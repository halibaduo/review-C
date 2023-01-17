/*一元多项式的计算*/
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include "wangjie.h"

struct SHU{
	double xishu[10];
	double zhishu[10];
};
struct SHU shu[20];
struct SHU2{
	double xishujia[10];
	double zhishujia[10];
	double xishujian[10];
	double zhishujian[10];
};
struct SHU2 shu_2;

void Create_2(void);//创建一元多项式
void menu_2(void);//菜单
void jiade(void);//相加
void jiande(void);//相减

int main(void)
{
	int choose_2=0, i=0, j=0;
	system("color F1");
	kaishi();
	system("pause");
	//初始化为0
	for(i=0; i<20; i++){
		for(j=0; j<10; j++){
			shu[i].xishu[j]=0.0;
			shu[i].zhishu[j]=0.0;
			shu_2.xishujia[j]=0.0;
			shu_2.xishujian[j]=0.0;
			shu_2.zhishujia[j]=0.0;
			shu_2.zhishujian[j]=0.0;
		}
	}
	do{
		printf("请选择:\n");
		menu_2();
		scanf("%d",&choose_2);
		switch(choose_2)
		{
		case 1:
			Create_2();
			break;
		case 2:
			//
			jiade();
			break;
		case 3:
			//
			jiande();
			break;
		case 4:
			printf("即将退出!\n");
			Sleep(1000);
			break;
		default :
			printf("输入有误!请重新输入!\n");
		}
	}while(choose_2 != 4);
	return 0;
}
void jiande(void)//相减
{
	int xushu=0, i=0, j=0, xushu1=0, m1=0, m2=0;
	printf("（形如a1x^3+a2x^2）,请选择相加的前一个一元多项式为第几个?\n");
	printf("请输入序数:");
	scanf("%d",&xushu);
	printf("该一元多项式为:");
	for(i=0; i<20; i++){
		for(j=0; j<10; j++){
			if(shu[i].xishu[j] != 0 && (i+1) == xushu && shu[i].xishu[j] != 1)
				printf("%.2lf",shu[i].xishu[j]);
			if(shu[i].zhishu[j] != 0 && (i+1) == xushu)
				printf("x^");
			if(shu[i].zhishu[j] != 0 && (i+1) == xushu)
				printf("%.2lf",shu[i].zhishu[j]);
			if(shu[i].xishu[j+1] > 0 && j+1<10 && (i+1) == xushu)
				printf("+");
		}
	}
	//
	printf("（形如a1x^3+a2x^2）,请选择相加的后一个一元多项式为第几个?\n");
	printf("请输入序数:");
	scanf("%d",&xushu1);
	printf("该一元多项式为:");
	for(i=0; i<20; i++){
		for(j=0; j<10; j++){
			if(shu[i].xishu[j] != 0.0 && (i+1) == xushu1 && shu[i].xishu[j] != 1)
				printf("%.2lf",shu[i].xishu[j]);
			if(shu[i].zhishu[j] != 0.0 && (i+1) == xushu1)
				printf("x^");
			if(shu[i].zhishu[j] != 0.0 && (i+1) == xushu1)
				printf("%.2lf",shu[i].zhishu[j]);
			if(shu[i].xishu[j+1] > 0.0 && j+1<10 && (i+1) == xushu1)
				printf("+");
		}
	}
	m1=xushu-1;
	m2=xushu1-1;
	printf("相减后:\n");
	//int mama=0;
	int baba=0;
	for(j=0; j<10; j++){
		//为了方便是有些浪费空间的
		for(i=0; i<10; i++){
			if(shu[m1].zhishu[i] == shu[m2].zhishu[j] && shu[m1].zhishu[i] != 0.0){
				shu_2.xishujian[baba]=shu[m1].xishu[i]-shu[m2].xishu[j];
				shu_2.zhishujian[baba]=shu[m1].zhishu[i];
				baba++;
			}
			//shu_2.zhishujia[j]=shu[xushu].zhishu[j]-shu[xushu1].zhishu[j];
			else if(shu[m1].xishu[i] == 0.0 && shu[m2].xishu[j] != 0.0)
			{
				shu_2.xishujian[baba]=shu[m2].xishu[j];
				shu_2.zhishujian[baba]=shu[m2].zhishu[j];
				baba++;
			}
			else if(shu[m1].xishu[i] != 0.0 && shu[m2].xishu[j] == 0.0){
				shu_2.xishujian[baba]=shu[m1].xishu[i];
				shu_2.zhishujian[baba]=shu[m1].zhishu[i];
				baba++;
			}
		}
	}
	for(j=0; j<10; j++)
	{
		if(shu_2.xishujian[j] != 0.0 && shu_2.xishujian[j] != 1)
			printf("%.2lf",shu_2.xishujian[j]);
		if(shu_2.zhishujian[j] != 0.0 && shu_2.xishujian[j] != 0.0 && shu_2.zhishujian[j] != 1)
			printf("x^");
		if(shu_2.zhishujian[j] != 0.0 && shu_2.xishujian[j] != 0.0 && shu_2.zhishujian[j] != 1)
			printf("%.2lf",shu_2.zhishujian[j]);
		if(shu_2.xishujian[j+1] != 0.0 && j+1<10 && shu_2.zhishujian[j+1] != 0.0)
			printf("+");
	}
	printf("\n");
}

