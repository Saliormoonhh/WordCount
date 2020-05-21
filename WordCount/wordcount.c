#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int CharCount(char* filename);  //字符统计函数
int WordCount(char* filename);  //单词统计函数



int CharCount(char* filename) //字符统计函数
{
	FILE* fp = fopen(filename, "r");
	int c = 0;
	char ch;
	if (fp == NULL)
	{
		printf("file read failure.");
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		c++;
		ch = fgetc(fp);
	}
	fclose(fp);
	return c;
}

int WordCount(char* filename) //单词统计函数
{
	FILE* fp;
	int w = 0;
	char ch;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("file read failure.");
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
		{
			while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_')
			{
				ch = fgetc(fp);
			}
			w++;
			ch = fgetc(fp);
		}
		else
		{
			ch = fgetc(fp);
		}
	}

	fclose(fp);
	return w;

}

int main(int argc, char* argv[])
{
	if ((strcmp(argv[1], "-c") == 0))
	{
		int a = CharCount(argv[2]);
		printf("字符数：%d", a);
	}

	if ((strcmp(argv[1], "-w") == 0))

	{
		int b = WordCount(argv[2]);
		printf("单词数：%d", b);
	}
	return 0;
}