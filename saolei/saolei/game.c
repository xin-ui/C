#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


//�����ʼ��
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



//��ӡ����
void Display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----ɨ����Ϸ-----\n");
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
	printf("-----ɨ����Ϸ-----\n");
	printf("\n");

}


//������
void Set_mine(char board[ROWS][COLS], int row, int col)
{
	//�����׵�����
	int count = COUNT;
	//��1-9
	//��1-9
	while (count)
	{
		int x = rand() % row + 1;//��һ�����������һ����
		int y = rand() % col + 1;//��һ�����������һ����
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
	
}


//ͳ���Ų�������Χ�׵ĸ���
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

//�Ų���
void Fine_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	
	while (win<row*col-COUNT)
	{
		printf("������Ҫ�Ų������>:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�������
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				Display_board(mine, ROW, COL);
				break;
			}
			else//���������
			{
				win++;
				//ͳ��mine������x,y������Χ�м�����
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//ת���������ַ�
				Display_board(show, ROW, COL);
			}
		}
		else
			printf("��������Ƿ�������������\n");
		
	}
	if (win == row*col - COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		Display_board(mine, ROW, COL);
	}
}



