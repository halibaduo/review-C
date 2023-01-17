//作业调度程序
/*职员有三种 1.经理 2.部门主管 3.职工 他们之间的联系全部由一个秘书来做(负责) 
他们三个做事之前都要向秘书打报告(提交申请),然后就是烦人的填表工作,
表中包含: 本人工名 任务号（每个任务号对应一份任务）  比如:策划、指示、建议、批复等
所有的这些全部用 **队列** 来处理,同时也需要最后生成一份文件*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "wangjie.h"

#define QueueSize 100
#define MAX 3

typedef struct Work{
	char task[MAX][MAX];//task[0]:经理 task[1]:部门经理 task[2]:职工
}Work;
Work W[MAX];

typedef struct cirQueue{
	int data[QueueSize];//一维全部为一,储存数组
	int rear;//尾指针
	int front;//头指针
	int count;//数量
}CirQueue;
CirQueue *Q;

void InitQueue(CirQueue *Q);//初始化队列
int QueueEmpty(CirQueue *Q);//判队列空
int QueueFull(CirQueue *Q);//判队列满
int EnQueue(CirQueue *Q,int x);//入队
int DeQueue(CirQueue *Q);//出队
void Anpai(void);//安排工作
char* ForName(int i);//工作名称
char* ForName_1(int i);//人员名称
char* ForWork();//输出工作种类

char kk[15]; //第一个位置记录经理工作,第二个位置记录部门经理工作,第三个位置记录职工的工作
char kk1[15];
char kk2[15];


int main(void)
{
	int i=0, j=0, chulai=0;
	//char str_1[20]={'\0'};
	system("color F1");
	kaishi();
	system("pause");
	Q=(CirQueue *)malloc(sizeof(CirQueue));
	for(i=0; i<QueueSize; i++)
		Q->data[i]=0;
	for(j=0; j<10; j++){
		kk[j]='\0';
		kk1[j]='\0';
		kk2[j]='\0';
		}
	InitQueue(Q);
	printf("本公司一共有四种人,但其中除了秘书,其他三人都是在秘书的安排下工作的!\n");
	printf("这余下的三种类分别是: 1.经理 2.部门经理 3.职工 \n");
	printf("他们的工作也大致可以分为4种!\n");
	printf("分别为: 1.策划 2.指示 3.建议 4.批复 \n");
	printf("本程序将让你来安排他们三人的工作,我们的系统秘书小姐姐将会帮助你完成!\n");
	Anpai();
	printf("所以他们三个的任务顺序是:\n");
	for(i=0; i<3; i++)
	{
		//strcpy(str_1,DeQueue(Q));
		chulai=DeQueue(Q);
		if(strcmp("经理",ForName_1(chulai)) == 0)
			printf("他（%s）的工作是:%s",ForName_1(chulai),kk);//就是因为少了3个%s就查了两个小时的bug,笑死了,呜呜呜呜,cao……
		else if(strcmp("部门经理",ForName_1(chulai)) == 0)
			printf("他（%s）的工作是:%s",ForName_1(chulai),kk1);
		else if(strcmp("职工",ForName_1(chulai)) == 0)
			printf("他（%s）的工作是:%s",ForName_1(chulai),kk2);
		printf("\n");
	}
	return 0;
}

void Anpai(void)
{
	//
	int i=0, choose=0, choose_1=0, d=0, yiqian=0;
	do{
		printf("请问你需要先安排谁的任务,（请输入代号1-3）:");
		scanf("%d",&choose_1);
		//i=choose_1-1;
		d++;
		printf("此刻请安排 %s 的工作!\n",ForName_1(choose_1));
		do{
			printf("请问它的工作是（请输入代号1-4）:");
			scanf("%d",&choose);
			if(choose == yiqian)
				d--;
			yiqian=choose;//储存上一个的代号
			printf("\n你选择的它的工作是:%s",ForName(choose));
			if(strcmp("经理",ForName_1(choose_1)) == 0)
				strcpy(kk,ForName(choose));//
			if(strcmp("部门经理",ForName_1(choose_1)) == 0)
				strcpy(kk1,ForName(choose));
			if(strcmp("职工",ForName_1(choose_1)) == 0)
				strcpy(kk2,ForName(choose));
			//printf("bug1\n"); //顺利通过
			strcpy(&W[i].task[i][0],ForName_1(choose));
			//printf("bug2\n"); //顺利通过
			EnQueue(Q,choose_1);
			printf("你可以重新安排任务,否则就请安排下一个人的任务!\n");
			for(i=1; i<=3; i++)
			if(i == choose_1)
				printf("\n %s的任务已经安排好了!",ForName_1(choose_1));
		}while(choose!=1 && choose!=2 && choose!=3 && choose!=4);
		
	}while(d != 3);
}

char* ForName_1(int i)
{
	if(i == 1)
		return "经理";
	else if(i == 2)
		return "部门经理";
	else if(i == 3)
		return "职工";
	else
		return " **** 出现未知错误 **** ";
}

char* ForName(int i)
{
	if(i == 1)
		return "策划";
	else if(i == 2)
		return "指示";
	else if(i == 3)
		return "建议";
	else if(i == 4)
		return "批复";
	else
		return " **** 出现未知错误 **** ";
}

void InitQueue(CirQueue *Q)
{
	Q->count=0;//数量初始化为零
	Q->front=Q->rear=0;
}

int QueueEmpty(CirQueue *Q)
{
	return Q->count==0;
}

int QueueFull(CirQueue *Q)
{
	return Q->count==QueueSize;//个数的确是对应数组下标的(定义时的)
}

int EnQueue(CirQueue *Q,int x)
{
	//
	//printf("要是我输出了,就是进入了队列!\n"); //顺利通过
	if(QueueFull(Q))
	{
		printf("队列已经满了,不好意思,已经无法在入队列了!\n");
		return 0;
	}
	//printf("bug1\n"); //顺利通过
	Q->count++;
	//strcpy(&Q->data[Q->rear],str);
	//printf("bug2\n");
	Q->data[Q->rear]=x;//数据进入
	Q->rear=(Q->rear+1)%QueueSize;
	//printf("bug3\n");
	printf("\n *** 入队成功 *** \n");
	return 1;
}

int DeQueue(CirQueue *Q)
{
	//char str_1[20]={'\0'};
	int temp=0;
	if(QueueEmpty(Q))
	{
		printf("\n队列为空,暂时无法进行出队操作 \n");
		return 1;//嘻嘻
	}
	Q->count--;
	//strcpy(str_1,Q->data[Q->front]);
	temp=Q->data[Q->front];
	Q->front=(Q->front+1)%QueueSize;
	return temp;
}