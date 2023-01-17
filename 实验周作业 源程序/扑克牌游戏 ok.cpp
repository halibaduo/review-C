//扑克牌游戏
//一共52张牌,默认正面向上,从1—52,作为基数，在所有牌中是该基数的倍数的牌号，就将牌翻面
//设置：为1：正面 为0：反面
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "wangjie.h"

#define MAX 53

typedef struct Pai{
	int num[MAX];//牌面
	//int num1[MAX][MAX];//牌大小 只看一维
}pai;
pai *P;

void youxi(void);//游戏开始
void look_1(void);//查看牌面朝上的牌还有哪些?

int jishu=2;

int main(void)
{
	int i=0;
	system("color F1");
	kaishi();
	system("pause");
	P=(pai *)malloc(sizeof(pai));
	//printf("bug1\n");
	for(i=1; i<=52; i++)
		P->num[i]=1;//全部先正面向上
	//printf("bug2\n");
	youxi();
	printf("此刻,还为正面的牌为:\n");
	look_1();
	return 0;
}

void youxi(void)//游戏开始的函数
{
	int i=0, j=0;
	do{
		for(j=1; j<=52; j++)
		{	
			if(jishu <= 52){
				if(j%jishu == 0)//找到是倍数的牌面
				{
					//printf("bug1\n");
					if(P->num[j] == 1)
						P->num[j]=0;
					if(P->num[j] == 0)
						P->num[j]=1;//也就是牌面换一换
				}
			}
		}
		jishu++;
	}while(jishu == 53);
}

void look_1(void)
{
	//
	int i=0, j=0;
	for(j=1; j<=52; j++)
	{
		if(P->num[j] == 1){//if条件为向上
			printf("%d\t",j);
			i++;
		}
		if(i%7 == 0)//7个一行
			printf("\n");
	}
	printf("\n");
}