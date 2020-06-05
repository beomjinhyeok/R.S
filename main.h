#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

enum Color  //콘솔에서 사용하는 색상
{
    BLACK, BLUE, GREEN, CYAN,
    RED, MAGENTA, BROWN, LIGHTGRAY,
    DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN,
    LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

using namespace std;

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define CHOICE 4

void setColor(int back, int text);
void init();
void gotoxy(int x, int y);
void introGame();      // 게임 시작화면을 불러오는 함수
int keyControl();
int menuChoice();
void gameImage();
void gameRule();
void player(int x, int y);
void bettingNumber();
int bettingMenuChoice();

