#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"


//��ӡ�˵�
void menu()
{
	printf("******************\n");
	printf("*****  1.play  ***\n");
	printf("*****  0.exit  ***\n");
	printf("******************\n");

}
void game()
{
	//���ú��׵���Ϣ
	char mine[ROWS][COLS] = {0};
	//�Ų���׵���Ϣ
	char show[ROWS][COLS] = {0};
	//��ʼ�����������Ϊָ������
	//mine������û�в����׵�ʱ�򣬶��ǡ�0��
	board_Init(mine,ROWS,COLS,'0');
	//show������û���Ų��׵�ʱ���ǡ�*��
	board_Init(show,ROWS,COLS,'*');
	
	//��ӡ����
	//Display_board(mine, ROW, COL);
	//Display_board(show, ROW, COL);
	//������
	Set_mine(mine, ROW, COL);
	//Display_board(mine, ROW, COL);
	Display_board(show, ROW, COL);
	//�Ų���
	Fine_Mine(mine, show, ROW, COL);


		
}
int main()
{
	//���������������
	 srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		printf("ɨ����Ϸ\n");
		menu();
		printf("��ѡ��1/0):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
		default:
			printf("�������\n");
		}
	}while (input);
	return 0;
}