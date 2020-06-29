#include "main.h"

void setColor(int back, int text)
{
	HANDLE hcon;

	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, (back << 4) | text);
}

void init()
{
	system("mode con cols=176 lines=50 | title 텍사스 홀덤 ");
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
	
	player(10, 3);
	cout << "도영";
	player(10, 18);
	cout << "진혁";
	player(150, 3);
	cout << "정훈";
	player(150, 18);
	cout << "강민";
	gotoxy(80, 36); cout << "참가자";

	gotoxy(60, 40); cout << "콜";
	gotoxy(70, 40); cout << "다이";
	gotoxy(80, 40); cout << "더블";
	gotoxy(90, 40); cout << "하프";
	gotoxy(100, 40); cout << "올인";

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
	gotoxy(x, y + 4); cout << "■□■■■■□■\n";
	gotoxy(x, y + 5); cout << "■□□□□□□■\n\n";
	gotoxy(x, y + 6); cout << "■■■■■■■■\n\n";
	gotoxy(x, y + 8); cout << "  참가자: ";
}					

int bettingMenuChoice()
{
	setColor(BLACK, WHITE);
	int x = 60;
	int y = 40;
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
				if (x < 100) 
				{	
					gotoxy(x - 2, y); cout << " ";
					x = x + 10;
					gotoxy(x - 2, y); cout << ">";
				}
				break;
			}

			case LEFT:
			{
				if (x > 60)
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
	int y = 14;
	switch (x / 10) {
		case 0:  // 빈 화면
			setColor(GREEN, GREEN);
			for (int i = y; i < 22; i++)
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

void picture(int* num1_rand, int* shape_rand, int* num1_rand2, int* shape_rand2)
{
	setColor(GREEN, WHITE);
	int shape[5] = { 0,1,2,3,4 }; //null, spade, diamond, heart, cluber
	int number[14] = { 0,2,3,4,5,6,7,8,9,10,11,12,13,1 }; //null, 2~10, jack, queen, king, ace
	int x = 80, y = 14;
	int i, j, k, v = 1, hide = 0;		//hide 0 숨김, 1 표시
	int get = 3;
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
						gotoxy(60 - num2, 21 - num1); cout << "          ";
					}
					gotoxy(60 - num2, 14 - num1); cout <<"┏━━━━━━┓";
					gotoxy(60 - num2, 15 - num1); cout <<"┃?     ┃";
					gotoxy(60 - num2, 16 - num1); cout <<"┃      ┃";
					gotoxy(60 - num2, 17 - num1); cout <<"┃   ?  ┃";
					gotoxy(60 - num2, 18 - num1); cout <<"┃      ┃";
					gotoxy(60 - num2, 19 - num1); cout <<"┃     ?┃";
					gotoxy(60 - num2, 20 - num1); cout <<"┗━━━━━━┛";
					if (i % 2 == 1)
					{
						gotoxy(60 - num2, 13 - num1); cout <<"          ";
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
			num1 = 0;
			num2 = 0;
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
				else // 아래칸 배열
				{
					if (i > get)
					{
						_getch();
					}
					Sleep(300);
					gotoxy(60 + num2, 26); cout << "┏━━━━━━┓";
					gotoxy(60 + num2, 27); cout << "┃      ┃";
					gotoxy(60 + num2, 28); cout << "┃      ┃";
					gotoxy(60 + num2, 29); cout << "┃      ┃";
					gotoxy(60 + num2, 30); cout << "┃      ┃";
					gotoxy(60 + num2, 31); cout << "┃      ┃";
					gotoxy(60 + num2, 32); cout << "┗━━━━━━┛";
					if (shape[shape_rand2[v]] == 1) {
						setColor(GREEN, BLACK);
						gotoxy(62 + num2, 27);cout << "♠";
						gotoxy(66 + num2, 31);cout << "♠";
					}
					else if (shape[shape_rand2[v]] == 2) {
						setColor(GREEN, RED);
						gotoxy(62 + num2, 27);cout << "◆";
						gotoxy(66 + num2, 31);cout << "◆";
					}
					else if (shape[shape_rand2[v]] == 3) {
						setColor(GREEN, RED);
						gotoxy(62 + num2, 27);cout << "♥";
						gotoxy(66 + num2, 31);cout << "♥";
					}
					else if (shape[shape_rand2[v]] == 4) {
						setColor(GREEN, BLACK);
						gotoxy(62 + num2, 27);cout << "♣";
						gotoxy(66 + num2, 31);cout << "♣";
					}
					if (number[num1_rand2[v]] == 13) {
						gotoxy(65 + num2, 29);cout << "A";
					}
					else if (number[num1_rand2[v]] == 10) {
						gotoxy(65 + num2, 29);cout <<"J";
					}
					else if (number[num1_rand2[v]] == 11) {
						gotoxy(65 + num2, 29);cout <<"Q";
					}
					else if (number[num1_rand2[v]] == 12) {
						gotoxy(65 + num2, 29);cout <<"K";
					}
					else if (number[num1_rand2[v]] == num1_rand2[v] + 1) {
						gotoxy(65 + num2, 29);cout << num1_rand2[v];
					}
					num2 += 12;
					v++; //배열을 한칸씩 증가시킨다.
				}
			}
		}
	}
}

