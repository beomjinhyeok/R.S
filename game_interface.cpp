#include "poker_header.h"

void makeBoard()
{
	system("cls");
	gotoTest();
	gotoxy(21, 10);
	setColor(15, 15);
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
	for (int i = 0; i < 25; i++)
	{
		setColor(15, 0);
		gotoxy(21, 11 + i);
		setColor(15, 15);
		cout << "¡á";
		setColor(1, 1);
		cout << "                                                                                    ";
		setColor(15, 15);
		cout << "¡á";
	}
	setColor(15, 0);
	gotoxy(21, 36);
	setColor(15, 15);
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
	setColor(15, 0);
}


