#define _CRT_SECURE_NO_WARNINGS 1
//��д���룬ģ���û���¼�龰������ֻ�ܵ�¼���Σ�
//��ֻ���������������룬���������ȷ����ʾ��¼�ɹ���
//������ξ�����������˳�����
#include <string.h>
#include <stdio.h>
int main()
{
	int i = 0;
	char password[] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("����������:>");
		scanf("%s", password);
		if (strcmp(password, "abcdef") == 0)//����Ϊabcdef
		{
			printf("��¼�ɹ�\n");
			break;
		}
		else
		{
			printf("�������\n");
		}
	}
	if (i == 3)
	{
		printf("��������˳�����\n");
	}
	return 0;
}