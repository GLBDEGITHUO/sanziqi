#pragma once
#define ROW 3
#define COL 3


#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL],int row,int col);
void ComputerMove(char board[ROW][COL],int row,int col);
void PlayerMove2(char board[ROW][COL], int row, int col);
//����Ӯ--#
//���Ӯ--*
//����--C
//ƽ��--'Q'
char IsWin(char board[ROW][COL],int row,int col);
//1��ʾ��������
//0��ʾû����
int IsFull(char board[ROW][COL], int row, int col);