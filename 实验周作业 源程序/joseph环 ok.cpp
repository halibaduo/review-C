//joseph环 顺时针围坐一圈
//num[i][j]=0 :死 num[i][j]=1 :活
//一维为密码 二维合在一起为存活
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "wangjie.h"

#define MAX 20

typedef struct People{
	int num[MAX][MAX];//活人
	int num1;//总人数
	int num2[MAX];//密码
}people;
people *P;

void youxi(int d);

int main(void)
{
	int people1=0, i=0, mima=0, choose_1, j=0;
	system("color F1");
	kaishi();
	system("pause");
	P=(people *)malloc(sizeof(people));
	printf("一共有多少人,请输入:");
	scanf("%d",&people1);
	P->num1=people1;
	for(i=0; i<people1; i++)
		for(j=0; j<people1; j++)
			P->num[i][j]=1;//全活
	printf("每个人都有一个密码,那么就让我们来决定他们每一个人的手中密码吧!\n");
	for(i=0; i<people1; i++)
	{
		printf("请输入第%d个人的手中密码:",i+1);
		scanf("%d",&mima);
		printf("\n");
		P->num2[i]=mima;
	}
	printf("接下来让我们开始游戏!\n");
	printf("我们是上帝玩家,那我们来决定第一个上限值,请输入:");
	scanf("%d",&choose_1);
	printf("\n");
	choose_1=choose_1%people1;
	youxi(choose_1);
	return 0;
}

void youxi(int d)
{
	int i=0, j=0, k=0, chuqu=0, kk=0;
	for(i=0; i<MAX; i++)
	{
		P->num[d][i]=0;//符合条件的全退出
	}
	//printf("haha");
	j=P->num2[d];//密码用d储存,人已出局,将出局人手中的密码储存下来
	kk++;//退出游戏的人加一
	do{
		//
		//printf("bug1\n"); //无限循环了!!!
		j=j%(P->num1-kk);
		for(i=0; i<P->num1; i++)//开始寻找手中密码是此的人
		{
			if(i == j && P->num[i][0] != 0){//密码符合且没退出的人
				for(k=0; k<MAX; k++){
					P->num[i][k]=0;//符合条件的全出局
				}
				chuqu=1;
				j=P->num2[i];//留好该人的手中密码
			}
			if(P->num[i][0] == 0)
				j++;
			if(chuqu == 1)
			{
				chuqu=0;
				kk++;
				break;
			}
		}
	}while(kk != P->num1-1);//剩余最后一个人的条件 并不是全部退出，搞清楚老弟!!!
	for(i=0; i<P->num1; i++){
		for(j=0; j<P->num1; j++)
		{
			if(P->num[i][j] == 1){
				printf("最后留下的人是第%d个!\n",i+1);
				break;
			}
		}
	}
}