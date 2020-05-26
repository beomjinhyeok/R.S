#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define CHOICE 4



int getKeyBoard();
void gotoTest();
void printGoto(const int& x, const int& y);
void gotoxy(int x, int y);
void init();
void drawTitle();
void selectMenu();
void makeBoard();
void setColor(int forground, int background);



