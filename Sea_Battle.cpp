#include <iostream>
#include <string.h>
#include "Header.h"
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>

using namespace std;
int FireSpotter = 0;
int SecondSpotter = 0;
int ThirdSpotter = 0;
int FourthSpotter = 0;
int numberFunctionFireSpotter = 0;
int p;
int gameCountMachine = 0;
int gameCountUser = 0;
int counter = 0;





int main()
{

	srand((unsigned int)time(NULL));
	cout << "   Welcome to the game \"SEA BATTLE!\"" << endl;
	cout << "==========================================" << endl;

	cout << "Enter the bow coordinates (x, y) for 10 ships!" << endl;
	cout << "    - horizontal-nose on the left;" << endl;
	cout << "    - vertical-nose from above;" << endl << endl;
	Map UserMap;
	Map MachineMap;
	Map nullmap;
	Memory(UserMap.coordin);
	Memory(MachineMap.coordin);
	Memory(nullmap.coordin);
	FillMapNull(MachineMap.coordin);
	FillMapNull(UserMap.coordin);
	FillMapNull(nullmap.coordin);
	MashineAutoCoordinateSelection(MachineMap.coordin, MachineMap.horizontal, MachineMap.vertical);
	int gameCount = 0;

	MapAndShip(UserMap.coordin, UserMap.horizontal, UserMap.vertical);
	game(nullmap.coordin, MachineMap.coordin, UserMap.coordin, MachineMap.horizontal, MachineMap.horizontal);
	DeleteMemory(UserMap.coordin);
	DeleteMemory(MachineMap.coordin);
	DeleteMemory(nullmap.coordin);

	return 0;
}


int FillX()
{
	int x;
	cout << "Enter \"x\" - ";
	cin >> x;

	if (x > 10 || !(int)x)
	{

		FillX();
		return x;
	}
	return x;

}
int FillY()
{
	int y;
	cout << "Enter \"y\" - ";
	cin >> y;
	if (y > 10)
		FillX();
	return y;

}

void Memory(char*** array)
{
	for (int i = 0; i < 10; i++)
	{
		array[i] = new char* [10];
		for (int j = 0; j < 10; j++)
		{
			array[i][j] = new char[6];
		}
	}
}

void DeleteMemory(char*** array)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			delete[]array[i][j];
		}
		delete[]array[i];
	}

}

void MapForGame(char*** array, int* arrayH, int* arrayV, int size)
{
	cout << "   ";
	for (int i = 0; i < size; i++)
	{
		cout << arrayH[i] << "   ";
		if (i == 9)
			cout << endl;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0 && i == 9)
				cout << arrayV[i] << " ";
			else
				if (j == 0)
					cout << arrayV[i] << "  ";
			cout << array[i][j];
			if (j == 9 && i == 9)
				cout << endl;// continue;//cout << endl ;
			else
				if (j == 9)
					cout << endl << endl;


		}
	}
}

void FillMapNull(char*** array)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			strcpy_s(array[i][j], 6, ".   ");
		}
	}
}

void ShowMAP(char*** array)
{
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cout << array[i][j];
				if (j == 9)
					cout << endl;
			}
		}
	}
}



int HorizontalSides(char*** array, int x, int y)
{
	if (y < 10)
	{
		if (strchr(array[x - 1][y - 1 + 1], '#') != 0)
		{
			//system("cls");
			//cout << "You have placed a ship closer than one space. Repeat correctly." << endl;
			//cout << endl;
			return 1;
		}
	}
	if (x == 10)
	{
		if ((strchr(array[x - 1][y - 1], '#') != 0) || (strchr(array[x - 2][y - 1], '#') != 0))
		{
			//system("cls");
			//cout << "You have placed a ship closer than one space. Repeat correctly." << endl;
			//cout << endl;
			return 1;
		}
	}
	else
	{
		if (x == 1)
		{
			if ((strchr(array[x - 1 + 1][y - 1], '#') != 0) || (strchr(array[x - 1][y - 1], '#') != 0))
			{
				//system("cls");
				//cout << "You have placed a ship closer than one space. Repeat correctly." << endl;
				//cout << endl;
				return 1;
			}
		}
		else
		{
			if ((strchr(array[x - 1 + 1][y - 1], '#') != 0) || (strchr(array[x - 2][y - 1], '#') != 0) || (strchr(array[x - 1][y - 1], '#') != 0))
			{
				//system("cls");
				//cout << "You have placed a ship closer than one space. Repeat correctly." << endl;
				//cout << endl;
				return 1;
			}
		}
	}


	return 0;
}

