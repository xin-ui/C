#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"



//���̳�ʼ��
void board_Init(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}



//��ӡ����
//��һ���汾
void board_Display(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//��ӡ����
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		//��ӡ�ָ���
		if (i < row-1)
		printf("---|---|---\n");
	}
}



//��ӡ����Mark2
void board_Display2(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//��ӡ����
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ���
		if (i < row - 1)
		{
			//printf("---|---|---\n");
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
 


//�������
void Player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�������\n");
	while (1)
	{
		printf("�����ѡ������λ��\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�����ѱ�ռ�ã�������ѡ��λ��\n");
		}
		else
			printf("����Ƿ�������������\n");
	}
}



//��������
//��û�������λ���������
void Computer_move(char board[ROW][COL], int row, int col)
{
	printf("��������\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;//0-2
		y = rand() % col;//0-2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}





//ƽ���ж�
//���˷���1
//��������0
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}	
		}
	}
	return 1;
}




//�ж���Ӯ
//
//���Ӯ-'*'
//����Ӯ-'#'
//ƽ��-'Q'
//��Ϸ����-'c'
//
char IsWin(char board[ROW][COL], int row, int col)
{
	//��
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	//��
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//ƽ��
	if (IsFull(board,row,col))
	{
		return 'Q';
	}
	//��Ϸ����
	return 'C';
}


//�ж���ӮMark2
char IsWin2(char board[ROW][COL], int row, int col, char tmp)//�ж���Ӯ�������ַ�
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < ROW; i++)//�ж�һ�Ƿ��������ַ���ͬ
	{
		int count = 0;
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] != tmp)//��һ����ͬ��break��������ѭ��
				break;
			else
				count++;//��һ����ͬcount��+1
			if (count == CON)//��count����3ʱ�ʹ���һ������������ͬ
				return tmp;//��һ������������ͬ���ַ�ʱ�ʹ�����ַ�����Ӧ��Ӯ�˷��ظ��ַ�
		}

	}
	for (j = 0; j < COL; j++)//ͬ���ж�һ�����Ƿ��������ַ���ͬ
	{
		int count = 0;

		for (i = 0; i < ROW; i++)
		{
			if (board[i][j] != tmp)
				break;
			else
				count++;
			if (count == CON)
				return tmp;
		}

	}
	for (count = 0, i = 0; i < ROW; i++)//�жϴ������ҵ�ֱ�������ַ��Ƿ���ͬ
	{

		if (board[i][i] != tmp)
			break;
		else
			count++;
		if (count == CON)
			return tmp;
	}

	for (count = 0, j = COL - 1, i = 0; j >= 0, i <ROW; j--, i++)//�жϴ������ҵ�ֱ��
	{

		if (board[i][j] != tmp)
			break;
		else
			count++;
		if (count == CON)
			return tmp;
	}
	//ƽ��
	if (IsFull(board, row, col))
	{
		return 'Q';
	}
	//��Ϸ����
	return 'C';
}
