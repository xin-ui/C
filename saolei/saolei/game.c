#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


//数组初始化
void board_Init(char board[ROWS][COLS], int rows, int cols,char x)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		
		for (j = 0; j < cols; j++)
		{
			board[i][j] = x;
		}
	}
}



//打印数组
void Display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----扫雷游戏-----\n");
	printf("  ");
	for (j = 1; j <= col; j++)
	{
		
		printf("%d ", j);
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
	printf("-----扫雷游戏-----\n");
	printf("\n");

}


//设置雷
void Set_mine(char board[ROWS][COLS], int row, int col)
{
	//定义雷的数量
	int count = COUNT;
	//行1-9
	//列1-9
	while (count)
	{
		int x = rand() % row + 1;//在一行中随机生成一个数
		int y = rand() % col + 1;//在一列中随机生成一个数
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
	
}


//统计排查坐标周围雷的个数
int get_mine_count(char board[ROWS][COLS], int x, int y)
{

	return board[x - 1][y - 1] +
		board[x - 1][y] +
		board[x - 1][y + 1] +
		board[x][y + 1] +
		board[x + 1][y + 1] +
		board[x + 1][y] +
		board[x + 1][y - 1] +
		board[x][y - 1] - 8 * '0';
}

//排查雷
void Fine_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	
	while (win<row*col-COUNT)
	{
		printf("请输入要排查的坐标>:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//如果是雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				Display_board(mine, ROW, COL);
				break;
			}
			else//如果不是雷
			{
				win++;
				//统计mine数组中x,y坐标周围有几个雷
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//转换成数字字符
				Display_board(show, ROW, COL);
			}
		}
		else
			printf("输入坐标非法，请重新输入\n");
		
	}
	if (win == row*col - COUNT)
	{
		printf("恭喜你，排雷成功\n");
		Display_board(mine, ROW, COL);
	}
}



