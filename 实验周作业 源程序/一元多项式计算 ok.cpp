/*һԪ����ʽ�ļ���*/
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

void Create_2(void);//����һԪ����ʽ
void menu_2(void);//�˵�
void jiade(void);//���
void jiande(void);//���

int main(void)
{
	int choose_2=0, i=0, j=0;
	system("color F1");
	kaishi();
	system("pause");
	//��ʼ��Ϊ0
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
		printf("��ѡ��:\n");
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
			printf("�����˳�!\n");
			Sleep(1000);
			break;
		default :
			printf("��������!����������!\n");
		}
	}while(choose_2 != 4);
	return 0;
}
void jiande(void)//���
{
	int xushu=0, i=0, j=0, xushu1=0, m1=0, m2=0;
	printf("������a1x^3+a2x^2��,��ѡ����ӵ�ǰһ��һԪ����ʽΪ�ڼ���?\n");
	printf("����������:");
	scanf("%d",&xushu);
	printf("��һԪ����ʽΪ:");
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
	printf("������a1x^3+a2x^2��,��ѡ����ӵĺ�һ��һԪ����ʽΪ�ڼ���?\n");
	printf("����������:");
	scanf("%d",&xushu1);
	printf("��һԪ����ʽΪ:");
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
	printf("�����:\n");
	//int mama=0;
	int baba=0;
	for(j=0; j<10; j++){
		//Ϊ�˷�������Щ�˷ѿռ��
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

void jiade(void)//���
{
	int xushu=0, i=0, j=0, xushu1=0, m1=0, m2=0;
	printf("������a1x^3+a2x^2��,��ѡ����ӵ�ǰһ��һԪ����ʽΪ�ڼ���?\n");
	printf("����������:");
	scanf("%d",&xushu);
	printf("��һԪ����ʽΪ:");
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
	printf("������a1x^3+a2x^2��,��ѡ����ӵĺ�һ��һԪ����ʽΪ�ڼ���?\n");
	printf("����������:");
	scanf("%d",&xushu1);
	printf("��һԪ����ʽΪ:");
	for(i=0; i<20; i++){
		for(j=0; j<10; j++){
			if(shu[i].xishu[j] != 0 && (i+1) == xushu1 && (int)shu[i].xishu[j] != 1)
				printf("%.2lf",shu[i].xishu[j]);
			if(shu[i].zhishu[j] != 0 && (i+1) == xushu1)
				printf("x^");
			if(shu[i].zhishu[j] != 0 && (i+1) == xushu1)//�ҵ���Ӧ���Ǹ�һԪ����ʽ
				printf("%.2lf",shu[i].zhishu[j]);
			if((int)shu[i].xishu[j+1] > 0 && j+1<10 && (i+1) == xushu1)
				printf("+");
		}
	}
	m1=xushu-1;
	m2=xushu1-1;
	printf("��Ӻ�:\n");
	int baba=0;
	for(j=0; j<10; j++){
		//Ϊ�˷�������Щ�˷ѿռ��
		for(i=0; i<10; i++){
			if(shu[m1].zhishu[j] == shu[m2].zhishu[i] && shu[m1].zhishu[j] != 0.0){//�ҵ�ָ����ͬ�ľ����
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
		if(shu_2.zhishujia[j] != 0.0 && shu_2.xishujia[j] != 0.0 && shu_2.zhishujia[j] != 1)//��=1�ǽ��bug�����Դ�bug��һ�ִ���ʽ
			printf("x^");
		if(shu_2.zhishujia[j] != 0.0 && shu_2.xishujia[j] != 0.0 && shu_2.zhishujia[j] != 1)////��=1�ǽ��bug�����Դ�bug��һ�ִ���ʽ
			printf("%.2lf",shu_2.zhishujia[j]);
		if(shu_2.xishujia[j+1] != 0.0 && j+1<10 && shu_2.zhishujia[j+1] != 0.0)
			printf("+");
	}
	printf("\n");
}

void menu_2(void)
{
	printf(" 1.����һԪ����ʽ  2.��� \n");
	printf(" 3.���  4.�˳� \n");
}
void Create_2(void)//����һԪ����ʽ
{
	int i=0, j=0, k=0, d=0;
	printf("�ж��ٸ�����ʽ��Ҫ,������:");
	scanf("%d",&k);
	printf("\n");
	for(i=0; i<k; i++){
		printf("�������%d���ö���ʽ�������:",i+1);
		scanf("%d",&d);
		for(j=0; j<d; j++){
			printf("�������%d������ʽ�ĵ�%d��ϵ��:",i+1,j+1);
			scanf("%lf",&shu[i].xishu[j]);
			printf("\n�������%d������ʽ�ĵ�%d��ָ��:",i+1,j+1);
			scanf("%lf",&shu[i].zhishu[j]);
			printf("\n");
		}
		printf(" *****   ��%d�����!   ***** \n",i+1);
	}
}