int VerticalSides(char*** array, int x, int y)
{
	if (x < 10)
	{
		if (strchr(array[x - 1 + 1][y - 1], '#') != 0)
		{
			//system("cls");
			//cout << "You have placed a ship closer than one space. Repeat correctly." << endl;
			//cout << endl;
			return 1;
		}
	}
	if (y == 10)
	{
		if ((strchr(array[x - 1][y - 1], '#') != 0) || (strchr(array[x - 1][y - 2], '#') != 0))
		{
			//system("cls");
			//cout << "You have placed a ship closer than one space. Repeat correctly." << endl;
			//cout << endl;
			return 1;
		}
	}
	else
	{
		if (y == 1)
		{
			if ((strchr(array[x - 1][y - 1 + 1], '#') != 0) || (strchr(array[x - 1][y - 1], '#') != 0))
			{
				//system("cls");
				//cout << "You have placed a ship closer than one space. Repeat correctly." << endl;
				//cout << endl;
				return 1;
			}
		}
		else
		{
			if ((strchr(array[x - 1][y - 1 + 1], '#') != 0) || (strchr(array[x - 1][y - 2], '#') != 0) || (strchr(array[x - 1][y - 1], '#') != 0))
			{
				//system("cls");
				//cout << "You have placed a ship closer than one space. Repeat correctly." << endl;
				//cout << endl;
				return 1;
			}
		}
	}
	return 0;
}

int ConditionsOnMapHorisontalShip(char*** array, int x, int y, int size)// последн€€ рабоча€ верси€
{

	int tem = 0;
	if (y != 1)
	{
		if (HorizontalSides(array, x, y - 1) == 1)
			tem++;
	}
	for (int i = 0; i < size; i++)
	{
		int k = HorizontalSides(array, x, y + i);
		if (k == 1)
		{
			tem++;
			break;
		}
	}
	return tem;
}
int ConditionsOnMapVerticalShip(char*** array, int x, int y, int size)
{

	int tem = 0;
	if (x != 1)
	{
		if (VerticalSides(array, x - 1, y) == 1)
			tem++;
	}
	for (int i = 0; i < size; i++)
	{
		int k = VerticalSides(array, x + i, y);
		if (k == 1)
		{
			tem++;
			break;
		}
	}
	return tem;
}

void HorORVert(char*** array, int size)
{

	int	x = FillX();
	int y = FillY();
	int r;
	cout << "Enter \"1\" if you want horizontal layout" << endl;
	cout << "Enter \"2\" if you want vertical layout" << endl;
	cin >> r;
	switch (r)
	{
	case(1):
	{
		while ((y - 1 + size) > 10)
		{
			y--;
		}
		while ((x - 1) > 9)
		{
			x--;
		}
		if (ConditionsOnMapHorisontalShip(array, x, y, size) == 0)
		{
			for (int i = 0; i < size; i++)
			{
				strcpy_s(array[x - 1][(y - 1) + i], 6, "#   ");
			}
		}
		else
		{
			cout << "You have placed a ship closer than one space. Repeat correctly." << endl;
			HorORVert(array, size);
		}
		break;
	}
	case(2):
	{
		while ((x - 1 + size) > 9)
		{
			x--;
		}
		while ((y - 1) > 9)
		{
			y--;
		}
		if (ConditionsOnMapVerticalShip(array, x, y, size) == 0)
		{
			for (int i = 0; i < size; i++)
			{
				strcpy_s(array[(x - 1) + i][y - 1], 6, "#   ");
			}
		}
		else
		{
			cout << "You have placed a ship closer than one space. Repeat correctly." << endl;
			HorORVert(array, size);
		}
		break;
	}
	}

}

int AutoFillX()
{
	int x;
	do {
		x = rand() % 10;
	} while (x == 0);


	return x;

}

