#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//初始化棋盘函数
void InitBoard(char board[ROW][COL], int row, int col)
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
//打印棋盘函数
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("___");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}printf("\n");
}

//玩家下棋函数
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家1走\n");
	while (1)
	{
		
		printf("请输入要下的坐标\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断坐标合法性
			if (board[x - 1][y - 1] ==' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
			 printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}


}
void PlayerMove2(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家2走\n");
	while (1)
	{

		printf("请输入要下的坐标\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断坐标合法性
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}


}

//电脑下棋函数
//void ComputerMove(char board[ROW][COL], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	printf("电脑走\n");
//	while (1)
//	{
//		x = rand() % 3;
//		y = rand() % 3;
//		if (board[x][y] == ' ')
//		{
//			board[x][y] = '#';
//			break;
//		}
//	}
//	
//}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for(j=0;j<col;j++)
			if (board[i][j] == ' ')
			{
				return 0;//没满
			}
	}
	return 1;//满了
}



//判断输赢函数
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}	
	}
	//竖三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//对角
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//判断是否平局
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}