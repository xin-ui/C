
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//�����к��еĴ�С
#define ROW 9
#define COL 9


#define ROWS ROW+2
#define COLS COL+2

//�����׵�����
#define COUNT 10
//��ʼ������
void board_Init(char mine[ROWS][COLS], int rows, int cols, char x);
//��ӡ����
void Display_board(char board[ROWS][COLS], int row, int col);
//������
void Set_mine(char board[ROWS][COLS], int row, int col);
//�Ų���
void Fine_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);