//int AutoFillX()
//{
//	int x;
//	x = rand() % 10;
//	if (x == 0)
//		AutoFillX();
//	else
//		return x;
//
//}
int AutoFillY()
{
	int y;
	do {
		y = rand() % 10;
	} while (y == 0);

	return y;

}
//int AutoFillY()
//{
//	int y;
//	y = rand() % 10;
//	if (y == 0)
//		AutoFillY();
//	else
//		return y;
//
//}
void AutoHorORVert(char*** array, int size)
{

	int	x = AutoFillX();
	int y = AutoFillY();
	int r;
	//cout << "\nEnter \"1\" if you want horizontal layout" << endl;
	//cout << "Enter \"2\" if you want vertical layout" << endl;
	int t = rand() % 2;
	if (t == 0)
		r = 2;
	else
		r = t;
	switch (r)
	{
	case(1):
	{
		while ((y - 1 + size) > 10)
		{
			y--;
		}
		while ((x - 1) > 9)
		{
			x--;
		}
		if (ConditionsOnMapHorisontalShip(array, x, y, size) == 0)
		{
			for (int i = 0; i < size; i++)
			{
				strcpy_s(array[x - 1][(y - 1) + i], 6, "#   ");
			}
		}
		else
			AutoHorORVert(array, size);
		break;
	}
	case(2):
	{
		while ((x - 1 + size) > 9)
		{
			x--;
		}
		while ((y - 1) > 9)
		{
			y--;
		}
		if (ConditionsOnMapVerticalShip(array, x, y, size) == 0)
		{
			for (int i = 0; i < size; i++)
			{
				strcpy_s(array[(x - 1) + i][y - 1], 6, "#   ");
			}
		}
		else
			AutoHorORVert(array, size);
		break;
	}
	}

}
void MapAndShip(char*** array, int* arrayH, int* arrayV)
{
	MapForGame(array, arrayH, arrayV, 10);
	cout << "\nEnter \"1\" if you want to place ships yourself" << endl;
	cout << "Enter \"2\" if you want the computer to place the ships" << endl;
	int v;
	cout << "Enter the number and start to place: - ";
	cin >> v;
	system("cls");
	cout << "            \"SEA BATTLE!\"" << endl;
	cout << "             (user map)" << endl;
	cout << "_________________________________________" << endl;
	MapForGame(array, arrayH, arrayV, 10);
	switch (v)
	{
	case(1):
	{
		CoordinateSelection(array, arrayH, arrayV, 1, 4);
		CoordinateSelection(array, arrayH, arrayV, 2, 3);
		CoordinateSelection(array, arrayH, arrayV, 3, 2);
		CoordinateSelection(array, arrayH, arrayV, 3, 1);
		break;
	}
	case(2):
	{
		MashineAutoCoordinateSelection(array, arrayH, arrayV);
		system("cls");
		cout << "            \"SEA BATTLE!\"" << endl;
		cout << "             (user map)" << endl;
		cout << "_________________________________________" << endl;

		MapForGame(array, arrayH, arrayV, 10);
		break;
	}
	default:
	{
		cout << "Be careful!!!" << endl;
		MapAndShip(array, arrayH, arrayV);
	}
	}
}

void AutoCoordinateSelection(char*** array, int* arrayH, int* arrayV, int numberOfShips, int numberOfDeck)
{

	for (int i = 0; i < numberOfShips; i++)
	{
		//cout << "Coordinates of a " << numberOfDeck << " - deck ship : " << endl;
		//cout << "It is necessary to determine the coordinates for " << numberOfShips - i << " ships" << endl;
		AutoHorORVert(array, numberOfDeck);
		//system("cls");
		/*cout << "            \"SEA BATTLE!\"" << endl;
		cout << "_________________________________________" << endl;
		MapForGame(array, arrayH, arrayV, 10);*/

	}
}


void CoordinateSelection(char*** array, int* arrayH, int* arrayV, int numberOfShips, int numberOfDeck)
{

	for (int i = 0; i < numberOfShips; i++)
	{
		cout << "\nCoordinates of a " << numberOfDeck << " - deck ship : " << endl;
		cout << "It is necessary to determine the coordinates for " << numberOfShips - i << " ships" << endl;
		HorORVert(array, numberOfDeck);
		system("cls");
		cout << "            \"SEA BATTLE!\"" << endl;
		cout << "             (user map)" << endl;
		cout << "_________________________________________" << endl;
		MapForGame(array, arrayH, arrayV, 10);

	}
}

