#define _CRT_SECURE_NO_WARNINGS 1


#include"game.h"
int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y - 1] +
		board[x - 1][y] +
		board[x - 1][y + 1] +
		board[x][y - 1] +
		board[x][y + 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] - 8 * '0';
}
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-80)
	{
		printf("ÇëÊäÈë×ø±ê>");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y]=='1')
			{
				printf("Äã²Èµ½À×À²\n");
				displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y);
				show[x][y] = count+'0';
				displayboard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("×ø±ê·Ç·¨£¡£¡£¡£¡\n");
		}

	}
	if (win == ROW * COL - 80)
	{
		printf("ÄãÓ®À²\n");
		displayboard(mine, ROW, COL);
	}

}
void setmine(char board[ROWS][COLS], int row, int col)
{
	int mine = 80;
	int x = 0;
	int y = 0;
	while (mine)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			mine--;
		}
	}

}
void initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i, j;

	for (i = 0; i <=col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}