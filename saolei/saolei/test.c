#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"


//打印菜单
void menu()
{
	printf("******************\n");
	printf("*****  1.play  ***\n");
	printf("*****  0.exit  ***\n");
	printf("******************\n");

}
void game()
{
	//布置好雷的信息
	char mine[ROWS][COLS] = {0};
	//排查出雷的信息
	char show[ROWS][COLS] = {0};
	//初始化数组的内容为指定内容
	//mine数组在没有布置雷的时候，都是‘0’
	board_Init(mine,ROWS,COLS,'0');
	//show数组在没有排查雷的时候都是‘*’
	board_Init(show,ROWS,COLS,'*');
	
	//打印数组
	//Display_board(mine, ROW, COL);
	//Display_board(show, ROW, COL);
	//设置雷
	Set_mine(mine, ROW, COL);
	//Display_board(mine, ROW, COL);
	Display_board(show, ROW, COL);
	//排查雷
	Fine_Mine(mine, show, ROW, COL);


		
}
int main()
{
	//设置随机数的生成
	 srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		printf("扫雷游戏\n");
		menu();
		printf("请选择（1/0):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
		default:
			printf("输入错误\n");
		}
	}while (input);
	return 0;
}