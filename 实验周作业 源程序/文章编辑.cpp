//文章编辑
//一个汉字两字节，最高位都是1,得出后还得/2
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "wangjie.h"
#include <math.h>
#include <string.h>

#define MAXSIZE_4 100 //可自行更改

int wenzi(char str[]);//文字数目
int shuzi(char str[]);//数字数目
int kongge(char str[]);//空格数目
int zimu(char str[]);//字母数目
int xunzhao(char str[], char ch);//寻找相同字母的个数
int xunzhao_1(char str[],char str1[]);//寻找字符串
void shanchu_1(char str[],char str2[]);//删除后,仍然前移

int main(void)
{
	int sum_4=0, sum_4_1=0, sum_4_2=0, sum_4_3=0, sum_4_4=0, sum_4_5=0, sum_4_6=0;
	char ch4_1;
	char str1[10]={'\0'}, str2[10]={'\0'};
	system("color F1");
	kaishi();
	system("pause");
	char str[MAXSIZE_4]={'\0'};//定义并初始化
	printf("请输入一串你想输入的东西:");
	gets(str);
	sum_4_1=wenzi(str);
	printf("该字符串中有%d个文字!\n",sum_4_1);
	sum_4_2=shuzi(str);
	printf("该字符串中有%d个数字!\n",sum_4_2);
	sum_4_3=kongge(str);
	printf("该字符串中有%d个空格!\n",sum_4_3);
	sum_4_4=zimu(str);
	printf("该字符串中有%d个字母!\n",sum_4_4);
	sum_4=sum_4_1+sum_4_2+sum_4_3+sum_4_4;;
	printf("该字符串中一共有%d字数!\n",sum_4);
	printf("请输入一个字母,我们帮你寻找在该程序中有多少个:");
	getchar();
	scanf("%c",&ch4_1);
	sum_4_5=xunzhao(str,ch4_1);
	if(sum_4_5 != 0)
		printf("该字符在其中有%d个!\n",sum_4_5);
	else
		printf("不存在!\n");
	printf("请输入一端字符串,我们帮助你寻找:");
	gets(str1);
	sum_4_6=xunzhao_1(str,str1);
	if(sum_4_6 != 0)
		printf("该字符串的起始位置在第%d个字母\n",sum_4_6);
	else
		printf("不存在!\n");
	printf("该字符串为%s\n",str);
	printf("请输入一段去删除:");
	gets(str2);
	shanchu_1(str,str2);
	return 0;
}

void shanchu_1(char str[], char str2[])
{
	int n=0, i=0, j=0, k=0;
	n=xunzhao_1(str,str2);
	k=strlen(str2);
	for(i=n-1,j=0; j<k  ; i++,j++)
	{
		str[i]=str[i+k];
	}
	printf("此刻的字符串为%s!\n",str);
}

int xunzhao_1(char str[], char str1[])
{
	//
	int i=0, j=0, m=1, n=0, j1=0, k=0;//m为相同字母个数
	for(i=0; str[i]; i++)
	{
		if(str[i] == str1[0])
		{
			j1=i;
			for(j=i+1,k=1; str1[j]; j++,k++)
			{
				if(str[j] == str1[k])
				{
					m++;
				}
				if(str[j] != str[k])
					break;
			}
		}
	}
	n=strlen(str1);
	if(n == m)
		return j1;
	else
		return 0;
}

int xunzhao(char str[],char ch)
{
	int xunzhao1=0, i=0;
	for(i=0; str[i]; i++)
	{
		if(str[i] == ch)
			xunzhao1++;
	}
	return xunzhao1;
}

int wenzi(char str[])
{
	int wenzi1=0, i=0;
	for(i=0; str[i]; i++)
	{
		if(str[i] < 0 )//最高位为1(负数),两个字节
			wenzi1++;
	}
	wenzi1=wenzi1/2;
	return wenzi1;
}

int shuzi(char str[])
{
	int shuzi1=0, i=0;
	for(i=0; str[i]; i++)
	{
		if(str[i]>='0' && str[i]<='9')
			shuzi1++;
	}
	return shuzi1;
}

int zimu(char str[])
{
	int zimu1=0, i=0;
	for(i=0; str[i]; i++)
	{
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			zimu1++;
	}
	return zimu1;
}

int kongge(char str[])
{
	int kongge1=0, i=0;
	for(i=0; str[i]; i++)
	{
		if(str[i] == ' ')
			kongge1++;
	}
	return kongge1;
}