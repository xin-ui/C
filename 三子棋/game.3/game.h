#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
#define CON 3
//���̳�ʼ��
void board_Init(char board[ROW][COL], int row, int col);
//��ӡ����
void board_Display(char board[ROW][COL], int row, int col);
//�������
void Player_move(char board[ROW][COL], int row, int col);
//��������
void Computer_move(char board[ROW][COL], int row, int col);
//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col);
char IsWin2(char board[ROW][COL], int row, int col, char tmp);