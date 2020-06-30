#include "main.h"

void setColor(int back, int text)
{
	HANDLE hcon;

	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, (back << 4) | text);
}

void init()
{
	system("mode con cols=176 lines=45 | title 텍사스 홀덤 ");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	system("color F5");
	//setColor(WHITE, GREEN); // 게임화면 만들때 사용..
}

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void introGame()
{
	setColor(WHITE, BLACK);
	gotoxy(45, 5); cout << "       □□□□□     □□□□□     □      □         □         □□□□□";
	gotoxy(45, 6); cout << "           □         □               □  □         □  □       □        ";
	gotoxy(45, 7); cout << "           □         □□□□□         □         □□□□□       □□□  ";
	gotoxy(45, 8); cout << "           □         □               □  □       □      □             □";
	gotoxy(45, 9); cout << "           □         □□□□□     □      □     □      □     □□□□□";
	gotoxy(45, 10); cout << "																			 ";
	gotoxy(45, 12); cout << " □      □     □□□□□     □             □□□□       □□□□□     □      □";
	gotoxy(45, 13); cout << " □      □     □      □     □             □     □      □             □□  □□";
	gotoxy(45, 14); cout << " □□□□□     □      □     □             □      □     □□□□□     □  □  □";
	gotoxy(45, 15); cout << " □      □     □      □     □             □     □      □             □      □";
	gotoxy(45, 16); cout << " □      □     □□□□□     □□□□□     □□□□       □□□□□     □      □";
	gotoxy(82, 25); cout << "[게임시작]";
	gotoxy(82, 26); cout << "[게임규칙]";
	gotoxy(82, 27); cout << "[게임종료]";
}

int keyControl()
{
	char c;
	while (1) {
		if (_kbhit())
		{
			c = _getch();
			if (c == -32)
			{
				c = _getch();

				if (c == UP)
					return UP;
				else if (c == DOWN)
					return DOWN;
				else if (c == RIGHT)
					return RIGHT;
				else if (c == LEFT)
					return LEFT;
			}
			else if (c == CHOICE)
				return CHOICE;
		}
	}
}

int menuChoice()
{
	int x = 82;
	int y = 25;
	gotoxy(x - 2, y); cout << "> [게임시작]";
	gotoxy(x, y + 1); cout << "[게임규칙]";
	gotoxy(x, y + 2); cout << "[게임종료]";
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 25) {
				gotoxy(x - 2, y); cout << " ";
				gotoxy(x - 2, --y); cout << ">";
			}
			break;
		}

		case DOWN:
		{
			if (y < 27)
			{
				gotoxy(x - 2, y); cout << " ";
				gotoxy(x - 2, ++y); cout << ">";
			}
			break;
		}

		case CHOICE:
		{
			return y - 25;
		}

		}
	}

}

void gameImage()
{	
	char Play_name[5][10] = { "참가자", "도영", "강민", "진혁", "정훈" };
	int x = 66;
	int y = 41;
	system("color 02");
	system("cls");
	setColor(GREEN, GREEN);
	for (int i = 1; i < 35; i++)
	{
		gotoxy(30, i);
		cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
	}
	setColor(WHITE, WHITE);
	for (int i = 0; i < 35; i++)
	{
		gotoxy(29, i); cout << "▒";
		gotoxy(145, i); cout << "▒";
	}
	gotoxy(29, 0);	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
	gotoxy(29, 35); cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
	

	player(10, 3);  cout << Play_name[1];
	player(150, 3); cout << Play_name[2];
	player(10, 18); cout << Play_name[3];
	player(150, 18);cout << Play_name[4];
	gotoxy(int(85.5), 37); cout << Play_name[0];

	gotoxy(x, y);  cout << "콜";
	gotoxy(x + 10, y); cout << "다이";
	gotoxy(x + 20, y); cout << "더블";
	gotoxy(x + 30, y); cout << "하프";
	gotoxy(x + 40, y); cout << "올인";

	/*while (1)
	{
		if (keyControl() == CHOICE)
		{
			system("color F5");
			break;
		}
	}*/
}

void gameRule()
{
	system("cls");
	gotoxy(15, 10); cout << "텍사스 홀덤 간단 요약"<< endl;
	gotoxy(15, 10); cout << "1. 플레이어들은 개인별 손패 2장의 카드를 받습니다." << endl;
	gotoxy(15, 11); cout << "2. 모든 플레이어들이 공유하는 커뮤니티 카드 5장이 주어집니다." << endl;
	gotoxy(15, 12); cout << "3. 커뮤니티 카드 5장과 개인별 손패 2장의 카드의 조합이 가장 높은 플레이어가 승리합니다." << endl;
	gotoxy(15, 13); cout << "카드 조합에 대한 자세한 설명은 아래 홈페이지를 참고하시기 바랍니다." << endl;
	gotoxy(15, 14); cout << "https://crash-landing.github.io" << endl;
	while (1)
	{
		if (keyControl() == CHOICE)
		{
			break;
		}
	}
}

