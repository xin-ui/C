#define _CRT_SECURE_NO_WARNINGS 1
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
//�ػ�����
//1.��������������1�����ڹػ�
//2.������룺NO����ȡ���ػ�

int main()
{
	char input[] = { 0 };
	system("shutdown -s -t 60");
again:
	printf("��ע�⣬��ĵ��Ի���60�����ڹػ���������룺NO����ȡ���ػ�\n");
	scanf("%s", input);
	if (strcmp(input, "NO") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}