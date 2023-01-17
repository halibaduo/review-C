//利用随机数产生来决定移动的方向
//代码是越健壮越好
//写两个栈 一个栈储存一维数 另外一个栈储存二维数
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "wangjie.h"

#define MAX 10//迷宫长宽大小
#define MAX1 200
#define random(i) (rand()%i)

typedef struct Maze{ //结构体——迷宫
	int maze[MAX][MAX]; //左上角为起点 右下角为终点 
}maze;
maze *M;

typedef struct Stack{ //栈number1
	int top;
	int use[MAX1];
}stack;
stack *S;

typedef struct ZhonZi{
	long zhonzi;
}Zhonzi;
Zhonzi *Z;

typedef struct Stack1{ //栈number2
	int top1;
	int use1[MAX1];
}stack1;
stack1 *S1;
struct timespec {//需要手写加入
	time_t   tv_sec;        /*  秒 seconds */
	long     tv_nsec;       /* 纳秒，10-9秒 nanoseconds */
};

void Create(void);//迷宫生成
void Solve(void);//迷宫求解
void InitStack(void);//栈的初始化
int StackEmpty(stack *S);//判栈空
int StackFull(stack *S);//判栈满
int Push(stack *S,int m);//进栈
int Pop(stack *S);//出栈
//下面为栈number2的函数
int StackEmpty1(stack1 *S1);//判栈空
int StackFull1(stack1 *S1);//判栈满
int Push1(stack1 *S1,int m);//进栈
int Pop1(stack1 *S1);//出栈


int main(void)
{
	int i0=0, j0=0;
	int i=0, j=0;
	Z->zhonzi=0;//初始化
	system("color F1");
	kaishi();
	system("pause");
	M=(maze *)malloc(sizeof(maze));//申请动态空间
	S=(stack *)malloc(sizeof(stack));//为栈申请动态空间
	Z=(Zhonzi *)malloc(sizeof(Zhonzi));//为种子的结构体申请动态空间
	S1=(stack1 *)malloc(sizeof(stack1));//为栈number2申请动态空间
	InitStack();//此初始化可以将两个栈都初始化
	for(i0=0; i0<MAX; ++i0)
		for(j0=0; j0<MAX; ++j0)
			M->maze[i0][j0]=0;//全部初始化为空位 1为墙位
		printf("欢迎来到迷宫求解程序,我们将为你找到最佳路径\n");
		Create();
		printf("空位:口 墙位:! 此时的迷宫为:\n");
		M->maze[0][0]=0;
		M->maze[MAX-1][MAX-1]=0;//起点终点为空 以防被弄为墙
		for(i=0; i<MAX; i++){
			for(j=0; j<MAX; j++){
				if(M->maze[i][j] == 0)//空位
					printf("口");
				if(M->maze[i][j] == 1)//墙位
					printf("!");
				printf("\t");
				if(j == (MAX-1))//到达一行的末尾就换行
					printf("\n\n");
			}		
		}
		Solve();
		printf("空位:口 墙位:! 路径:$ 路径为:\n");
		for(i=0; i<MAX; ++i){
			for(j=0; j<MAX; j++){
				if(M->maze[i][j] == 0)//空位
					printf("口");
				else if(M->maze[i][j] == 1)//墙位
					printf("!");
				else if(M->maze[i][j] == 2)//路径位
					printf("$");
				printf("\t");
				if(j == (MAX-1))//到达一行的末尾就换行
					printf("\n\n");	
			}
		}
		return 0;
}

void Create(void)//迷宫生成
{
	//
	int ok=1, ok0=1;//用于输入失误时
	while(ok == 1){
		for(int i=0; i<MAX; ++i){
			int geshuqiang=0;
			printf("请输入第%d行有多少个墙位:",i+1);
			scanf("%d",&geshuqiang);
			if(geshuqiang < MAX && geshuqiang != 0){//判断是否可行
				if(i == (MAX-1))
					ok=0;//可行即为正确输入直至最后一行了 不像后面的,这个不需要恢复
				while(ok0 == 1){
					printf("再请依次输入第%d行墙的位序号 序号从左往右 ( 1-%d ) :",i+1,MAX);
					for(int j=0; j<geshuqiang; ++j){
						int k=0;
						scanf("%d",&k);
						if(k>0 && k<=MAX){
							M->maze[i][k-1]=1;
							ok0=0;
						}
						else{
							printf("输入有误,请重新输入!\n");
							break;
						}
					}
				}
				ok0=1;//恢复 毕竟极大可能还有下一波
			}
			else if(geshuqiang == 0){
				printf("");
				if(i == (MAX-1))
					ok=0;//可行即为正确输入直至最后一行了 不像后面的,这个不需要恢复
			}
			else{
				printf("\n输入有误,请全部重新输入!\n");
				break;
			}
		}
	}
}

