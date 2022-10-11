#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
//srand(time_t(NULL));

struct Map
{
	int horizontal[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int vertical[10] = { 1,2,3,4,5,6,7,8,9,10 };
	char*** coordin = new char** [10];

};

int FillX();
int FillY();
void Memory(char*** array);
void DeleteMemory(char*** array);
void MapForGame(char*** array, int* arrayH, int* arrayV, int size);
void FillMapNull(char*** array);
void ShowMAP(char*** array);
int HorizontalSides(char*** array, int x, int y);
int VerticalSides(char*** array, int x, int y);
int ConditionsOnMapHorisontalShip(char*** array, int x, int y, int size);
int ConditionsOnMapVerticalShip(char*** array, int x, int y, int size);
void HorORVert(char*** array, int size);
void AutoHorORVert(char*** array, int size);
void CoordinateSelection(char*** array, int* arrayH, int* arrayV, int numberOfShips, int numberOfDeck);
void AutoCoordinateSelection(char*** array, int* arrayH, int* arrayV, int numberOfShips, int numberOfDeck);
int AutoFillX();
int AutoFillY();
void AutoHorORVert(char*** array, int size);

void MapAndShip(char*** array, int* arrayH, int* arrayV);


void AutoCoordinateSelection(char*** array, int* arrayH, int* arrayV, int numberOfShips, int numberOfDeck);

void CoordinateSelection(char*** array, int* arrayH, int* arrayV, int numberOfShips, int numberOfDeck);
void  MashineAutoCoordinateSelection(char*** array, int* arrayH, int* arrayV);

int FirstShotMachine(char*** array, int x_machine, int y_machine, int t);
int  FunctionFireSpotter(int n);
int SecondShotMachineR(char*** array, int x_machine, int y_machine, int t, int p);
void FullShotMachine(char*** array);

void UserShot(char*** arrayNull, char*** arrayMachine, int* arrayH, int* arrayV, char* b);
int MachineCount(char*** arrayNull, int* arrayH, int* arrayV);
void MapForGameMachine(char*** arrayNull, int* arrayH, int* arrayV);
void MapForGameUser(char*** arrayNull, int* arrayH, int* arrayV);
void game(char*** arrayNull, char*** arrayMachine, char*** arrayUser, int* arrayH, int* arrayV);