void player(int x, int y)
{
	int coin = 50;
	setColor(BLACK, WHITE);
	gotoxy(x, y - 2); cout << "  남은 칩: " << coin << endl;
	gotoxy(x, y);     cout << "■■■■■■■■\n";
	gotoxy(x, y + 1); cout << "■□□■■□□■\n";
	gotoxy(x, y + 2); cout << "■□□■■□□■\n";
	gotoxy(x, y + 3); cout << "■■■□□■■■\n";
	gotoxy(x, y + 4); cout << "■■■■■■■■\n";
	gotoxy(x, y + 5); cout << "■□□□□□□■\n\n";
	gotoxy(x, y + 6); cout << "■■■■■■■■\n\n";
	gotoxy(x, y + 8); cout << "  참가자: ";
}					

int bettingMenuChoice()
{
	setColor(BLACK, WHITE);
	int x = 66;
	int y = 41;
	gotoxy(x - 2, y);  cout << "> 콜";
	gotoxy(x + 10, y); cout << "다이";
	gotoxy(x + 20, y); cout << "더블";
	gotoxy(x + 30, y); cout << "하프";
	gotoxy(x + 40, y); cout << "올인";
	while (1) {
		int n = keyControl();
		switch (n) {
			case RIGHT: 
			{
				if (x < 105) 
				{	
					gotoxy(x - 2, y); cout << " ";
					x = x + 10;
					gotoxy(x - 2, y); cout << ">";
				}
				break;
			}

			case LEFT:
			{
				if (x > 65)
				{
					gotoxy(x - 2, y); cout << " ";
					x = x - 10;
					gotoxy(x - 2, y); cout << ">";
				}
				break;
			}

			case CHOICE:
			{
				gotoxy(x - 2, y); cout << " ";
				return x - 50;
			}
		}
	}

}
void bettingPrint(int x) //베팅 문자 출력 
{
	int y = 12;
	switch (x / 10) {
		case 0:  // 빈 화면
			setColor(GREEN, GREEN);
			for (int i = y; i < y+5; i++)
			{
				gotoxy(45, i);
				cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
			}
			break;

		case 1: // 콜
			gotoxy(45, y);   cout << "                ■■■■■         ■         ■           ■           ■           ";
			gotoxy(45, y+1); cout << "                ■               ■  ■       ■           ■           ■           ";
			gotoxy(45, y+2); cout << "                ■             ■■■■■     ■           ■           ■           ";
			gotoxy(45, y+3); cout << "                ■             ■      ■     ■           ■                        ";
			gotoxy(45, y+4); cout << "                ■■■■■     ■      ■     ■■■■     ■■■■     ■           ";
			break;

		case 2: // 다이
			gotoxy(45, y);   cout << "                       ■■■■         ■■■       ■■■■     ■                   ";
			gotoxy(45, y+1); cout << "                       ■     ■          ■         ■           ■                   ";
			gotoxy(45, y+2); cout << "                       ■      ■         ■         ■■■■     ■                   ";
			gotoxy(45, y+3); cout << "                       ■     ■          ■         ■                                ";
			gotoxy(45, y+4); cout << "                       ■■■■         ■■■       ■■■■     ■                   ";
			break;

		case 3: // 더블
			gotoxy(45, y);   cout << " ■■■■        ■■■■      ■      ■     ■■■■       ■           ■■■■     ■   ";
			gotoxy(45, y+1); cout << " ■     ■      ■      ■     ■      ■     ■     ■      ■           ■           ■   ";
			gotoxy(45, y+2); cout << " ■      ■     ■      ■     ■      ■     ■■■■       ■           ■■■■     ■   ";
			gotoxy(45, y+3); cout << " ■     ■      ■      ■     ■      ■     ■     ■      ■           ■                ";
			gotoxy(45, y+4); cout << " ■■■■        ■■■■       ■■■■      ■■■■       ■■■■     ■■■■     ■   ";
			break;

		case 4: // 하프
			gotoxy(45, y);   cout << "                ■      ■         ■         ■           ■■■■     ■             ";
			gotoxy(45, y+1); cout << "                ■      ■       ■  ■       ■           ■           ■             ";
			gotoxy(45, y+2); cout << "                ■■■■■     ■■■■■     ■           ■■■■     ■             ";
			gotoxy(45, y+3); cout << "                ■      ■     ■      ■     ■           ■                          ";
			gotoxy(45, y+4); cout << "                ■      ■     ■      ■     ■■■■     ■           ■             ";
			break;

		case 5:  // 올인
			gotoxy(45, y);   cout << "         ■         ■           ■                ■■■       ■      ■     ■      ";
			gotoxy(45, y+1); cout << "       ■  ■       ■           ■                  ■         ■■    ■     ■      ";
			gotoxy(45, y+2); cout << "     ■■■■■     ■           ■                  ■         ■  ■  ■     ■      ";
			gotoxy(45, y+3); cout << "     ■      ■     ■           ■                  ■         ■    ■■             ";
			gotoxy(45, y+4); cout << "     ■      ■     ■■■■     ■■■■          ■■■       ■      ■     ■      ";
			break;
	}
}

