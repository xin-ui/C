#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
#define CON 3
//棋盘初始化
void board_Init(char board[ROW][COL], int row, int col);
//打印棋盘
void board_Display(char board[ROW][COL], int row, int col);
//玩家下棋
void Player_move(char board[ROW][COL], int row, int col);
//电脑下棋
void Computer_move(char board[ROW][COL], int row, int col);
//判断输赢
char IsWin(char board[ROW][COL], int row, int col);
char IsWin2(char board[ROW][COL], int row, int col, char tmp);