#pragma once
#include "main.h"

int Play_number[6] = { 0, }, Play_pattern[6] = { 0 };

int main()
{
	init(); //창 크기와 제목 설정 함수
	while (1) {
		introGame(); // 시작화면의 표시부분 함수
		int menuNumber = menuChoice(); // 메뉴 선택 함수
		if (menuNumber == 0) //게임 시작 버튼
		{
			gameImage();
			picture(Play_number, Play_pattern);
			
			choice_betting();
			choice_betting2();
			
			printAll(Play_number, Play_pattern); // 플레이어들 카드 오픈 함수.
			Print_result(1, 1);
		}
		else if (menuNumber == 1) // 게임 규칙 설명
		{
			gameRule();
		}
		else if (menuNumber == 2) // 게임 종료 버튼
		{
			return 0;
		}
		system("cls");
	}
	return 0;
}