void  MashineAutoCoordinateSelection(char*** array, int* arrayH, int* arrayV)
{
	AutoCoordinateSelection(array, arrayH, arrayV, 1, 4);
	AutoCoordinateSelection(array, arrayH, arrayV, 2, 3);
	AutoCoordinateSelection(array, arrayH, arrayV, 3, 2);
	AutoCoordinateSelection(array, arrayH, arrayV, 3, 1);
}






int  FunctionFireSpotter(int n)
{


	if (FireSpotter > 0)
	{
		switch (numberFunctionFireSpotter)
		{
		case(0):
		{
			if (n == 4)
			{
				SecondSpotter = 3;
				numberFunctionFireSpotter++;
			}
			else
			{
				if (n == 3)
				{
					SecondSpotter = 2;
					numberFunctionFireSpotter++;
				}
				else
				{
					if (n == 2)
					{
						SecondSpotter = 1;
						numberFunctionFireSpotter++;
					}
					else
					{
						SecondSpotter = 3;
						numberFunctionFireSpotter++;
					}
				}
			}
			return SecondSpotter;
			break;
		}
		case(1):
		{
			if (SecondSpotter == 4)
			{
				ThirdSpotter = 3;
				numberFunctionFireSpotter++;
			}
			else
			{
				if (SecondSpotter == 3)
				{
					ThirdSpotter = 2;
					numberFunctionFireSpotter++;
				}
				else
				{
					if (SecondSpotter == 2)
					{
						ThirdSpotter = 1;
						numberFunctionFireSpotter++;
					}
					else
					{
						ThirdSpotter = 3;
						numberFunctionFireSpotter++;
					}
				}
			}
			return ThirdSpotter;
			break;
		}
		case(2):
		{
			if (ThirdSpotter == 4)
			{
				FourthSpotter = 3;
				numberFunctionFireSpotter++;
			}
			else
			{
				if (ThirdSpotter == 3)
				{
					FourthSpotter = 2;
					numberFunctionFireSpotter++;
				}
				else
				{
					if (ThirdSpotter == 2)
					{
						FourthSpotter = 1;
						numberFunctionFireSpotter++;
					}
					else
					{
						FourthSpotter = 3;
						numberFunctionFireSpotter++;
					}
				}
			}
			return FourthSpotter;
			break;
		}
		}
	}
	else
	{
		n = 0;
		return n;
	}

}

int FirstShotMachine(char*** array, int x_machine, int y_machine, int t)
{
	if (strchr(array[x_machine - 1][y_machine - 1], '#') != 0 || strchr(array[x_machine - 1][y_machine - 1], 'X') != 0)
	{
		strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "X   ");
		counter++;

		if (++t == 4)
		{
			t = 0;
			FullShotMachine(array);
		}
		else
		{
			p = rand() % 4 + 1;
			switch (p)
			{
			case(1):
			{
				x_machine++;
				if (x_machine == 11)
				{
					FullShotMachine(array);
					break;
				}
				while (strchr(array[x_machine - 1][y_machine - 1], '#') != 0 || strchr(array[x_machine - 1][y_machine - 1], 'X') != 0)
				{
					strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "X   ");
					counter++;
					x_machine++;
					if (x_machine == 11)
					{
						FullShotMachine(array);
						break;
					}
					if (++t == 4)
					{
						t = 0;
						FullShotMachine(array);
						break;
					}
				}
				if (++t == 4)
					t = 0;
				strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "O   ");
				break;
			}
			case(2):
			{
				x_machine--;
				if (x_machine == 0)
				{
					FullShotMachine(array);
					break;
				}
				while (strchr(array[x_machine - 1][y_machine - 1], '#') != 0 || strchr(array[x_machine - 1][y_machine - 1], 'X') != 0)
				{
					strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "X   ");
					counter++;
					x_machine--;
					if (x_machine == 0)
					{
						FullShotMachine(array);
						break;
					}
					if (++t == 4)
					{
						t = 0;
						FullShotMachine(array);
						break;
					}
				}
				if (++t == 4)
					t = 0;
				strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "O   ");
				break;
			}
			case(3):
			{
				y_machine--;
				if (y_machine == 0)
				{
					FullShotMachine(array);
					break;
				}
				while (strchr(array[x_machine - 1][y_machine - 1], '#') != 0 || strchr(array[x_machine - 1][y_machine - 1], 'X') != 0)
				{
					strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "X   ");
					counter++;
					x_machine--;
					if (y_machine == 0)
					{
						FullShotMachine(array);
						break;
					}
					if (++t == 4)
					{
						t = 0;
						FullShotMachine(array);
						break;
					}
				}
				if (++t == 4)
					t = 0;
				strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "O   ");
				break;
			}
			case(4):
			{
				y_machine++;
				if (y_machine == 11)
				{
					FullShotMachine(array);
					break;
				}
				while (strchr(array[x_machine - 1][y_machine - 1], '#') != 0 || strchr(array[x_machine - 1][y_machine - 1], 'X') != 0)
				{
					strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "X   ");
					counter++;
					x_machine++;
					if (y_machine == 11)
					{
						FullShotMachine(array);
						break;
					}
					if (++t == 4)
					{
						t = 0;
						FullShotMachine(array);
						break;
					}
				}
				if (++t == 4)
					t = 0;
				strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "O   ");
				break;
			}
			}
		}
	}
	else
	{
		strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "O   ");
	}
	return t;
}

