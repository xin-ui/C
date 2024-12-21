#define _CRT_SECURE_NO_WARNINGS 1
//编写代码，模拟用户登录情景，并且只能登录三次，
//（只允许输入三次密码，如果密码正确则提示登录成功，
//如果三次均输入错误，则退出程序。
#include <string.h>
#include <stdio.h>
int main()
{
	int i = 0;
	char password[] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:>");
		scanf("%s", password);
		if (strcmp(password, "abcdef") == 0)//密码为abcdef
		{
			printf("登录成功\n");
			break;
		}
		else
		{
			printf("密码错误\n");
		}
	}
	if (i == 3)
	{
		printf("密码错误，退出程序\n");
	}
	return 0;
}