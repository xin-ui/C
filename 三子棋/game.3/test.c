#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"

game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//棋盘初始化
	board_Init(board,ROW ,COL );
	board_Display2(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		Player_move(board,ROW,COL);
		//判断输赢
		//ret = IsWin(board,ROW,COL);
		ret = IsWin2(board, ROW, COL, '*');

		if (ret != 'C')
		{
			break;
		}
		board_Display2(board, ROW, COL);
		//电脑下棋
		Computer_move(board, ROW, COL);
		//判断输赢
		//ret = IsWin(board, ROW, COL);
		ret = IsWin2(board, ROW, COL, '#');
		if (ret != 'C')
		{
			break;
		}
		board_Display2(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
	board_Display2(board, ROW, COL);
}

//菜单打印
void menu()
{
	printf("*******   三子棋   ******\n");
	printf("*****1. play 0. exit*****\n");
	printf("************************\n");

}

int main()
{
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	int input = 0;
	do
	{
		menu();//菜单打印
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
				printf("开始游戏\n");
				game();
				break;
		case 0:
				printf("退出游戏\n");
				break;
		default:
			printf("选择错误\n");
		}
	} while (input);
	return 0;
}