void bettingNumber() 
{
	while (1) {
		int x = bettingMenuChoice(); // 베팅메뉴 선택 함수
		setColor(GREEN, WHITE);
		bettingPrint(x);
		Sleep(1000);
		bettingPrint(0);
	}
}

void victoryPrint()
{
	gotoxy(80, 17); cout << "------------------------";
	gotoxy(80, 18); cout << "|                       |";
	gotoxy(80, 19); cout << "|      승리!!!!!!!      |";
	gotoxy(80, 20); cout << "|                       |";
	gotoxy(80, 21); cout << "------------------------";
	introGame(); // 시작화면의 표시부분 함수
}

void defeatPrint()
{
	gotoxy(80, 17); cout << "------------------------";
	gotoxy(80, 18); cout << "|                       |";
	gotoxy(80, 19); cout << "|      패배!!!!!!!      |";
	gotoxy(80, 20); cout << "|                       |";
	gotoxy(80, 21); cout << "------------------------";
	introGame(); // 시작화면의 표시부분 함수
}

void picture(int* num1_rand, int* shape_rand)
{
	setColor(GREEN, WHITE);
	int shape[5] = { 0,1,2,3,4 }; //null, spade, diamond, heart, cluber
	int number[14] = { 0,2,3,4,5,6,7,8,9,10,11,12,13,1 }; //null, 2~10, jack, queen, king, ace
	int x = 100, y = 14;
	int i, j, k, v = 1, hide = 0;		//hide 0 숨김, 1 표시
	int get = 4;
	int num1 = 0, num2 = 0;
	for (k = 0; k < 2; k++)
	{
		if (k == 0) // 현재 뒷면인 상태
		{
			for (i = 0;i < 4;i++) // 카드가 나열되는 그래픽
			{
				num1 = 0;
				for (j = 0; j < 15; j++)
				{
					Sleep(10);
					gotoxy(x - num1, 14); cout << "┏━━━━━━┓";
					gotoxy(x - num1, 15); cout << "┃?     ┃";
					gotoxy(x - num1, 16); cout << "┃      ┃";
					gotoxy(x - num1, 17); cout << "┃   ?  ┃";
					gotoxy(x - num1, 18); cout << "┃      ┃";
					gotoxy(x - num1, 19); cout << "┃     ?┃";
					gotoxy(x - num1, 20); cout << "┗━━━━━━┛";
					num1 += 1;
				}
				x += 2;
			}
			num1 = 0;
			for (i = 0;i < 15;i++) // 카드가 배분되는 그래픽
			{
				num1 = 1;
				if (i % 2 == 1)
				{
					num1 *= -1;
				}
				for (j = 0;j < 7;j++)
				{
					Sleep(20);
					if (i % 2 == 0)
					{
						gotoxy(80 - num2, 21 - num1); cout << "          ";
					}
					gotoxy(80 - num2, 14 - num1); cout <<"┏━━━━━━┓";
					gotoxy(80 - num2, 15 - num1); cout <<"┃?     ┃";
					gotoxy(80 - num2, 16 - num1); cout <<"┃      ┃";
					gotoxy(80 - num2, 17 - num1); cout <<"┃   ?  ┃";
					gotoxy(80 - num2, 18 - num1); cout <<"┃      ┃";
					gotoxy(80 - num2, 19 - num1); cout <<"┃     ?┃";
					gotoxy(80 - num2, 20 - num1); cout <<"┗━━━━━━┛";
					if (i % 2 == 1)
					{
						gotoxy(80 - num2, 13 - num1); cout <<"          ";
					}
					if (i % 2 == 0)
						num1 += 1;
					else
						num1 -= 1;
				}
				num2 += 2;
			}
			system("cls");
			gameImage();
		}
		else // 앞면인 상태
		{
			setColor(GREEN, WHITE);
		
			playerCard(80, 25, 0);
			playerCard(35, 3, 1);
			playerCard(125, 3, 2);
			playerCard(35, 18, 3);
			playerCard(125, 18, 4);
		
			num1 = 0;
			j = 1;
			for (i = 0;i < 10;i++)
			{
				if (i % 2 == 0)
				{
					if (i > get)
					{
						get += 2;
						hide = 1;
						_getch();
					}
					gotoxy(60 + num1, 3); cout <<"┏━━━━━━┓";
					gotoxy(60 + num1, 4); cout <<"┃      ┃";
					gotoxy(60 + num1, 5); cout <<"┃      ┃";
					gotoxy(60 + num1, 6); cout <<"┃      ┃";
					gotoxy(60 + num1, 7); cout <<"┃      ┃";
					gotoxy(60 + num1, 8); cout <<"┃      ┃";
					gotoxy(60 + num1, 9); cout <<"┗━━━━━━┛";
					//					if(hide != 1){
					if (shape[shape_rand[j]] == 1) {
						setColor(GREEN, BLACK);
						gotoxy(62 + num1, 4);cout <<"♠";
						gotoxy(66 + num1, 8);cout <<"♠";
					}
					else if (shape[shape_rand[j]] == 2) {
						setColor(GREEN, RED);
						gotoxy(62 + num1, 4);cout <<"◆";
						gotoxy(66 + num1, 8);cout <<"◆";
					}
					else if (shape[shape_rand[j]] == 3) {
						setColor(GREEN, RED);
						gotoxy(62 + num1, 4);cout <<"♥";
						gotoxy(66 + num1, 8);cout <<"♥";
					}
					else if (shape[shape_rand[j]] == 4) {
						setColor(GREEN, BLACK);
						gotoxy(62 + num1, 4);cout <<"♣";
						gotoxy(66 + num1, 8);cout <<"♣";
					}
					if (number[num1_rand[j]] == 13) {
						gotoxy(65 + num1, 6);cout <<"A";
					}
					else if (number[num1_rand[j]] == 10) {
						gotoxy(65 + num1, 6);cout <<"J";
					}
					else if (number[num1_rand[j]] == 11) {
						gotoxy(65 + num1, 6);cout <<"Q";
					}
					else if (number[num1_rand[j]] == 12) {
						gotoxy(65 + num1, 6);cout <<"K";
					}
					else if (number[num1_rand[j]] == num1_rand[j] + 1) {
						gotoxy(65 + num1, 6);cout << num1_rand[j];
					}
					//					}
					num1 += 12;
					j++;			//배열을 1칸씩 증가 시킨다.
				}
			}
		}
	}
}

