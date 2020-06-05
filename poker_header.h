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
	player();
	void payMoney(int pay,int &totalBet); 
	void showMoney();
	void getCard(card newCard1, card newCard2);
	bool checkPlayer(); //살아있는 플레이어 체크
	friend void openCard(player open);
	void takeCard();
	int getMoney();
	int inputBet(int& totalBet); // 리더의 배팅 금액 입력.
	void playerDie(int& gambler); // play가 false로 바뀜.
	int leaderBet(int &totalMoney, int& gamlber);
	void doubleBet(int& betMoney,int & totalBet);
	void allMoney(int& betMoney,int & totalBet);
	bool canBet(int betMoney);
	void halfBet(int &betMoney,int & totalBet);
	void dieAllMoney(int& totalMoney);
	bool nowPlay();
private:
	int used; // 받은 카드 갯수
	int gameMoney;
	card myCard[5]; // 딜러 때문에 크기 5로 변경
	bool play ; //이번 판 플레이가 제한된 경우 false로 변경
	bool die; //이번판 아웃된 경우
};

player::player() : used(0),gameMoney(0),play(true), die(false)
{}

ostream& operator<< (ostream& a, const card& thiscard ) // 삭제 고려
{
	a << thiscard.pat << thiscard.cardNumber;

	return a;
}

card Deck[52];
int survivor=5; //게임 전체 생존자



//-------------------------- 헤드 업데이트
card drawCard(); // (임시)카드 뽑기
void obliBet(player member[], int& totalBet);
void openCard(player open);
void playGame(player member[],player &gambler);
int checkCard() {
	return 0;
};
void choiceBet(player member[], int &gambler, int leader,int& totalBet);
int choiceLeader(player member[], const int gambler); // 가장 금액 높은 사람이 첫 배팅 리더
void choiceFollower(player& follwer, int &betMoney, int& totalBet, int& gambler,int &bet);
void cant_Bet(player& follwer, int& betMoney, int& gambler,int& totalBet);