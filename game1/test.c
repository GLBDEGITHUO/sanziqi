#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//�˵�����
void menu()
{
	printf("********************\n");
	printf("**1.PLAY***0.EXIT***\n");
	printf("********************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };//���������Ϣ
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����ѭ��
	while (1)
	{
		
		//�������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
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
		printf("���1Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("���2Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}


}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("���������ѡ��\n");
		
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������������������\n");
			break;

		}
	}while (input);
}
int main()
{
	test();
	return 0;
}