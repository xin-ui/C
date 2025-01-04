#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"

game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//���̳�ʼ��
	board_Init(board,ROW ,COL );
	board_Display2(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		Player_move(board,ROW,COL);
		//�ж���Ӯ
		//ret = IsWin(board,ROW,COL);
		ret = IsWin2(board, ROW, COL, '*');

		if (ret != 'C')
		{
			break;
		}
		board_Display2(board, ROW, COL);
		//��������
		Computer_move(board, ROW, COL);
		//�ж���Ӯ
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
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	board_Display2(board, ROW, COL);
}

//�˵���ӡ
void menu()
{
	printf("*******   ������   ******\n");
	printf("*****1. play 0. exit*****\n");
	printf("************************\n");

}

int main()
{
	srand((unsigned int)time(NULL));//������������������
	int input = 0;
	do
	{
		menu();//�˵���ӡ
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
				printf("��ʼ��Ϸ\n");
				game();
				break;
		case 0:
				printf("�˳���Ϸ\n");
				break;
		default:
			printf("ѡ�����\n");
		}
	} while (input);
	return 0;
}