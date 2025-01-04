#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"



//棋盘初始化
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



//打印棋盘
//第一个版本
void board_Display(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印数据
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		//打印分隔符
		if (i < row-1)
		printf("---|---|---\n");
	}
}



//打印棋盘Mark2
void board_Display2(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印数据
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分隔符
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
 


//玩家下棋
void Player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋\n");
	while (1)
	{
		printf("玩家请选择下棋位置\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("坐标已被占用，请重新选择位置\n");
		}
		else
			printf("坐标非法，请重新输入\n");
	}
}



//电脑下棋
//找没有下棋的位置随机下棋
void Computer_move(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
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





//平局判断
//满了返回1
//不满返回0
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




//判断输赢
//
//玩家赢-'*'
//电脑赢-'#'
//平局-'Q'
//游戏继续-'c'
//
char IsWin(char board[ROW][COL], int row, int col)
{
	//行
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	//列
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//平局
	if (IsFull(board,row,col))
	{
		return 'Q';
	}
	//游戏继续
	return 'C';
}


//判断输赢Mark2
char IsWin2(char board[ROW][COL], int row, int col, char tmp)//判断输赢，返回字符
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < ROW; i++)//判断一是否有三个字符相同
	{
		int count = 0;
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] != tmp)//有一个不同就break跳出本次循环
				break;
			else
				count++;//有一个相同count就+1
			if (count == CON)//当count等于3时就代表一行中有三个相同
				return tmp;//当一行中有三个相同的字符时就代表该字符所对应的赢了返回该字符
		}

	}
	for (j = 0; j < COL; j++)//同理判断一列中是否有三个字符相同
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
	for (count = 0, i = 0; i < ROW; i++)//判断从左往右的直线三个字符是否相同
	{

		if (board[i][i] != tmp)
			break;
		else
			count++;
		if (count == CON)
			return tmp;
	}

	for (count = 0, j = COL - 1, i = 0; j >= 0, i <ROW; j--, i++)//判断从左往右的直线
	{

		if (board[i][j] != tmp)
			break;
		else
			count++;
		if (count == CON)
			return tmp;
	}
	//平局
	if (IsFull(board, row, col))
	{
		return 'Q';
	}
	//游戏继续
	return 'C';
}