void jiade(void)//相加
{
	int xushu=0, i=0, j=0, xushu1=0, m1=0, m2=0;
	printf("（形如a1x^3+a2x^2）,请选择相加的前一个一元多项式为第几个?\n");
	printf("请输入序数:");
	scanf("%d",&xushu);
	printf("该一元多项式为:");
	for(i=0; i<20; i++){
		for(j=0; j<10; j++){
			if(shu[i].xishu[j] != 0 && (i+1) == xushu && shu[i].xishu[j] != 1)
				printf("%.2lf",shu[i].xishu[j]);
			if(shu[i].zhishu[j] != 0 && (i+1) == xushu)
				printf("x^");
			if(shu[i].zhishu[j] != 0 && (i+1) == xushu)
				printf("%.2lf",shu[i].zhishu[j]);
			if(shu[i].xishu[j+1] > 0 && j+1<10 && (i+1) == xushu)
				printf("+");
		}
	}
	//
	printf("（形如a1x^3+a2x^2）,请选择相加的后一个一元多项式为第几个?\n");
	printf("请输入序数:");
	scanf("%d",&xushu1);
	printf("该一元多项式为:");
	for(i=0; i<20; i++){
		for(j=0; j<10; j++){
			if(shu[i].xishu[j] != 0 && (i+1) == xushu1 && (int)shu[i].xishu[j] != 1)
				printf("%.2lf",shu[i].xishu[j]);
			if(shu[i].zhishu[j] != 0 && (i+1) == xushu1)
				printf("x^");
			if(shu[i].zhishu[j] != 0 && (i+1) == xushu1)//找到对应的那个一元多项式
				printf("%.2lf",shu[i].zhishu[j]);
			if((int)shu[i].xishu[j+1] > 0 && j+1<10 && (i+1) == xushu1)
				printf("+");
		}
	}
	m1=xushu-1;
	m2=xushu1-1;
	printf("相加后:\n");
	int baba=0;
	for(j=0; j<10; j++){
		//为了方便是有些浪费空间的
		for(i=0; i<10; i++){
			if(shu[m1].zhishu[j] == shu[m2].zhishu[i] && shu[m1].zhishu[j] != 0.0){//找到指数相同的就相加
				shu_2.xishujia[baba]=shu[m1].xishu[j]+shu[m2].xishu[i];
				shu_2.zhishujia[baba]=shu[m1].zhishu[j];
				baba++;
			}
			else if((int)shu[m1].xishu[i] != 0 && (int)shu[m2].xishu[j] == 0)
			{
				shu_2.xishujia[baba]=shu[m1].xishu[i];
				shu_2.zhishujia[baba]=shu[m1].zhishu[i];
				baba++;
			}
			else if((int)shu[m1].xishu[i] == 0 && (int)shu[m2].xishu[j] != 0)
			{
				shu_2.xishujia[baba]=shu[m2].xishu[j];
				shu_2.zhishujia[baba]=shu[m2].zhishu[j];
				baba++;
			}
			//shu_2.zhishujia[j]=shu[xushu].zhishu[j]+shu[xushu1].zhishu[j];
		}
	}
	for(j=0; j<10; j++)
	{
		if(shu_2.xishujia[j] != 0.0 && shu_2.xishujia[j] != 1)
			printf("%.2lf",shu_2.xishujia[j]);
		if(shu_2.zhishujia[j] != 0.0 && shu_2.xishujia[j] != 0.0 && shu_2.zhishujia[j] != 1)//！=1是解决bug，并自带bug的一种处理方式
			printf("x^");
		if(shu_2.zhishujia[j] != 0.0 && shu_2.xishujia[j] != 0.0 && shu_2.zhishujia[j] != 1)////！=1是解决bug，并自带bug的一种处理方式
			printf("%.2lf",shu_2.zhishujia[j]);
		if(shu_2.xishujia[j+1] != 0.0 && j+1<10 && shu_2.zhishujia[j+1] != 0.0)
			printf("+");
	}
	printf("\n");
}

void menu_2(void)
{
	printf(" 1.创建一元多项式  2.相加 \n");
	printf(" 3.相减  4.退出 \n");
}
void Create_2(void)//创建一元多项式
{
	int i=0, j=0, k=0, d=0;
	printf("有多少个多项式需要,请输入:");
	scanf("%d",&k);
	printf("\n");
	for(i=0; i<k; i++){
		printf("请输入第%d个该多项式的项个数:",i+1);
		scanf("%d",&d);
		for(j=0; j<d; j++){
			printf("请输入第%d个多项式的第%d个系数:",i+1,j+1);
			scanf("%lf",&shu[i].xishu[j]);
			printf("\n请输入第%d个多项式的第%d个指数:",i+1,j+1);
			scanf("%lf",&shu[i].zhishu[j]);
			printf("\n");
		}
		printf(" *****   第%d个完成!   ***** \n",i+1);
	}
}