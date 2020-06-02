#include "poker_header.h"


void player::showMoney() // 남은 플레이어 돈 확인
{
	cout << gameMoney << endl;
}

void player::payMoney(int pay, int& totalBet) //첫 의무돈 지불
{
	if (pay >= gameMoney)
	{
		gameMoney = 0;
		totalBet = totalBet + gameMoney;
		// 이제부터 스킵하는 함수.
	}

	else
	{
		gameMoney = gameMoney - pay;
		totalBet = totalBet + pay;
	}
}

void player::playerDie() // 플레이어 컴퓨터 구분;
{
	play = false;
}

void player::getCard(card newCard1, card newCard2)
{
	myCard[0] = newCard1;
	myCard[1] = newCard2;
}

bool player::checkPlayer()
{
	if (play == true)
		return true;
	else
		return false;
}

int player::getMyNumber()
{
	return myNumber;
}

void player::takeCard()
{
	myCard[used++] = drawCard();
}

int player::getMoney()
{
	return gameMoney;
}

int player::inputBet(int &totalBet) // 베팅 범위 정해야 함.
{
	int betMoney;
	do 
	{
		cin >> betMoney;
	} while (betMoney>gameMoney || betMoney < 0);

	totalBet = totalBet + betMoney;
	gameMoney = gameMoney - betMoney;

	return betMoney;
}
