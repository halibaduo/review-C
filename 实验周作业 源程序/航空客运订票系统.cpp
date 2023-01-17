#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "wangjie.h"

#define MAX 20

typedef struct Plane{
	//
	char destination[MAX][MAX];//终点站 用一维去存储
	int flightnumber;//航班号
	int airplanenumber;//飞机号
	int time;//飞行时间(int)
	int ridenumber;//乘坐定额 满为20
	int ticket;//余票量
}plane;
plane P[MAX];//航班

struct People{
	char name[MAX][MAX];//一维来储存
	int flightnumber_1;//航班号
	int grade;//等级 1对应总统套间
};
struct People people[MAX];//人的信息


int choose=0;
char* ForTime(int i);//输出星期
char* ForName(int i);//级别
void menu(void);//输出飞机号


int main(void)
{
	/*终点站名、航班号、飞机号、飞行周日（星期几）、
	乘员定额、余票量、已订票的客户名单（包括名字、订票量、舱位等级1、2、3）以及等候替补的客户名单；*/
	int i=0, j=0, choose_1=0, choose_2;
	int jixia=0, k=0;
	char str[10];
	system("color F1");
	kaishi();
	system("pause");
	//P=(plane )malloc(sizeof(plane));
	//people=(People *)malloc(sizeof(People));
	for(i=0; i<MAX; i++)//初始化,下同
		for(j=0; j<MAX; j++)
			P->destination[i][j]='\0';
	//
	for(i=0; i<MAX; i++)
		P[i].ticket=0;
	printf("接下来让我们开始设置航班的细节!\n");
	printf("请问该飞机场一共有多少航班:");
	scanf("%d",&choose);
	for(i=0; i<choose; i++)
	{
		printf("接下来开始处理第%d艘航班的信息!\n",i+1);
		printf("它的终点站是:");
		getchar();
		gets(P[i].destination[i]);
		printf("它的航班号是:");
		scanf("%d",&P[i].flightnumber);
		printf("它的飞机号是:");
		scanf("%d",&P[i].airplanenumber);
		printf("该航班的开始飞行时间是（1为星期一，类推）:");
		scanf("%d",&P[i].time);
		printf("它的乘坐定额是（<20）:");
		scanf("%d",&P[i].ridenumber);
	}
kaitou:
	printf("接下来假设你是一名乘客,你前去买票!(一共三个人)\n");
	for(i=0; i<3; i++){
		printf("先生,您好,请问你的贵姓:");
		getchar();
		gets(people[i].name[0]);
		printf("请问您需要乘坐哪号飞机,请输入该飞机的航班号:");
		menu();
		printf("请输入:");
		scanf("%d",&choose_1);
		for(j=0; j<choose; j++)
		{
			if(P[j].flightnumber == choose_1)
			{
				people[i].flightnumber_1=P[j].flightnumber;//航班号存入,后面使用这个查找航班号的哦！！！
				printf("\n请输入您需要搭乘的级别（1-3）:");
					scanf("%d",&choose_2);
				if(choose_2>=1 && choose_2<=3)
					people[i].grade=choose_2;
				else{
					printf("哎呀,算了,喜欢乱输入,那你就乘坐高级的3吧！反正也不是花我的钱,hahaha\n");
					people[i].grade=3;
				}
				printf("先生,已经为你办理好了,该航班于%s早上10点起飞!，票您拿好\n",ForTime(P[j].time));
				P[j].ticket++;
				break;
			}
			else if(j==choose){
				printf("不好意思先生,没有找到你所说的的航班号,请您查看清楚后再办理!\n");
				goto kaitou;
			}
		}
		printf("\n *** 第%d个模拟身份信息录入完成! *** \n",i+1);
	}
	printf("请问需要我们告诉你所有人的航班信息吗？(yes or no):");
	getchar();
	gets(str);
	if(strcmp(str,"yes") == 0 || strcmp(str,"YES") == 0)
	{
		//
		for(i=0; i<3; i++)
		{
			printf("第%d人的信息如下:\n",i+1);
			printf("\n姓名:%s",people[i].name);
			printf("\n乘坐级别:%s",ForName(people[i].grade));
			//for(j=0; j<choose; j++){
			for(k=0; k<MAX; k++)//其实此处的MAX可以改为3,但其实吧,总体来说还是MAX更好
			{
				if(P[k].flightnumber == people[i].flightnumber_1 )
					jixia=k;
			}
			//}
			printf("\n终点站:%s",P[jixia].destination[jixia]);
			printf("\n航班号:%d",P[jixia].flightnumber);
			printf("\n飞机号:%d",P[jixia].airplanenumber);
			printf("\n飞行时间:%s",ForTime(P[jixia].time));
			printf("\n乘坐定额:%d",P[jixia].ridenumber);
			printf("\n该航班余票量:%d",(P[jixia].ridenumber-P[jixia].ticket));
			printf("\n");
		}
	}
	else{
		printf("本程序马上即将退出,祝您生活愉快!");
		Sleep(2000);
		exit(0);
	}
	return 0;
}

char* ForName(int i)
{
	if(i == 1)
		return "初级";
	else if(i == 2)
		return "中级";
	else if(i == 3)
		return "高级";
	else
		return "出现未知错误";
}

char* ForTime(int i)//输出星期
{
	//1代表星期一,类推
	if(i == 1)
		return "星期一";
	else if(i == 2)
		return "星期二";
	else if(i == 3)
		return "星期三";
	else if(i == 4)
		return "星期四";
	else if(i == 5)
		return "星期五";
	else if(i == 6)
		return "星期六";
	else if(i == 7)
		return "星期天";
	else
		return "有误!请小心行事";
}

/*代码所写人:王杰*/

void menu(void)
{
	int i=0;
	printf("当前航班号有:\n");
	for(i=0; i<choose; i++)
	{
		printf("%5d\t",P[i].flightnumber);
		if((i+1)%4 == 0)
			printf("\n");
	}
	printf("\n");
}