void result_Dack(int size, int count, int re, int* number, int* pattern)
{
	int i, jump = 0;			//jump = 카드값 위치 바꾸기

	if (count == 0) {
		for (i = 1; i <= size; i++) {
			white();
			gotoxy(14 + jump, 4);cout <<"┏━━━┓";
			gotoxy(14 + jump, 5);cout <<"┃      ┃";
			gotoxy(14 + jump, 6);cout <<"┃      ┃";
			gotoxy(14 + jump, 7);cout <<"┃      ┃";
			gotoxy(14 + jump, 8);cout <<"┃      ┃";
			gotoxy(14 + jump, 9);cout <<"┃      ┃";
			gotoxy(14 + jump, 10);cout <<"┗━━━┛";
			if (pattern[i - re] == 1) {
				white();
				gotoxy(16 + jump, 5);cout <<"♠";
				gotoxy(20 + jump, 9);cout <<"♠";
			}
			else if (pattern[i - re] == 2) {
				red();
				gotoxy(16 + jump, 5);cout <<"◆";
				gotoxy(20 + jump, 9);cout <<"◆";
			}
			else if (pattern[i - re] == 3) {
				red();
				gotoxy(16 + jump, 5);cout <<"♥";
				gotoxy(20 + jump, 9);cout <<"♥";
			}
			else if (pattern[i - re] == 4) {
				white();
				gotoxy(16 + jump, 5);cout <<"♣";
				gotoxy(20 + jump, 9);cout <<"♣";
			}
			if (number[i - re] == 13) {
				gotoxy(19 + jump, 7);cout <<"A";
			}
			else if (number[i - re] == 10) {
				gotoxy(19 + jump, 7);cout <<"J";
			}
			else if (number[i - re] == 11) {
				gotoxy(19 + jump, 7);cout <<"Q";
			}
			else if (number[i - re] == 12) {
				gotoxy(19 + jump, 7);cout <<"K";
			}
			else {
				gotoxy(18 + jump, 7);cout << number[i - re] + 1;
			}
			jump += 10;
		}
	}
	if (count == 1)
	{
		for (i = 1; i <= size; i++) {
			white();
			gotoxy(14 + jump, 12);cout <<"┏━━━┓";
			gotoxy(14 + jump, 13);cout <<"┃      ┃";
			gotoxy(14 + jump, 14);cout <<"┃      ┃";
			gotoxy(14 + jump, 15);cout <<"┃      ┃";
			gotoxy(14 + jump, 16);cout <<"┃      ┃";
			gotoxy(14 + jump, 17);cout <<"┃      ┃";
			gotoxy(14 + jump, 18);cout <<"┗━━━┛";
			if (pattern[i - re] == 1) {
				white();
				gotoxy(16 + jump, 13);cout <<"♠";
				gotoxy(20 + jump, 17);cout <<"♠";
			}
			else if (pattern[i - re] == 2) {
				red();
				gotoxy(16 + jump, 13);cout <<"◆";
				gotoxy(20 + jump, 17);cout <<"◆";
			}
			else if (pattern[i - re] == 3) {
				red();
				gotoxy(16 + jump, 13);cout <<"♥";
				gotoxy(20 + jump, 17);cout <<"♥";
			}
			else if (pattern[i - re] == 4) {
				white();
				gotoxy(16 + jump, 13);cout <<"♣";
				gotoxy(20 + jump, 17);cout <<"♣";
			}
			if (number[i - re] == 13) {
				gotoxy(19 + jump, 15);cout <<"A";
			}
			else if (number[i - re] == 10) {
				gotoxy(19 + jump, 15);cout <<"J";
			}
			else if (number[i - re] == 11) {
				gotoxy(19 + jump, 15);cout <<"Q";
			}
			else if (number[i - re] == 12) {
				gotoxy(19 + jump, 15);cout <<"K";
			}
			else {
				gotoxy(18 + jump, 15);cout << number[i - re] + 1;
			}
			jump += 10;
		}
	}
	if (count == 0)					//결과 값 위치 지정
		gotoxy(68, 4);
	else if (count == 1)
		gotoxy(68, 6);
}

void printOrder(int result, int i) //
{
	white();
	int card_one = 0, reset_count = 0, temp[8] = { 0 }, results[5] = { 0 }, patterns[5] = { 0 };

	switch (result)
	{
		case 1:
			result_Dack(3, i, 0, results, patterns);
			white(); cout <<"하이카드\n";
			break;
		case 2:
			result_Dack(5, i, 0, results, patterns);
			white(); cout <<"원페어\n";
			break;
		case 3:
			result_Dack(5, i, 0, results, patterns);
			white(); cout <<"투페어\n";
			break;
		case 4:
			result_Dack(5, i, 0, results, patterns);
			white(); cout <<"트리플\n";
			break;
		case 5:
			result_Dack(5, i, 0, results, patterns);
			white(); cout <<"스트레이트\n";
			break;
		case 6:
			result_Dack(5, i, 0, results, patterns);
			white(); cout <<"플러쉬\n";
			break;
		case 7:
			result_Dack(4, i, 0, results, patterns);
			white(); cout <<"풀하우스\n";
			break;
		case 8:
			result_Dack(5, i, 0, results, patterns);
			white(); cout <<"포카드\n";
			break;
		case 9:
			result_Dack(5, i, 0, results, patterns);
			white(); cout <<"스트레이트 플러시\n";
			break;
	}
}

void red()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
}
void white()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void blue()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}