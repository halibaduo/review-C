//�˿�����Ϸ
//һ��52����,Ĭ����������,��1��52,��Ϊ�����������������Ǹû����ı������ƺţ��ͽ��Ʒ���
//���ã�Ϊ1������ Ϊ0������
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "wangjie.h"

#define MAX 53

typedef struct Pai{
	int num[MAX];//����
	//int num1[MAX][MAX];//�ƴ�С ֻ��һά
}pai;
pai *P;

void youxi(void);//��Ϸ��ʼ
void look_1(void);//�鿴���泯�ϵ��ƻ�����Щ?

int jishu=2;

int main(void)
{
	int i=0;
	system("color F1");
	kaishi();
	system("pause");
	P=(pai *)malloc(sizeof(pai));
	//printf("bug1\n");
	for(i=1; i<=52; i++)
		P->num[i]=1;//ȫ������������
	//printf("bug2\n");
	youxi();
	printf("�˿�,��Ϊ�������Ϊ:\n");
	look_1();
	return 0;
}

void youxi(void)//��Ϸ��ʼ�ĺ���
{
	int i=0, j=0;
	do{
		for(j=1; j<=52; j++)
		{	
			if(jishu <= 52){
				if(j%jishu == 0)//�ҵ��Ǳ���������
				{
					//printf("bug1\n");
					if(P->num[j] == 1)
						P->num[j]=0;
					if(P->num[j] == 0)
						P->num[j]=1;//Ҳ�������滻һ��
				}
			}
		}
		jishu++;
	}while(jishu == 53);
}

void look_1(void)
{
	//
	int i=0, j=0;
	for(j=1; j<=52; j++)
	{
		if(P->num[j] == 1){//if����Ϊ����
			printf("%d\t",j);
			i++;
		}
		if(i%7 == 0)//7��һ��
			printf("\n");
	}
	printf("\n");
}