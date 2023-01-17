//教学计划编制问题
/*自然，专业分很多种,不同的专业可能就存在不同的学习班年限 （也就是说该专业只给哪些年级的人上）
一年=两学期 不同专业又有不同的课程 
假设每个学期的时间相等，学分相等 课程的先后顺序也不能乱了 ！！！ 
又假设没门课程只占一个学期 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "wangjie.h"

#define MAX 20

typedef struct Term{
	char course[MAX][MAX]; //每一行的储存一门课程
}term;
term subject[MAX];//代表专业


void menu(void);//显示大多数专业的种类
void menu_1(void);//显示大多数课程的种类
char* ForName(int i);//返回专业名称
char* ForName_1(int i);//返回课程名称
void look(void);//输出所有专业的情况


int main(void)
{
	int i=0, j=0, k=0, choose=0, choose_1=0;
	system("color F1");
	kaishi();
	system("pause");
	for(k=0; k<MAX; k++)
		for(i=0; i<MAX; i++)
			for(j=0; j<MAX; j++)
				subject[k].course[i][j]='\0';
			printf("欢迎来到教学计划编制问题程序,我们将帮助你!\n");
			printf("计算机类专业大概有以下:\n");
			menu();
			printf("接下来你拥有相当上帝一般的能力,你将决定该专业下需要学习哪些课程!\n");
			for(i=0; i<7; i++){
				printf("现在让我们从 **** 第%d个专业（%s） **** 开始:\n",i+1,ForName(i+1));
				printf("课程有:\n");
				menu_1();
				//……
				do{
					printf("你觉得他需要学有几门课程呢？请输入:");
					scanf("%d",&choose);
					if(choose <= 8){
						for(j=0; j<choose; j++){
							printf("请输入第%d门课程的代号:",j+1);
							scanf("%d",&choose_1);
							strcpy(subject[i].course[j],ForName_1(choose_1));
						}
					}
					else
						printf("输入有误!请重新输入!\n");
				}while(choose > 8);
			}
			printf("接下来输出所有专业的所有课程（顺序未变）\n");
			Sleep(1000);
			look();
			return 0;
}

void look(void)
{
	//
	int i=0, j=0;
	for(i=0; i<7; i++)
	{
		printf("第%d个专业（%s）:",i+1,ForName(i+1));
		printf("该门专业有以下课程:");
		for(j=0; j<MAX; j++)
		{
			//
			printf("%8s\t",subject[i].course[j]);
			if((j+1)%3 == 0)
				printf("\n");
		}
	}
}

void menu_1(void)
{
/*课程有:电子技术、离散数学、程序设计、数据结构、操作系统、计算机组成原理、微机系统、计算机系统结构、
编译原理、计算机网络、数据库系统、软件工程、人工智能、计算机图形学、数字图像处理、计算机通讯原理、
多媒体信息处理技术、数字信号处理、计算机控制、网络计算、算法设计与分析、信息安全
	、应用密码学基础、信息对抗、移动计算、数论与有限域基础、人机界面设计、面向对象程序设计*/
	printf("\n 1.电子技术     2.离散数学 ");
	printf("\n 3.程序设计     4.数据结构");
	printf("\n 5.操作系统     6.计算机组成原理");
	printf("\n 7.计算机网络     8.人工智能");
	printf("\n");
}

char* ForName_1(int i)
{
	//
	if(i == 1)
		return "电子技术";
	else if(i == 2)
		return "离散数学";
	else if(i == 3)
		return "程序设计";
	else if(i == 4)
		return "数据结构";
	else if(i == 5)
		return "操作系统";
	else if(i == 6)
		return "计算机组成原理";
	else if(i == 7)
		return "计算机网络";
	else if(i == 8)
		return "人工智能";
	else
		return "出现了未知错误!\n";
}

void menu(void)
{
	printf("\n 1.计算机科学于技术     2.自动化");
	printf("\n 3.信息安全     4.物联网工程");
	printf("\n 5.通信工程     6.数据科学");
	printf("\n 7.大数据技术     \n");
}

char* ForName(int i)
{
	if(i == 1)
		return "计算机科学于技术";
	else if(i == 2)
		return "自动化";
	else if(i == 3)
		return "信息安全";
	else if(i == 4)
		return "物联网工程";
	else if(i == 5)
		return "通信工程";
	else if(i == 6)
		return "数据科学";
	else if(i == 7)
		return "大数据技术";
	else
		return "出现了未知的错误";
}