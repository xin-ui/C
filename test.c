#define _CRT_SECURE_NO_WARNINGS 1
//��������Ϸ
//���Բ��� һ���������1-100)
//������
//�´���
//��С��
//ֱ���¶��ˣ�����
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
void menu()
{
	printf("********************************\n");
	printf("***********   1. play   ********\n");
	printf("***********   2. exit   ********\n");
	printf("********************************\n");
}
void game()
{
	int guess = 0;
	//1,���������
	//%100  0-99
	int ret = rand() % 100 + 1;//����������ĺ���
	//printf("%d\n", ret);
	//2.������
	while (1)
	{
		printf("�������:>");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("��С��\n");
		}
		else  if (guess>ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
}
int main()
{
	printf("��ע������60���ӵ�ʱ����в����֣�60����֮������Զ��ػ����¶�����ȡ���ػ�\n");
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��(0/1):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//�����������߼�
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}