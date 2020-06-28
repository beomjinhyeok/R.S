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
	for (int i = 0; i < 35; i++)
	{
		gotoxy(30, i);
		cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
	}
	player(10, 3);
	cout << "도영";
	player(10, 18);
	cout << "진혁";
	player(150, 3);
	cout << "정훈";
	player(150, 18);
	cout << "강민";
	gotoxy(80, 35); cout << "참가자";

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
	gotoxy(15, 12); cout << "https://crash-landing.github.io" << endl;
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
			return x - 60;
		}

		}
	}

}

void bettingNumber() 
{
	while (1) {
		int bettingMenuNumber = bettingMenuChoice(); // 베팅메뉴 선택 함수
		setColor(GREEN, WHITE);
		if (bettingMenuNumber == 0) // 콜
		{
			gotoxy(45, 17); cout << "                □□□□□         □         □             □                        ";
			gotoxy(45, 18); cout << "                □               □  □       □             □                        ";
			gotoxy(45, 19); cout << "                □             □□□□□     □             □                        ";
			gotoxy(45, 20); cout << "                □             □      □     □             □                        ";
			gotoxy(45, 21); cout << "                □□□□□     □      □     □□□□□     □□□□□                ";
		}
		else if (bettingMenuNumber == 10) // 다이
		{
			gotoxy(45, 17); cout << "                       □□□□         □□□       □□□□□                        ";
			gotoxy(45, 18); cout << "                       □     □          □         □                                ";
			gotoxy(45, 19); cout << "                       □      □         □         □□□□□                        ";
			gotoxy(45, 20); cout << "                       □     □          □         □                                ";
			gotoxy(45, 21); cout << "                       □□□□         □□□       □□□□□                        ";
		}
		else if (bettingMenuNumber == 20) // 더블
		{
			gotoxy(45, 17); cout << " □□□□       □□□□□     □      □     □□□□       □             □□□□□ ";
			gotoxy(45, 18); cout << " □     □      □      □     □      □     □     □      □             □         ";
			gotoxy(45, 19); cout << " □      □     □      □     □      □     □□□□       □             □□□□□ ";
			gotoxy(45, 20); cout << " □     □      □      □     □      □     □     □      □             □         ";
			gotoxy(45, 21); cout << " □□□□       □□□□□     □□□□□     □□□□       □□□□□     □□□□□ ";
		}
		else if (bettingMenuNumber == 30) // 하프
		{
			gotoxy(45, 17); cout << "                □      □         □         □             □□□□□                ";
			gotoxy(45, 18); cout << "                □      □       □  □       □             □                        ";
			gotoxy(45, 19); cout << "                □□□□□     □□□□□     □             □□□□□                ";
			gotoxy(45, 20); cout << "                □      □     □      □     □             □                        ";
			gotoxy(45, 21); cout << "                □      □     □      □     □□□□□     □                        ";
		}
		else if (bettingMenuNumber == 40) // 올인
		{
			gotoxy(45, 17); cout << "     □         □             □                 □□□       □      □   ";
			gotoxy(45, 18); cout << "   □  □       □             □                   □         □□    □   ";
			gotoxy(45, 19); cout << " □□□□□     □             □                   □         □  □  □   ";
			gotoxy(45, 20); cout << " □      □     □             □                   □         □    □□   ";
			gotoxy(45, 21); cout << " □      □     □□□□□     □□□□□         □□□       □      □   ";
		}
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
	int shape[5] = { 0,1,2,3,4 }; //null, spade, diamond, heart, cluber
	int num1ber[14] = { 0,2,3,4,5,6,7,8,9,10,11,12,13,1 }; //null, 2~10, jack, queen, king, ace
	int x = 28, y = 29;
	int i, j, k, v = 1, hide = 0;		//hide 0 숨김, 1 표시
	int get = 3;
	int num1 = 0, num2 = 0;
	setColor(GREEN, WHITE);
	for (k = 0; k < 2; k++)
	{
		if (k == 0) // 현재 뒷면인 상태
		{
			for (i = 0;i < 4;i++)
			{
				num1 = 0;
				for (j = 0;j < 25;j++)
				{
					Sleep(10);
					gotoxy(x - num1, 8); printf("┏--------┓");
					gotoxy(x - num1, 9); printf("┃?       ┃");
					gotoxy(x - num1, 10);printf("┃        ┃");
					gotoxy(x - num1, 11);printf("┃   ??   ┃");
					gotoxy(x - num1, 12);printf("┃        ┃");
					gotoxy(x - num1, 13);printf("┃       ?┃");
					gotoxy(x - num1, 14);printf("┗━━━━┛");
					num1 += 1;
				}
				x += 2;
			}
			num1 = 0;
			for (i = 0;i < 4;i++)
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
						gotoxy(10 - num2, 15 - num1);printf("          ");
					}
					gotoxy(10 - num2, 8 - num1); printf("┏━━━┓");
					gotoxy(10 - num2, 9 - num1); printf("┃?     ┃");
					gotoxy(10 - num2, 10 - num1);printf("┃      ┃");
					gotoxy(10 - num2, 11 - num1);printf("┃   ?  ┃");
					gotoxy(10 - num2, 12 - num1);printf("┃      ┃");
					gotoxy(10 - num2, 13 - num1);printf("┃     ?┃");
					gotoxy(10 - num2, 14 - num1);printf("┗━━━┛");
					if (i % 2 == 1)
					{
						gotoxy(10 - num2, 7 - num1);printf("          ");
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
					//white();
					gotoxy(4 + num1, 1);printf("┏━━━┓");
					gotoxy(4 + num1, 2);printf("┃?     ┃");
					gotoxy(4 + num1, 3);printf("┃      ┃");
					gotoxy(4 + num1, 4);printf("┃   ?  ┃");
					gotoxy(4 + num1, 5);printf("┃      ┃");
					gotoxy(4 + num1, 6);printf("┃     ?┃");
					gotoxy(4 + num1, 7);printf("┗━━━┛");
					//					if(hide != 1){
					if (shape[shape_rand[j]] == 1) {
						//white();
						gotoxy(6 + num1, 2);printf("♠");
						gotoxy(10 + num1, 6);printf("♠");
					}
					else if (shape[shape_rand[j]] == 2) {
						//red();
						gotoxy(6 + num1, 2);printf("◆");
						gotoxy(10 + num1, 6);printf("◆");
					}
					else if (shape[shape_rand[j]] == 3) {
						//red();
						gotoxy(6 + num1, 2);printf("♥");
						gotoxy(10 + num1, 6);printf("♥");
					}
					else if (shape[shape_rand[j]] == 4) {
						//white();
						gotoxy(6 + num1, 2);printf("♣");
						gotoxy(10 + num1, 6);printf("♣");
					}
					if (num1ber[num1_rand[j]] == 13) {
						gotoxy(9 + num1, 4);printf("A");
					}
					else if (num1ber[num1_rand[j]] == 10) {
						gotoxy(9 + num1, 4);printf("J");
					}
					else if (num1ber[num1_rand[j]] == 11) {
						gotoxy(9 + num1, 4);printf("Q");
					}
					else if (num1ber[num1_rand[j]] == 12) {
						gotoxy(9 + num1, 4);printf("K");
					}
					else if (num1ber[num1_rand[j]] == num1_rand[j]+1) {
						gotoxy(8 + num1, 4);printf("%2d", num1_rand[j]);
					}
					//					}
					num1 += 12;
					j++;			//배열을 1칸씩 증가 시킨다.
				}
				else
				{
					if (i > get)
					{
						_getch();
					}
					Sleep(300);
					//white();
					gotoxy(4 + num2, 15);printf("┏━━━┓");
					gotoxy(4 + num2, 16);printf("┃      ┃");
					gotoxy(4 + num2, 17);printf("┃      ┃");
					gotoxy(4 + num2, 18);printf("┃      ┃");
					gotoxy(4 + num2, 19);printf("┃      ┃");
					gotoxy(4 + num2, 20);printf("┃      ┃");
					gotoxy(4 + num2, 21);printf("┗━━━┛");
					if (shape[shape_rand2[v]] == 1) {
						//white();
						gotoxy(6 + num2, 16);printf("♠");
						gotoxy(10 + num2, 20);printf("♠");
					}					
					else if (shape[shape_rand2[v]] == 2) {
						//red();
						gotoxy(6 + num2, 16);printf("◆");
						gotoxy(10 + num2, 20);printf("◆");
					}					
					else if (shape[shape_rand2[v]] == 3) {
						//red();
						gotoxy(6 + num2, 16);printf("♥");
						gotoxy(10 + num2, 20);printf("♥");
					}
					else if (shape[shape_rand2[v]] == 4) {
						//white();
						gotoxy(6 + num2, 16);printf("♣");
						gotoxy(10 + num2, 20);printf("♣");
					}
					if (num1ber[num1_rand2[v]] == 13) {
						gotoxy(9 + num2, 18);printf("A");
					}
					else if (num1ber[num1_rand2[v]] == 10) {
						gotoxy(9 + num2, 18);printf("J");
					}
					else if (num1ber[num1_rand2[v]] == 11) {
						gotoxy(9 + num2, 18);printf("Q");
					}
					else if (num1ber[num1_rand2[v]] == 12) {
						gotoxy(9 + num2, 18);printf("K");
					}
					else if (num1ber[num1_rand2[v]] == num1_rand2[v]+1) {
						gotoxy(8 + num2, 18);printf("%2d", num1_rand2[v]);
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
			gotoxy(14 + jump, 4);printf("┏━━━┓");
			gotoxy(14 + jump, 5);printf("┃      ┃");
			gotoxy(14 + jump, 6);printf("┃      ┃");
			gotoxy(14 + jump, 7);printf("┃      ┃");
			gotoxy(14 + jump, 8);printf("┃      ┃");
			gotoxy(14 + jump, 9);printf("┃      ┃");
			gotoxy(14 + jump, 10);printf("┗━━━┛");
			if (pattern[i - re] == 1) {
				white();
				gotoxy(16 + jump, 5);printf("♠");
				gotoxy(20 + jump, 9);printf("♠");
			}
			else if (pattern[i - re] == 2) {
				red();
				gotoxy(16 + jump, 5);printf("◆");
				gotoxy(20 + jump, 9);printf("◆");
			}
			else if (pattern[i - re] == 3) {
				red();
				gotoxy(16 + jump, 5);printf("♥");
				gotoxy(20 + jump, 9);printf("♥");
			}
			else if (pattern[i - re] == 4) {
				white();
				gotoxy(16 + jump, 5);printf("♣");
				gotoxy(20 + jump, 9);printf("♣");
			}
			if (number[i - re] == 13) {
				gotoxy(19 + jump, 7);printf("A");
			}
			else if (number[i - re] == 10) {
				gotoxy(19 + jump, 7);printf("J");
			}
			else if (number[i - re] == 11) {
				gotoxy(19 + jump, 7);printf("Q");
			}
			else if (number[i - re] == 12) {
				gotoxy(19 + jump, 7);printf("K");
			}
			else {
				gotoxy(18 + jump, 7);printf("%2d", number[i - re]+1);
			}
			jump += 10;
		}
	}
	if (count == 1)
	{
		for (i = 1; i <= size; i++) {
			white();
			gotoxy(14 + jump, 12);printf("┏━━━┓");
			gotoxy(14 + jump, 13);printf("┃      ┃");
			gotoxy(14 + jump, 14);printf("┃      ┃");
			gotoxy(14 + jump, 15);printf("┃      ┃");
			gotoxy(14 + jump, 16);printf("┃      ┃");
			gotoxy(14 + jump, 17);printf("┃      ┃");
			gotoxy(14 + jump, 18);printf("┗━━━┛");
			if (pattern[i - re] == 1) {
				white();
				gotoxy(16 + jump, 13);printf("♠");
				gotoxy(20 + jump, 17);printf("♠");
			}			
			else if (pattern[i - re] == 2) {
				red();
				gotoxy(16 + jump, 13);printf("◆");
				gotoxy(20 + jump, 17);printf("◆");
			}
			else if (pattern[i - re] == 3) {
				red();
				gotoxy(16 + jump, 13);printf("♥");
				gotoxy(20 + jump, 17);printf("♥");
			}
			else if (pattern[i - re] == 4) {
				white();
				gotoxy(16 + jump, 13);printf("♣");
				gotoxy(20 + jump, 17);printf("♣");
			}
			if (number[i - re] == 13) {
				gotoxy(19 + jump, 15);printf("A");
			}
			else if (number[i - re] == 10) {
				gotoxy(19 + jump, 15);printf("J");
			}
			else if (number[i - re] == 11) {
				gotoxy(19 + jump, 15);printf("Q");
			}
			else if (number[i - re] == 12) {
				gotoxy(19 + jump, 15);printf("K");
			}
			else {
				gotoxy(18 + jump, 15);printf("%2d", number[i - re]+1);
			}
			jump += 10;
		}
	}
	if (count == 0)					//결과 값 위치 지정
		gotoxy(68, 4);
	else if (count == 1)
		gotoxy(68, 6);
}

void print(int result, int i) //
{
	white();

	switch (result)
	{
	case 2:
		result_Dack(3, i, 0, results, patterns);
		white(); printf("하이카드\n");
		break;
	case 3:
		result_Dack(5, i, 0, results, patterns);
		white(); printf("원페어\n");
		break;
	case 4:
		result_Dack(5, i, 0, results, patterns);
		white(); printf("투페어\n");
		break;
	case 5:
		result_Dack(5, i, 0, results, patterns);
		white(); printf("쓰리카드\n");
		break;
	case 6:
		result_Dack(5, i, 0, results, patterns);
		white(); printf("스트레이트\n");
		break;
	case 7:
		result_Dack(5, i, 0, results, patterns);
		white(); printf("플러쉬\n");
		break;
	case 8:
		result_Dack(4, i, 0, results, patterns);
		white(); printf("풀하우스\n");
		break;
	case 9:
		result_Dack(5, i, 0, results, patterns);
		white(); printf("포카드\n");
		break;
	case 10:
		result_Dack(5, i, 0, results, patterns);
		white(); printf("스트레이트 플러시\n");
		break;
	case 11:
		result_Dack(5, i, 0, results, patterns);
		white(); printf("로얄 스트레이트 플러시\n");
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
