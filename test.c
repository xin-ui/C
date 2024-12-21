#define _CRT_SECURE_NO_WARNINGS 1
//猜数字游戏
//电脑产生 一个随机数（1-100)
//猜数字
//猜大了
//猜小了
//直到猜对了，结束
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
void menu()
{
	printf("********************************\n");
	printf("***********   1. play   ********\n");
	printf("***********   2. exit   ********\n");
	printf("********************************\n");
}
void game()
{
	int guess = 0;
	//1,生成随机数
	//%100  0-99
	int ret = rand() % 100 + 1;//生成随机数的函数
	//printf("%d\n", ret);
	//2.猜数字
	while (1)
	{
		printf("请猜数字:>");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("猜小了\n");
		}
		else  if (guess>ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}
int main()
{
	printf("请注意你有60秒钟的时间进行猜数字，60秒钟之后电脑自动关机，猜对数字取消关机\n");
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择(0/1):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//猜数字整个逻辑
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);

	return 0;
}