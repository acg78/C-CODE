//#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("*****************************************\n");
	printf("*****************************************\n");
	printf("****1.开始游戏       0.退出游戏     *****\n");
	printf("*****************************************\n");
	printf("*****************************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	initboard(mine, ROWS, COLS,'0');
	initboard(show, ROWS, COLS,'*');
	displayboard(show, ROW, COL);
	setmine(mine, ROW, COL);
	displayboard(mine, ROW, COL);
	findmine(mine, show, ROW, COL);



}


void test()
{
	int input=0;
	srand(time(NULL));
	do
	{
		menu();
		printf("请输入数字>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误！！\n");
			break;
		}
	} while (input);
}






int main()
{
	test();
	return 0;
}