void Solve(void)//尝试使用随机数决定方向的方式去走
//网上大部分教程都是 规定好沿着某一方向前进,遇到阻碍物才转向
{
	//提醒: 1为墙位 0为空位 新增2 为移动位
	int choose=1;
	int direction=0;
	int k1=0, k2=0;
	int ji1=0,ji2=0;//记录下上一个位置
	struct timespec time1 = { 0, 0 };
	M->maze[k1][k2]=2;//此时为起点位
	M->maze[MAX-1][MAX-1]=0;
	Push(S,0);
	Push1(S1,0);
	do{	
		srand(time1.tv_nsec);//返回值0左 1右 2上 3下 NULL可写0
		//Z->zhonzi++;//通过改变种子的大小使得方向能够不循环
		direction=rand()%4;// (int)[0,4)  c语言是返回整数型,但是java是返回double型
		if(direction == 0){//向左
			if((k2-1) >= 0 && M->maze[k1][k2-1] != 1 && M->maze[k1][k2-1]){//条件:没碰墙且未出界且未走过
				if((k1 == ji1 && (k2-1) != ji2) || ((k2-1) == ji2 && k1 != ji1) || (k1 != ji1 && (k2-1) != ji2)){//不得重复
					choose=0;//用于后面跳过退步操作
					ji1=k1; ji2=k2;
					k2=k2-1;
					M->maze[k1][k2]=2;//标记移动位
					if(!StackFull(S))//如果栈没满就进栈储存
						Push(S,k1);
					if(!StackFull1(S1))
						Push1(S1,k2);
				}
				else
					choose=0;
			}
		}
		else if(direction == 1){//向右
			if(M->maze[k1][k2+1] != 1 && (k2+1)<=(MAX-1) && M->maze[k1][k2+1] != 2){//条件:没碰墙且未出界且未走过
				if((k1 == ji1 && k2+1 != ji2) || (k2+1 == ji2 && k1 != ji1) || (k2+1 != ji2 && k1 != ji1)){//不得重复
					choose=0;//用于后面跳过退步操作
					ji1=k1; ji2=k2;
					k2=k2+1;
					M->maze[k1][k2]=2;//标记移动位
					if(!StackFull(S))//如果栈没满就进栈储存
						Push(S,k1);
					if(!StackFull1(S1))
						Push1(S1,k2);
				}
				else
					choose=0;
			}
		}
		else if(direction == 2){//向上
			if(k1-1 >= 0 && M->maze[k1-1][k2] != 1 && M->maze[k1-1][k2] != 2){//条件:没碰墙且未出界且未走过
				if((k1-1 == ji1 && k2 != ji2) || (k1-1 != ji1 && k2 == ji2) || (k1-1 != ji1 && k2 != ji2)){//不得重复
					choose=0;//用于后面跳过退步操作
					ji1=k1; ji2=k2;
					k1=k1-1;
					M->maze[k1][k2]=2;
					if(!StackFull(S))//如果栈没满就进栈储存
						Push(S,k1);
					if(!StackFull1(S1))
						Push1(S1,k2);
				}
				else
					choose=0;
			}
		}
		else if(direction == 3){//向下
			if(M->maze[k1+1][k2] != 1 && (k1+1)<=(MAX-1) && M->maze[k1+1][k2] != 2){//条件:没碰墙且未出界且未走过
				if((k1+1 != ji1 && k2 == ji2) || (k1+1 == ji1 && k2 != ji2) || (k1+1 != ji1 && k2 != ji2)){//不得重复
					choose=0;//用于后面跳过退步操作
					ji1=k1; ji2=k2;
					k1=k1+1;
					M->maze[k1][k2]=2;
					if(!StackFull(S))//如果栈没满就进栈储存
						Push(S,k1);
					if(!StackFull1(S1))
						Push1(S1,k2);
				}
				else
					choose=0;
			}
		}
		else
			printf("");//否则啥也不是就玩一下
		if(choose == 1){//暂且只能回退一位 上面的四个if都不成立的话进入 则choose=1
			M->maze[k1][k2]=0;//改回空位 本位归零
			//printf("进行到我这一步了!\n");                                            //这一步无缘无故不断进行 !!!!!!!!!
			//k1=ji1; k2=ji2;
			//printf("k1=%d,k2=%d \n",k1,k2);
			//system("pause");
			if(!StackEmpty(S))//利用栈的后进先出
				k1=Pop(S);
			if(!StackEmpty1(S1))
				k2=Pop1(S1);
			if(k1==0 && k2==0 && S->top == -1 && S1->top1 == -1){//返回至了原点
				Push(S,k1);
				Push1(S1,k2);
			}
			//Sleep(1000);
		}
		choose=1;//恢复 用于下次判断
	}while(M->maze[MAX-1][MAX-1] != 2);//条件:已到达终点
	M->maze[0][0]=2;
}

void InitStack(void)
{
	S->top=-1;//初始化数组下标为-1
	S1->top1=-1;//初始化栈number的数组下标为-1
}
int StackEmpty(stack *S)//判栈空
{
	return S->top==0;//是空的话就返回1 否则返回0
}
int StackFull(stack *S)//判栈满
{
	return S->top==MAX1-1;//是满的话就返回1 否则返回0
}
int Push(stack *S,int m)//进栈
{
	//
	if(StackFull(S)){
		printf("栈已满,请自行增大栈的容量!\n");
		return 0;
	}
	S->use[++S->top]=m;
	return 1;
}
int Pop(stack *S)//出栈
{
	int fanhui=0;
	if(StackEmpty(S)){
		printf("栈为空,无法进行出栈操作!\n");
		return 0;
	}
	fanhui=S->use[S->top--];
	return fanhui;//将该值返回
}
//下面为栈number2的函数说明
int StackEmpty1(stack1 *S1)//判栈空
{
	return S1->top1==0;//是空的话就返回1 否则返回0
}
int StackFull1(stack1 *S1)//判栈满
{
	return S1->top1==MAX1-1;//是满的话就返回1 否则返回0
}
int Push1(stack1 *S1,int m)//进栈
{
	//
	if(StackFull1(S1)){
		printf("栈已满,请自行增大栈的容量!\n");
		return 0;
	}
	S1->use1[++S1->top1]=m;
	return 1;
}
int Pop1(stack1 *S1)//出栈
{
	int fanhui=0;
	if(StackEmpty1(S1)){
		printf("栈为空,无法进行出栈操作!\n");
		return 0;
	}
	fanhui=S1->use1[S1->top1--];
	return fanhui;//将该值返回
}

