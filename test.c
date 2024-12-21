#define _CRT_SECURE_NO_WARNINGS 1
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
//关机程序
//1.电脑运行起来后，1分钟内关机
//2.如果输入：NO，就取消关机

int main()
{
	char input[] = { 0 };
	system("shutdown -s -t 60");
again:
	printf("请注意，你的电脑会在60秒钟内关机，如果输入：NO，就取消关机\n");
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