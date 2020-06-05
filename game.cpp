#include "poker_header.h"


card drawCard()
{
	card temp;
	temp = drawCard();

	return drawCard();
}


void choiceBet(player member[], int& gambler, int leader, int &totalBet)
{
	int nowBet = leader-1, betMoney=0;

	int cantChoice;

	for (int i = 0; i < gambler; i++)
	{	
		nowBet = gambler % (nowBet + 1);
		
		while (member[nowBet].nowPlay() == false) //다음 플레이어가 이번판 다이를 쳤을 경우.
		{
			nowBet = gambler % (nowBet + 1);
		}

		if (i == 0) //첫 턴 leader만 배팅 다름.
		{
			betMoney = member[nowBet].leaderBet(totalBet,gambler);
			while (betMoney == 0) //만약 리더가 다이한 경우
			{
				if (gambler==1) // 한 명빼고 gambler가 없을 경우
				{
					break;
				}
				nowBet = gambler % (nowBet + 1);
				betMoney = member[nowBet].leaderBet(totalBet,gambler);
			}
		}
		else
		{
			if (member[nowBet].canBet == true) // 돈 낼 능력이 있는가 판단
				choiceFollower(member[nowBet], betMoney, totalBet, gambler, i);
			else
				cant_Bet(member[nowBet], betMoney, gambler,totalBet);
		}
	}
}

void choiceFollower(player& follower,int& betMoney,int& totalBet,int& gambler, int &bet)
{
	int choice;
	cin >> choice; // 인터페이스에서는 선택

	switch (choice)
	{
	case 1: //콜
		follower.payMoney(betMoney,totalBet);
		break;
	case 2: //다이
		follower.playerDie(gambler);
		break;
	case 3: // 더블, 배팅 금액 없는 경우 생각
		bet = 0; // 더블 다음 사람부터 다시 팔로워처럼 배팅 선택
		follower.doubleBet(betMoney,totalBet);
		break;
	case 4: // 하프
		if (betMoney > totalBet / 2)
		{
			cout << "하프가 배팅 금액보다 적습니다.\n";
			choiceFollower(follower, betMoney, totalBet, gambler, bet);
		}
		else if (follower.getMoney < totalBet/2)
		{
			cout << "현재 가진 돈이 판돈의 절반이 되지 않습니다.\n";
			choiceFollower(follower, betMoney, totalBet, gambler, bet);
		}
		else
		{
			follower.halfBet(betMoney, totalBet);
			bet = 0;
		}
		break;
	case 5: //All in
		bet = 0; // 올인 다음 사람부터 다시 팔로워처럼 배팅 선택
		follower.allMoney(betMoney,totalBet);
	}
}

void cant_Bet(player& follwer, int& betMoney,int &gambler,int & totalBet)
{
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1: // 올인 
		follwer.dieAllMoney(totalBet);
		break;
	case 2: // 다이
		follwer.playerDie(gambler);
	}
}


card drawCard()
{
	int top = 52; // 임시 변수. 전역으로 할 지, 주소를 넘길지 고민.
	return Deck[top--];
}

void obliBet(player member[],int &totalBet) // 의무 배팅
{
	int obli = 3;

	for (int i = 0; i < survivor; i++)
	{
		member[i].payMoney(obli, totalBet);
		member[i].showMoney();
		
	}
	cout << totalBet << endl;
}

void openCard(player open) // 인터페이스 요소 생각중
{
	cout << open.myCard[0]; 
	cout << open.myCard[1];
}


int choiceLeader(player member[],const int gambler) // 손봐야함
{
	int temp = member[0].getMoney(), leader=0;

	for (int i = 1; i < gambler; i++)
	{
		if (member[i].getMoney() > temp)
		{
			temp = member[i].getMoney();
			leader = i;
		}
	}
	return leader;
}



void playGame(player member[],player& dealer) // 게임 진행
{
	int totalBet = 0, leader;
	int gambler=survivor;
	obliBet(member,totalBet);
	//givePlayer(member);
	for (int i = 0; i < gambler; i++) // 2장씩 배팅
	{
		member[i].takeCard;
		member[i].takeCard;
	}

	for(int i =0; i<3; i++)
		dealer.takeCard;
	
	leader = choiceLeader(member, gambler); // 리더는 한 번만 정하면 다음부터는 오른쪽 사람이 리더

	for (int i = 0; i < 2; i++)
	{
		
	}


}

//진행 상황 - 의무 배팅 구현, 카드 2장 주기 구현, 딜러 카드 3장 구현, 리더 선택 구현, 리더 배팅 구현, 팔로워 배팅 구현(예외사항 적용중)

