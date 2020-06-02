#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define CHOICE 4

enum {Half, Quater, Double, Call, All_in, Die} betting;

class card { //(임시) 카드 클래스
public:
	friend ostream& operator<< (ostream& a, const card& thiscard);
private:
	bool status=false; // 뒷면 false 앞면 true
	string pat;
	int cardNumber;
	int num;

};

class player {
public:
	void payMoney(int pay,int &totalBet); 
	void showMoney();
	void getCard(card newCard1, card newCard2);
	bool checkPlayer(); //살아있는 플레이어 체크
	friend void openCard(player open);
	int getMyNumber();
	void takeCard();
	int getMoney();
	int inputBet(int& totalBet); // 리더의 배팅 금액 입력.
	void playerDie(); // play가 false로 바뀜.
private:
	int used = 0; // 받은 카드 갯수
	int gameMoney=0;
	card myCard[5]; // 딜러 때문에 크기 5로 변경
	int myNumber;
	bool play = true; //이번 판 다이를 친 경우 false로 변경
};

ostream& operator<< (ostream& a, const card& thiscard ) // 삭제 고려
{
	a << thiscard.pat << thiscard.cardNumber;

	return a;
}

card Deck[52];
int survivor=5; //게임 전체 생존자

int getKeyBoard();
void gotoTest();
void printGoto(const int& x, const int& y);
void gotoxy(int x, int y);
void init();
void drawTitle();
void selectMenu();
void setColor(int forground, int background);


//-------------------------- 헤드 업데이트
//card givePlayer(player member[]);
card drawCard(); // (임시)카드 뽑기
void giveCard(int survive, int leader);
void obliBet(player member[], int& totalBet);
void openCard(player open);
void playGame(player member[],player &gambler);
int checkCard() {
	return 0;
};
void choiceBet(player member[], const int gambler, int leader,int& totalBet);
int choiceLeader(player member[], const int gambler); // 가장 금액 높은 사람이 첫 배팅 리더
void choiceBet(player& follwer, int &betMoney, int& totalBet);