void FullShotMachine(char*** array)
{
	static int n;
	static int x_machine;
	static int y_machine;

	n = FunctionFireSpotter(p);

	if (n == 0)
	{
		x_machine = AutoFillX();
		y_machine = AutoFillY();
		int x = x_machine;
		int y = y_machine;
		FireSpotter = FirstShotMachine(array, x, y, FireSpotter);
		//break;
	}
	else
	{
		int x = x_machine;
		int y = y_machine;
		FireSpotter = SecondShotMachineR(array, x, y, FireSpotter, n);
	}


}

int SecondShotMachineR(char*** array, int x_machine, int y_machine, int t, int p)
{
	switch (p)
	{
	case(1):
	{
		x_machine++;
		if (x_machine == 11)
		{
			FullShotMachine(array);
			break;
		}
		while (strchr(array[x_machine - 1][y_machine - 1], '#') != 0 || strchr(array[x_machine - 1][y_machine - 1], 'X') != 0)
		{
			strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "X   ");
			counter++;
			x_machine++;
			if (x_machine == 11)
			{
				FullShotMachine(array);
				break;
			}
			if (++t == 5)
			{
				t = 0;
				FullShotMachine(array);
				break;
			}
		}
		if (++t == 5)
			t = 0;
		strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "O   ");
		break;
	}
	case(2):
	{
		x_machine--;
		if (x_machine == 0)
		{
			FullShotMachine(array);
			break;
		}
		while (strchr(array[x_machine - 1][y_machine - 1], '#') != 0 || strchr(array[x_machine - 1][y_machine - 1], 'X') != 0)
		{
			strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "X   ");
			counter++;
			x_machine--;
			if (x_machine == 0)
			{
				FullShotMachine(array);
				break;
			}
			if (++t == 3)
			{
				t = 0;
				FullShotMachine(array);
				break;
			}
		}
		if (++t == 5)
			t = 0;
		strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "O   ");
		break;
	}
	case(3):
	{
		y_machine--;
		if (y_machine == 0)
		{
			FullShotMachine(array);
			break;
		}
		while (strchr(array[x_machine - 1][y_machine - 1], '#') != 0 || strchr(array[x_machine - 1][y_machine - 1], 'X') != 0)
		{
			strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "X   ");
			counter++;
			y_machine--;
			if (y_machine == 0)
			{
				FullShotMachine(array);
				break;
			}
			if (++t == 5)
			{
				t = 0;
				FullShotMachine(array);
				break;
			}
		}
		if (++t == 5)
			t = 0;
		strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "O   ");
		break;
	}
	case(4):
	{
		y_machine++;
		if (y_machine == 11)
		{
			FullShotMachine(array);
			break;
		}
		while (strchr(array[x_machine - 1][y_machine - 1], '#') != 0 || strchr(array[x_machine - 1][y_machine - 1], 'X') != 0)
		{
			strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "X   ");
			counter++;
			y_machine++;
			if (y_machine == 11)
			{
				FullShotMachine(array);
				break;
			}
			if (++t == 5)
			{
				t = 0;
				FullShotMachine(array);
				break;
			}
		}
		if (++t == 5)
			t = 0;
		strcpy_s(array[x_machine - 1][(y_machine - 1)], 6, "O   ");
		break;
	}


	}

	return t;
}

