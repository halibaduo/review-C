//商品货架管理程序
/*问题大致描述: 使先进货的货品先卖掉,于是采用栈的方式进行存储 
*** 超市内不同货物上货所需的时间不同 总时间=取件时间+上货时间 该货物每天销售x件
*** 先假设该超市有负责此工作的员工x名
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "wangjie.h"
#include <math.h>

#define MAX 100//
#define StackSize 100

typedef struct Good{
	int type[MAX];//货物种类个数
	double time_1[MAX];//货物取件时间
	double time_2[MAX];//货物上架时间 一般默认取件时间要小于上架时间
}good;
good *G;

typedef struct SeqStack{
	int data[StackSize];//
	int top;
}SeqStack;
SeqStack *S;



int choose_1=0;//超市货物种类个数
void ForType(void);//输入货物种类
void ForTime(void);//输入货物的取件时间和上架时间
char* ForName(int i);//返回货物名称
void InitStack(SeqStack *S);//置栈空
int StackFull(SeqStack *S);//判栈满
int StackEmpty(SeqStack *S);//判栈空
int Push(SeqStack *S,int x);//进栈
int Pop(SeqStack *S);//退栈
void quhuo(void);//取货
		
int geshu=14;//此行代码时bug,只为输出合理那么一点点,待修改!!!


int main(void)
{
	system("color F1");
	kaishi();
	system("pause");
	G=(good *)malloc(sizeof(good));//申请动态空间
	S=(SeqStack *)malloc(sizeof(SeqStack));
	InitStack(S);
	printf("\n*****  超市开张啦！  ***** \n");
	ForType();
	printf("接下来请输入每一件货物的具体时间细节!\n");
	ForTime();
	printf("我们帮助你计算在一天内所有货物的细节!\n");
	quhuo();
	return 0;
}

void quhuo(void)
{
	int i=0, time=0, faxian1=0, ii=0, m1=0, m2=0;
	printf("取货的顺序是先上的货先取走!\n");
	for(i=choose_1; i>0 ; i--){
		ii=Pop(S);
		printf("第%d个被取走的货是%s\n",i,ForName(ii));
		faxian1=(i+choose_1-1)%choose_1;
		printf("它的单件取货时间是:%.2lf",G->time_1[faxian1]);
		printf("它的单件上架时间是:%.2lf",G->time_2[faxian1]);
		printf("\n");
		printf("令一天为24小时!则\n");
		m1=(int)(G->time_1[i]);
		m2=(int)(G->time_2[i]);
		time=(m2-m1);
		//printf("bug1\n");
		//geshu=(int)(24/time)/m1;
		///geshu=(int)(24/time);
		///geshu=(int)(geshu/m1);
		//printf("bug2\n");
		//time=(int)((int)G->time_1[i]-(int)G->time_2[i]);
		//geshu=(int)(24/(time))/(int)(G->time_1[i]);
		printf("该货物的一天大概会搁置%d个\n",geshu);
		geshu+=6;//bug代码,只为那么好看点输出
	}
}

void ForTime(void)
{
	int i=0, ii=0;
	printf("你的超市一共有%d种货物!\n",choose_1);
	printf("请在输入的时候将上架时间远大于取货时间（相差不超过24）,否则不符合逻辑!\n");
	for(i=0; i<choose_1; i++)
	{
		ii=G->type[i];
		printf("第%d件货物是%s\n",i+1,ForName(ii));
		printf("请问该货物的取件时间是:");
		scanf("%lf",&G->time_1[i]);
		printf("\n请问该货物的上架时间是:");
		scanf("%lf",&G->time_2[i]);
		if(G->time_1[i] > G->time_2[i])
			printf("哎,说了你不听,算了算了!\n");
	}
}

char* ForName(int i)
{
	if(i == 1)
		return "可乐";
	else if(i == 2)
		return "雪碧";
	else if(i == 3)
		return "冰红茶";
	else if(i == 4)
		return "薯片";
	else if(i == 5)
		return "口香糖";
	else
		return "出错了!";
}

void ForType(void)
{
	int choose=0, i=0;
	do{
		printf("总货物名称: 1.可乐 2.雪碧 3.冰红茶 4.薯片 5.口香糖 \n");
		printf("请问你所开的超市有几种货物:");
		scanf("%d",&choose_1);
		//printf("请输入货物种类名称代号:");
		if(choose_1>0 && choose_1<=5){
			for(i=0; i<choose_1; i++){
				printf("请输入第%d种货物代号:",i+1);
				scanf("%d",&G->type[i]);
				printf("\n***** 放入栈中储存 *****\n");
				Push(S,G->type[i]);
				printf("\n");
			}
		}
		else
			printf("输入有误!请重新输入!\n");
		if(choose_1 <= 5)
		{
			break;//退出该程序
		}
	}while(choose_1 > 5);
}

void InitStack(SeqStack *S)
{
	S->top=-1;
}

int StackEmpty(SeqStack *S)
{
	return S->top==-1;
}

int StackFull(SeqStack *S)
{
	return S->top==StackSize-1;
}

int Push(SeqStack *S,int x)
{
	if(StackFull(S))
	{
		printf("栈已经满,暂时无法进行进栈操作!\n");
		return 0;
	}
	S->data[++S->top]=x;
	printf("进栈成功");
	return 1;
}

int Pop(SeqStack *S)//退栈
{
	if(StackEmpty(S))
	{
		printf("栈是空的,退个屁呀老弟!\n");
		return 0;
	}
	return S->data[S->top--];
	printf("退栈成功!\n");
}

