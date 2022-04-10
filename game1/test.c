#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//菜单函数
void menu()
{
	printf("********************\n");
	printf("**1.PLAY***0.EXIT***\n");
	printf("********************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };//存放棋盘信息
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋循环
	while (1)
	{
		
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		//ComputerMove(board, ROW, COL);
		PlayerMove2(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家1赢\n");
	}
	else if (ret == '#')
	{
		printf("玩家2赢\n");
	}
	else
	{
		printf("平局\n");
	}


}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入你的选择\n");
		
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;

		}
	}while (input);
}
int main()
{
	test();
	return 0;
}