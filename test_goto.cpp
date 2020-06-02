##참고자료
#include "poker_header.h"



int getKeyBoard()
{
	char key = _getch();

	if (key == 'w' || key == 'W')
		return UP;
	else if (key == 's' || key == 'S')
		return DOWN;
	else if (key == 'a' || key == 'A')
		return LEFT;
	else if (key == 'd' || key == 'D')
		return RIGHT;
	else if (key == ' ')
		return CHOICE;
}

void gotoTest()
{
	int x = 6, y = 6;
	int enter_key;
	gotoxy(6, 6);
	while (1)
	{
		enter_key = getKeyBoard();
		switch (enter_key)
		{
		case UP:
			//gotoxy(x, y);
			cout << "              ";
			gotoxy(x, --y);
			printGoto(x, y);
			gotoxy(x, y);
			//cout << "a";
			break;
		case DOWN: 
			//gotoxy(x, y);
			cout << "              ";
			gotoxy(x, ++y);
			printGoto(x, y);
			gotoxy(x, y);
			//cout << "a";
			break;
		case LEFT: 
			//gotoxy(x, y);
			cout << "              ";
			gotoxy(--x, y);
			printGoto(x, y);
			gotoxy(x, y);
			//cout << "a";
			break;
		case RIGHT: 
			//gotoxy(x, y);
			cout << "              ";
			gotoxy(++x, y);
			printGoto(x, y);
			gotoxy(x, y);
			//cout << "a";
			break;
		case CHOICE: return;

		}
	}
}

void printGoto(const int& x,const int& y)
{
	cout << " (x,y : " << x << "," << y << ")";
}

