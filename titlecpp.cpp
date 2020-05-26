#include "poker_header.h"

void init()
{
	system("mode con cols=130 lines=47 | title 포커 게임");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void setColor(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawTitle()
{
	gotoxy(0, 9);
	cout<< "                     ■■■■■■          ■■■        ■          ■    ■■■■■■■     ■■■■■■■     \n"
		<< "                     ■          ■      ■      ■      ■        ■      ■               ■              ■   \n"
		<< "                     ■           ■   ■          ■    ■      ■        ■               ■              ■   \n"
		<< "                     ■          ■    ■          ■    ■    ■          ■               ■              ■   \n"
		<< "                     ■■■■■■      ■          ■    ■■■            ■■■■■■■   ■■■■■■■■     \n"
		<< "                     ■                ■          ■    ■    ■          ■               ■        ■         \n"
		<< "                     ■                ■          ■    ■      ■        ■               ■          ■       \n"
		<< "                     ■                  ■      ■      ■        ■      ■               ■            ■     \n"
		<< "                     ■                    ■■■        ■          ■    ■■■■■■■   ■              ■   \n";
	gotoxy(59, 29);
	cout << "게임 시작";
	gotoxy(59, 33);
	cout << "게임 종료";
	 
}

void selectMenu()
{
	drawTitle();
	int x = 57, y = 29, temp;
	gotoxy(x, y);
	cout << ">";
	while (1)
	{
		gotoxy(x, y);
		temp = getKeyBoard();
		switch (temp)
		{
		case UP :
			if (y > 29) 
			{
				cout << "  ";
				y -= 4;
				gotoxy(x, y);
				cout << ">";
				//gotoxy(x, y);
			}
			break;
		case DOWN :
			if (y < 33)
			{
				cout << "  ";
				y += 4;
				gotoxy(x, y);
				cout << ">";
				//gotoxy(x, y);
			}
			break;
		case CHOICE:
			makeBoard();
			return;
		}
	}
}