void playerCard(int x, int y, int number)
{
	int r = 1; // memeber[number].checksurvivor = true
	if (1) {
		gotoxy(x, y);     cout << "┏━━━━━━┓┏━━━━━━┓";
		gotoxy(x, y + 1); cout << "┃      ┃┃      ┃";
		gotoxy(x, y + 2); cout << "┃      ┃┃      ┃";
		gotoxy(x, y + 3); cout << "┃      ┃┃      ┃";
		gotoxy(x, y + 4); cout << "┃      ┃┃      ┃";
		gotoxy(x, y + 5); cout << "┃      ┃┃      ┃";
		gotoxy(x, y + 6); cout << "┗━━━━━━┛┗━━━━━━┛";
	}
	else {
		gotoxy(x, y);     cout << "								   ";
		gotoxy(x, y + 1); cout << "								   ";
		gotoxy(x, y + 2); cout << "								   ";
		gotoxy(x, y + 3); cout << "								   ";
		gotoxy(x, y + 4); cout << "								   ";
		gotoxy(x, y + 5); cout << "								   ";
		gotoxy(x, y + 6); cout << "								   ";
	}
}

void printOrder(int result) //
{
	switch (result)
	{
		case 1:
			cout <<"하이카드\n";
			break;
		case 2:
			cout <<"원페어\n";
			break;
		case 3:
			cout <<"투페어\n";
			break;
		case 4:
			cout <<"트리플\n";
			break;
		case 5:
			cout <<"스트레이트\n";
			break;
		case 6:
			cout <<"플러쉬\n";
			break;
		case 7:
			cout <<"풀하우스\n";
			break;
		case 8:
			cout <<"포카드\n";
			break;
		case 9:
			cout <<"스트레이트 플러시\n";
			break;
	}
}