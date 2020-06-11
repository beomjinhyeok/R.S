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
	gotoxy(80, 18); cout << "|                       |-";
	gotoxy(80, 19); cout << "|      승리!!!!!!!      |";
	gotoxy(80, 20); cout << "|                       |";
	gotoxy(80, 21); cout << "------------------------";
	introGame(); // 시작화면의 표시부분 함수
}

void defeatPrint()
{
	gotoxy(80, 17); cout << "------------------------";
	gotoxy(80, 18); cout << "|                       |-";
	gotoxy(80, 19); cout << "|      패배!!!!!!!      |";
	gotoxy(80, 20); cout << "|                       |";
	gotoxy(80, 21); cout << "------------------------";
	introGame(); // 시작화면의 표시부분 함수
}

