#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>

const char shape[5][10] = { "zero", "spade", "diamonds", "cluber", "heart" };
const char number[14][7] = { "zero","two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace" };

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
#define CHOICE 13

void setColor(int back, int text);
void init();
void gotoxy(int x, int y);
void introGame(); // 게임 시작화면 함수
int keyControl(); // 방향키로 메뉴 선택 함수
int menuChoice(); // 시작화면 메뉴 선택 함수
void gameImage(); // 게임화면 이미지 출력 함수
void gameRule(); // 게임 룰 화면 함수
void player(int x, int y); // 컴퓨터 플레이어 이미지 출력 함수
void bettingNumber(); // 베팅 메뉴 선택 함수
void bettingPrint(int x); // 베팅 문자 출력 
int bettingMenuChoice(); // 베팅 메뉴 이름 출력 함수
void victoryPrint(); // 승리 시 화면 출력
void defeatPrint();  // 패배 시 화면 출력
void picture(int* num1_rand, int* shape_rand); //공유 카드 구성 함수
void playerCard(int x, int y, int number);
void printOrder(int);
void Print_result(int i, int result);
void printAll(int* num1_rand, int* shape_rand);
void PrintMCard(int x, int y, int* num1_rand, int* shape_rand);
void choice_betting();
void choice_betting2();
int betting_coin(int x);
int betting_coin2(int x);
void betting_all();