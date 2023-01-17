//本程序为迷宫求解
/*题目大概可以理解为在一个由许多个正方形组成的大正方形中，有一个起点和一个终点，而且有且只有
一条通道能从起点到终点,而且点的移动只能上下左右（一格）,由人工智能去找寻通路
'!'为怪物位置 '$'为走过的位置 有很大的bug存在！！！*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "wangjie.h"
#include <time.h>
#include <math.h>

#define MAXSIZE 10//可自行调整迷宫大小
typedef struct MiGon{
	char ch1[MAXSIZE][MAXSIZE];//迷宫的存在格子
	char ch2[MAXSIZE][MAXSIZE];//行走的格子
}migon;
migon *E;

void Monster(void);//设置怪物位置
void silu(void);//死路自行设置
void find_3(void);//找寻出路

int dd=0;

int main(void)
{
	int i=0, j=0;
	system("color F1");
	kaishi();
	system("pause");
	srand(time(0));
	E=(migon *)malloc(sizeof(migon));
	//初始化
	//初始化所有通道为可行通道
	for(i=0; i<MAXSIZE; i++){
		for(j=0; j<MAXSIZE; j++){
			E->ch1[i][j]='0';
			E->ch2[i][j]='0';
		}
	}
	printf("\n本程序已经初始化所有通道,我们的起点在左上角那个路口,终点在右下角那个格子\n");
	printf("路径上存在很多很多怪物,不能碰到怪物!否则淘汰\n");
	printf("路径上还有很多条死路\n");
	printf("求一条到终点的路径!!!\n");
	printf("接下来就请你先在每一行的三个怪物位置吧!\n");
	Monster();//生成怪物函数
	printf("\n **** 稍等片刻,程序将自动生成部分死路 **** \n");//死路用'1'表示,活路用'0'表示
	silu();//和前面的生成怪物随机的话一样的类似程序
	Sleep(1000);//休眠1秒
	printf("\n **** 接下来就请我们的系统帮助我们找到一条通路吧 **** \n");
	find_3();
	return 0;
}

void find_3(void)
{
	//默认向下移动，遇到错误就向右,再不行就返回
	//用E->ch2[][]来记录下行走的路径,走过的位置用'1'表示,没走过的地方用'0'表示
	int i=0, j=0, k=0, k1=0, k2=0, j1=0, i1=0;//k=1退出向右的程序
	char ch_3_1[2]={'*','\0'};
	char ch_3_2[2]={'!','\0'};
	char ch_3_3[2]={'#','\0'};
	//char ch3[MAXSIZE1][MAXSIZE1];
	//for(i=0; i<MAXSIZE1; i++)
	//	for(j=0; j<MAXSIZE1; j++)
	//	ch3[i][j]='\0';
	E->ch2[0][0]='1';//E->ch2是记录下移动位置的数组,所以自然起始位置也是为'1'
	//printf("1bug1\n"); //测试：正常输出  
	do{
	//罗技:先默认一个方向为初始移动方向
		//下移
		do{
			//printf("bug1\n");
			i++;
			if(i<=MAXSIZE-1 && E->ch1[i][j1] != '!'){//没碰到怪物且没有碰壁
				//printf("1bug2\n"); //测试：正常通过
				E->ch2[i][j1]='1';
				i1=i;
				//ch3[dd]="下";
				//strcpy(ch3[dd],"下");
				//dd++;
				if(i == MAXSIZE-1 && j1 == MAXSIZE-1)//是否到达终点判断
					k=1;
			}
			else//否则就回一步
			{
				i--;
				i1=i;
				k1=1;
			}
			if(i == MAXSIZE-1 && j1 == MAXSIZE-1)//是否到达终点判断
				k=1;
		}while(k1 != 1);
		//右移
		k1=0;//恢复
		do{
			//printf("1bug3\n"); //测试：会无限进行bug3
			j++;
			if(j<=MAXSIZE-1 && E->ch1[i1][j] != '!'){//没有碰到怪物且没碰壁
				E->ch2[i1][j]='1';
				j1=j;
				//ch3[dd]="右";
				i1++;//能往下了就不再往右
				//printf("bug4\n");//测试：未正常输出
				if(i1 <= MAXSIZE-1 && E->ch1[i1][j] != '!'){
					k2=1;
					i1--;
				}
				//	strcpy(ch3[dd],"右");
				//dd++;
				if(i1 == MAXSIZE-1 && j == MAXSIZE-1)//是否到达终点判断
					k=1;
			}
			else{
				j--;
				j1=j;
				k2=1;
			}
		}while(k2 != 1);
		if(i1 == MAXSIZE-1 && j1 == MAXSIZE-1)//是否到达终点判断
			k=1;
		if(E->ch1[i1+1][j1] == '!' && E->ch1[i1][j1+1] == '!')//角落处理
		{
			i1=i1-2;
			j++;
			j1++;
		}
		k2=0;//恢复
		dd++;
		if(dd == (int)pow(1000,2))
			k=1;
	}while(k !=1 );
	printf("\n路径为（*）:\n");
	for(i=0; i<MAXSIZE; i++)
		for(j=0; j<MAXSIZE; j++){
			if(E->ch2[i][j] == '1')//移动位置
				printf("%3s",ch_3_1);
				//printf("*");
			if(E->ch1[i][j] == '!')//怪物位置
				printf("%3s",ch_3_2);
				//printf("!");
			if(E->ch2[i][j] == '0')//空
				printf("%3s",ch_3_3);
				//printf("#");
			if((j+1) == MAXSIZE)
				printf("\n");
		}
		//	for(i=0; i<MAXSIZE1; i++){
		//	printf("%s\t",ch3[i]);
		//if((i+1)%10 == 0)
		//printf("\n");
		//}
		
}

void Monster(void)//人为选择每行3个的怪物的位置
{
	int i=0, j=0, choose_3, j1=0, j2=0, choose_4=0;
	printf("请问您是需要你本人来自行操作,还是由我们的程序来随机决定怪物位置? 1:是  2.不是");
	scanf("%d",&choose_4);
	if(choose_4 ==1){
	for(i=0; i<MAXSIZE; i++){
		while(j<3){
			printf("\n（从左往右）请输入第%d行第%d个为怪物位置:",i+1,j+1);
			scanf("%d",&choose_3);
			if(choose_3 <= MAXSIZE)
			{
				E->ch1[i][choose_3-1]='!';//标记怪物
				j++;
			}
			else
			{
				for(j2=0; j2<MAXSIZE; j2++)
					for(j1=0; j1<MAXSIZE; j1++)
						E->ch1[j2][j1]='0';
				printf("\n ****** 输入有误!请重新输入! ******\n");
				i=0;
				j=0;
			}
		}
		j=0;
	}
	}
	else{
		//
		for(i=0; i<MAXSIZE; i++){
			for(j=0; j<3; j++){
				E->ch1[i][rand()%MAXSIZE]='!';//从第一行开始向后面,每行三个怪物随机生成 有可能重叠,占时允许重叠
			}
		}
	}
	//将可能被玩家将起点、终点变成怪物的错误或随机时不故意的行为改正,使起点、终点可
	E->ch1[0][0]='0';
	E->ch1[MAXSIZE-1][MAXSIZE-1]='0';
}

void silu(void)
{
	//随机生成三个
	int i=0, a=0, b=0, c=0, j=0;
	for(i=0; i<MAXSIZE; i++){
		a=rand()%MAXSIZE;
		b=rand()%MAXSIZE;
		c=rand()%MAXSIZE;
		E->ch1[i][a]='!';//会有于前面发生重合的情况
		E->ch1[i][b]='!';
		E->ch1[i][c]='!';
	}
	//将可能被玩家将起点、终点变成怪物的错误行为改正
	/*for(i=0; i<MAXSIZE; i++)
		for(j=0; j<MAXSIZE; j++)
		{
			if(E->ch1[i][j] == '!' && i<MAXSIZE-1 && j<MAXSIZE-1)
				E->ch1[i+1][j-1]='0';
		}
	*/
	E->ch1[0][0]='0';
	E->ch1[1][0]='0';
	E->ch1[MAXSIZE-1][MAXSIZE-1]='0';
}