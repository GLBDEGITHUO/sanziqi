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
//电脑赢--#
//玩家赢--*
//继续--C
//平局--'Q'
char IsWin(char board[ROW][COL],int row,int col);
//1表示棋盘满了
//0表示没有满
int IsFull(char board[ROW][COL], int row, int col);