void UserShot(char*** arrayNull, char*** arrayMachine, int* arrayH, int* arrayV, char* b)
{
	cout << "         Please your shot!       " << endl;
	int x = FillX();
	int y = FillY();
	if (strchr(arrayMachine[x - 1][y - 1], '#') != 0 || strchr(arrayMachine[x - 1][y - 1], 'X') != 0)
	{
		strcpy_s(arrayNull[x - 1][(y - 1)], 6, "X   ");
		system("cls");
		if (MachineCount(arrayNull, arrayH, arrayV) < 19)
		{
			MapForGameMachine(arrayNull, arrayH, arrayV);
			//MapForGame(arrayMachine, arrayH, arrayV, 10);
			cout << " Congratulations, you've hit the ship! ! ! " << endl;
			cout << " Shoot more!" << endl;
			//if (gameCountUser != 19);
			UserShot(arrayNull, arrayMachine, arrayH, arrayV, b);
		}
	}
	else
	{
		strcpy_s(arrayNull[x - 1][(y - 1)], 6, "O   ");
		system("cls");
		MapForGameMachine(arrayNull, arrayH, arrayV);
		cout << "           You missed the target!" << endl << endl;
		cout << "Press any key and then press the \"ENTER\" key!" << endl;
		cin >> b;
		system("cls");

	}
}
int MachineCount(char*** arrayNull, int* arrayH, int* arrayV)
{
	int t = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (strchr(arrayNull[i][j], 'X') != 0)
			{
				t++;
			}
		}
	}
	return t;
}

void MapForGameMachine(char*** arrayNull, int* arrayH, int* arrayV)
{
	cout << "             \"SEA BATTLE!\"" << endl;
	cout << "             (machine map)" << endl;
	cout << "_________________________________________" << endl;
	MapForGame(arrayNull, arrayH, arrayV, 10);
}
void MapForGameUser(char*** arrayNull, int* arrayH, int* arrayV)
{
	cout << "             \"SEA BATTLE!\"" << endl;
	cout << "              (user map)" << endl;
	cout << "_________________________________________" << endl;
	MapForGame(arrayNull, arrayH, arrayV, 10);
}


void game(char*** arrayNull, char*** arrayMachine, char*** arrayUser, int* arrayH, int* arrayV)
{

	char* temp = new char[5];
	cout << "-user success: " << gameCountUser << endl;
	cout << "-machine success: " << gameCountMachine << endl;
	cout << "Press any key and then press the \"ENTER\" key!" << endl;
	cin >> temp;
	system("cls");
	MapForGameMachine(arrayNull, arrayH, arrayV);
	UserShot(arrayNull, arrayMachine, arrayH, arrayH, temp);
	gameCountUser = MachineCount(arrayNull, arrayH, arrayV);
	if (gameCountUser < 19)
	{
		FullShotMachine(arrayUser);
		gameCountMachine = MachineCount(arrayUser, arrayH, arrayV);
		if (gameCountMachine < 19)
		{
			MapForGameUser(arrayUser, arrayH, arrayV);
			cout << "      The machine fired ! ! !  " << endl << endl;
			game(arrayNull, arrayMachine, arrayUser, arrayH, arrayV);
		}
		else
		{
			cout << endl << endl << endl << endl << endl << endl;
			cout << "                                          Game over!" << endl;
			cout << "                                        Machine winner" << endl;
			cout << endl << endl << endl << endl << endl << endl;
		}

	}
	else
	{
		cout << endl << endl << endl << endl << endl << endl;
		cout << "                                          Game over!" << endl;
		cout << "                                         User winner" << endl;
		cout << endl << endl << endl << endl << endl << endl;
	}
	delete[]temp;
}