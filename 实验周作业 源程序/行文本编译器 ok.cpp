#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include "wangjie.h"

#define MAX 50

char filename[MAX];//储存文件名
typedef struct File{
	char name[MAX];//姓名
	char grade[MAX];//成绩
	char sex;//性别,m为男,w为女
	//
}File;
File F[MAX];
File F1[MAX];//用于验证是否成功将F中的数据中转文件到F1中
//这是不用申请动态空间的,像这里如果用指针的话就是需要申请动态空间的
int people=0;

void Setup(void);//设计文件内容

int main(void)//主函数不易太复杂,否则不利于维护和扩展
{
	int i=0, j=0;
	system("color F1");
	kaishi();
	//初始化
	for(i=0; i<MAX; i++)
	for(j=0; j<MAX; j++){
		F[i].grade[j]='\0';
		F[i].name[j]='\0';
		F1[i].grade[j]='\0';
		F1[i].name[j]='\0';
	}
	system("pause");
	FILE *fp;
	printf("我们现在可以创建一个文件,请你来决定这个文件的名称!请输入你的选择（尾缀.dat）:");
	gets(filename);
	fp=fopen(filename,"w+");//读写打开filename文件 fp文件指针指向 文件的首地址 由fopen函数返回
	if(fp == NULL)
	{
		printf("文件打开失败!\n");
		exit(0);
	}
	else
	{
		//
		printf("文件已经成功打开!那么我们现在就开始设计文件内容吧!\n");
		Setup();
		rewind(fp);//完成后才开始进行后序操作
		//fprintf(fp,"\n");
		fprintf(fp,"成员信息如下:\n");
		fprintf(fp,"姓名:\t\t\t成绩:\t\t\t性别:\n");
		for(i=0; i<MAX; i++){//尝试将所有的数据读入
			fwrite(&F[i],sizeof(struct File),1,fp);// size*count
			fprintf(fp,"\n");
		}
		printf("输入文件中成功!\n");
		printf("接下来我们查看一下文件中的数据\n");
		//rewind(fp);//使文件指针指回头部
		fseek(fp,0,SEEK_SET);//运用此行代码代替上行代码 同功能
		fread(&F1[0],sizeof(struct File),1,fp);
		for(i=0; i<people; i++)
		{//此后继代码可以采用F1,但是需将自加的fprintf,与换行代码删除掉
			printf("第%d个人的姓名:%s",i+1,F[i].name);
			printf("\n第%d个人的考试成绩:%s",i+1,F[i].grade);
			printf("\n第%d个人的性别是:",i+1);
			if(F[i].sex == 'm'  || F[i].sex == 'M')
				printf("男\n");
			else if(F[i].sex == 'w' || F[i].sex == 'W')//注意:这里不能连写两个if 需加上else 否则else语句将异常输出
				printf("女\n");
			else
				printf("!**** 出现错误 ****!\n");
			printf("\n\n");
		}
	}
	fclose(fp);
	return 0;
}


void Setup(void)
{
	int i=0, j=0;
	printf("请输入文件中一共需要存储多少人:");
	scanf("%d",&people);
	for(i=0; i<people; i++)
	{
		//
		printf("请输入第%d人的姓名:",i+1);
		//scanf("%s",F[i]->name); //记住自己的错误!!!
		getchar();//注意这一行的getchar()与后面的getchar(),只有这一行的getchar()需要加入
		//fflush(stdin);
		gets(F[i].name);
		printf("\n请输入第%d个人的考试成绩:",i+1);//暂且发现储存的只有两位数的后一位,也就是第一位是不储存的,未读取的
		//getchar(); //本行的getchar()使得第一个字符被回车取代
		gets(F[i].grade);
		//scanf("%s",F[i].grade);
		//printf("\n !!! 刚刚读取的数为%s !!! \n",F[i].grade); //验证bug代码
		printf("\n请输入第%d个人的性别（m:男 or w:女）:",i+1);
		scanf("%c",&F[i].sex);
		printf("\n ***** 第%d个人的信息录制完成! *****\n",i+1);
	}
}