#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wangjie.h"

struct STU1{//男
	char name1[20];//学校名称
	int grade1[20];//学校成绩 项目至多20种
};
struct STU1 stu1[100];

struct STU2{//女
	char name2[20];//学校名称
	int grade2[20];//学校成绩 项目至多20种
};
struct STU2 stu2[100];

int m=0, w=0, n=0;//m:男子比赛项目个数 w:女子比赛项目个数 n:参加学校的个数


void Gradewoman(int i);//女子项目成绩
void Grademan(int i);//男子项目成绩
void Create(void);//建立
void insert_sort(int *array,int length);//直接插入排序算法
void menu_1(void);//菜单
void paihang(void);
void SUM(void);//求各个学校的总分
void chazhao_1(void);//查找
void paihang_1(void);//学校排行

int main(void)
{
	int choose_1=0;
	system("color F1");
	kaishi();
	system("pause");
	do{
		menu_1();
		printf("请选择:");
		scanf("%d",&choose_1);
		switch(choose_1)
		{
		case 1:
			Create();
			break;
		case 2:
			paihang();
			break;
		case 3:
			SUM();
			break;
		case 4:
			chazhao_1();
			break;
		case 5:
			paihang_1();
			break;
		case 6:
			//退出
			printf("即将退出!\n");
			break;
		default :
			printf("输入有误!,请重新输入!\n");
		}
	}while(choose_1 != 6);
	return 0;
}

void paihang_1(void)
{
	int i=0, j=0, j1=0;
	int sum[20]={0}, sum1[20]={0}, sum2[20]={0};//函数数组下标c语言不允许写未知数哦!
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
			sum1[i]+=stu1[i].grade1[j];
		for(j1=0; j1<w; j1++)
			sum2[i]+=stu2[i].grade2[j];
		sum[i]=sum1[i]+sum2[i];
	}
	printf("每所学校的总分:\n");
	for(i=0; i<n; i++)
		printf("第%d所（%s）:%d\t",i+1,stu1[i].name1,sum[i]);
	insert_sort(sum,n);//直接插入排序算法
	printf("\n排行为\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t",sum[i]);
	}
	printf("\n");
}
void chazhao_1(void)
{
	int chengji[20], chengji1[20];
	int i=0, j=0, j1=0;
	char name_1[20];
	for(i=0; i<m; i++)//将所有学校的男子成绩放入到一个函数
	{
		for(j=0; j<n; j++){
			chengji[i]=stu1[j].grade1[i];
		}
	}
	for(i=0; i<w; i++)//与上同理
	{
		for(j=0; j<n; j++){
			chengji1[i]=stu2[j].grade2[i];
		}
	}
	printf("参加比赛的所有学校名称如下:");
	for(i=0; i<n; i++){
		printf("%s\t",stu1[i].name1);
		if((i+1)%4 == 0)
			printf("\n");
	}
	printf("\n请输入学校的名称:");
	getchar();
	scanf("%s",&name_1);
	for(i=0; i<n; i++)
	{
		if(strcmp(stu1[i].name1,name_1) == 0){
			printf("该校的男子,女子成绩为\n");
			//!!!!!!
			printf("男子:\n");
			for(j=0; j<m; j++)
			{
				printf("%d\t",stu1[i].grade1[j]);
			}
			printf("\n女子:\n");
			for(j1=0; j1<w; j1++)
			{
				printf("%d\t",stu2[i].grade2[j1]);
			}
			printf("\n");
		}
	}
}
void SUM(void)//求各个的学校总分
{
	int k1=0, k2=0, i=0, j=0;
	for(i=0; i<n; i++)
	{
		printf("第%d所学校的总分统计\n",i+1);
		int sum1=0, sum2=0;
		printf("该校的名称为:%s\n",stu1[i].name1);
		printf("该校男子成绩总和为:\n");
		for(k1=0; k1<m; k1++){
			printf("第%d项:\n",k1+1);
			for(j=0; j<m; j++)
			{
				sum1 += stu1[i].grade1[j];
			}
			printf("总和成绩为:%d\n",sum1);
		}
		printf("该校的女子成绩总和为:\n");
		for(k2=0; k2<w; k2++){
			printf("第%d项:\n",k2+1);
			for(j=0; j<w; j++)
			{
				sum2 += stu2[i].grade2[j];
			}
			printf("总和成绩为:%d\n",sum2);
		}
	}
}

void paihang(void)//输出各个学校的成绩排行
{
	int chengji[20], chengji1[20];
	int i=0, j=0;
	for(i=0; i<m; i++)//将所有学校的男子成绩放入到一个函数
	{
		for(j=0; j<n; j++){
			chengji[i]=stu1[j].grade1[i];
		}
	}
	for(i=0; i<w; i++)
	{
		for(j=0; j<n; j++){
			chengji1[i]=stu2[j].grade2[i];
		}
	}
	//
	printf("接下来输出男子的项目成绩排行\n");
	insert_sort(chengji,m);
	for(i=0; i<m; i++){
		printf("%d\t",chengji[i]);
	}
	//
	printf("\n");
	printf("接下来输出女子的项目成绩排行\n");
	insert_sort(chengji1,m);
	for(i=0; i<w; i++){
		printf("%d\t",chengji1[i]);
	}
	printf("\n");
}

void menu_1(void)
{
	printf(" 1.建立 2.成绩排行 \n");
	printf(" 3.成绩总和 4.查找 \n");
	printf(" 5.学校排行 6.退出\n");
}
void Create(void)
{
	int i=0, j=0;
	printf("请输入参加项目的学校个数:");
	scanf("%d",&n);
	printf("\n");
	printf("\n请输入男子比赛项目个数:");
	scanf("%d",&m);
	printf("\n");
	printf("\n请输入女子比赛项目个数:");
	scanf("%d",&w);
	printf("接下来请输入男子比赛每个队的成绩\n");
	for(j=0; j<n; j++)
	{
		printf("请输入第%d个学校的名称:",j+1);
		getchar();
		scanf("%s",&stu1[j].name1);
		stu2[j].name2[20]=stu1[j].name1[20];//同名传输
		printf("请再次输入该校的项目成绩\n");
		printf("*** 男子 ***\n");
		Grademan(j);
		printf("*** 女子 ***\n");
		Gradewoman(j);
	}	
}

void Grademan(int t)//男子项目成绩
{
	//
	int i=0;
	for(i=0; i<m; i++){
		printf("请输入第%d个项目的成绩:",i+1);
		scanf("%d",&stu1[t].grade1[i]);
		printf("\n");
	}
}

void Gradewoman(int t)//女子项目成绩
{
	int i=0;
	for(i=0; i<m; i++){
		printf("请输入第%d个项目的成绩:",i+1);
		scanf("%d",&stu2[t].grade2[i]);
		printf("\n");
	}
}

void insert_sort(int *array,int length)//直接插入排序算法
{
	//目的:按从小到大排序
	int i , j , temp;
	if(length <= 1)//小于等于1的长度也不需要排序了!
		return;
	for(i=1; i<length-1; i++){
		temp=array[i];
		j=i-1;
		while(j>=0 && temp<array[j]){//没有到达最头那个且后面的小于前面的数据时
			array[j+1]=array[j];
			--j;
		}
		array[j+1]=temp;//j在最后依然-1了,所以+1补上去
	}
}
