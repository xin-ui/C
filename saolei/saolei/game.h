
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//设置行和列的大小
#define ROW 9
#define COL 9


#define ROWS ROW+2
#define COLS COL+2

//设置雷的数量
#define COUNT 10
//初始化数组
void board_Init(char mine[ROWS][COLS], int rows, int cols, char x);
//打印数组
void Display_board(char board[ROWS][COLS], int row, int col);
//设置雷
void Set_mine(char board[ROWS][COLS], int row, int col);
//排查雷
void Fine_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);