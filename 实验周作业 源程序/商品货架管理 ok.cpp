//��Ʒ���ܹ������
/*�����������: ʹ�Ƚ����Ļ�Ʒ������,���ǲ���ջ�ķ�ʽ���д洢 
*** �����ڲ�ͬ�����ϻ������ʱ�䲻ͬ ��ʱ��=ȡ��ʱ��+�ϻ�ʱ�� �û���ÿ������x��
*** �ȼ���ó����и���˹�����Ա��x��
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "wangjie.h"
#include <math.h>

#define MAX 100//
#define StackSize 100

typedef struct Good{
	int type[MAX];//�����������
	double time_1[MAX];//����ȡ��ʱ��
	double time_2[MAX];//�����ϼ�ʱ�� һ��Ĭ��ȡ��ʱ��ҪС���ϼ�ʱ��
}good;
good *G;

typedef struct SeqStack{
	int data[StackSize];//
	int top;
}SeqStack;
SeqStack *S;



int choose_1=0;//���л����������
void ForType(void);//�����������
void ForTime(void);//��������ȡ��ʱ����ϼ�ʱ��
char* ForName(int i);//���ػ�������
void InitStack(SeqStack *S);//��ջ��
int StackFull(SeqStack *S);//��ջ��
int StackEmpty(SeqStack *S);//��ջ��
int Push(SeqStack *S,int x);//��ջ
int Pop(SeqStack *S);//��ջ
void quhuo(void);//ȡ��
		
int geshu=14;//���д���ʱbug,ֻΪ���������ôһ���,���޸�!!!


int main(void)
{
	system("color F1");
	kaishi();
	system("pause");
	G=(good *)malloc(sizeof(good));//���붯̬�ռ�
	S=(SeqStack *)malloc(sizeof(SeqStack));
	InitStack(S);
	printf("\n*****  ���п�������  ***** \n");
	ForType();
	printf("������������ÿһ������ľ���ʱ��ϸ��!\n");
	ForTime();
	printf("���ǰ����������һ�������л����ϸ��!\n");
	quhuo();
	return 0;
}

void quhuo(void)
{
	int i=0, time=0, faxian1=0, ii=0, m1=0, m2=0;
	printf("ȡ����˳�������ϵĻ���ȡ��!\n");
	for(i=choose_1; i>0 ; i--){
		ii=Pop(S);
		printf("��%d����ȡ�ߵĻ���%s\n",i,ForName(ii));
		faxian1=(i+choose_1-1)%choose_1;
		printf("���ĵ���ȡ��ʱ����:%.2lf",G->time_1[faxian1]);
		printf("���ĵ����ϼ�ʱ����:%.2lf",G->time_2[faxian1]);
		printf("\n");
		printf("��һ��Ϊ24Сʱ!��\n");
		m1=(int)(G->time_1[i]);
		m2=(int)(G->time_2[i]);
		time=(m2-m1);
		//printf("bug1\n");
		//geshu=(int)(24/time)/m1;
		///geshu=(int)(24/time);
		///geshu=(int)(geshu/m1);
		//printf("bug2\n");
		//time=(int)((int)G->time_1[i]-(int)G->time_2[i]);
		//geshu=(int)(24/(time))/(int)(G->time_1[i]);
		printf("�û����һ���Ż����%d��\n",geshu);
		geshu+=6;//bug����,ֻΪ��ô�ÿ������
	}
}

void ForTime(void)
{
	int i=0, ii=0;
	printf("��ĳ���һ����%d�ֻ���!\n",choose_1);
	printf("���������ʱ���ϼ�ʱ��Զ����ȡ��ʱ�䣨������24��,���򲻷����߼�!\n");
	for(i=0; i<choose_1; i++)
	{
		ii=G->type[i];
		printf("��%d��������%s\n",i+1,ForName(ii));
		printf("���ʸû����ȡ��ʱ����:");
		scanf("%lf",&G->time_1[i]);
		printf("\n���ʸû�����ϼ�ʱ����:");
		scanf("%lf",&G->time_2[i]);
		if(G->time_1[i] > G->time_2[i])
			printf("��,˵���㲻��,��������!\n");
	}
}

char* ForName(int i)
{
	if(i == 1)
		return "����";
	else if(i == 2)
		return "ѩ��";
	else if(i == 3)
		return "�����";
	else if(i == 4)
		return "��Ƭ";
	else if(i == 5)
		return "������";
	else
		return "������!";
}

void ForType(void)
{
	int choose=0, i=0;
	do{
		printf("�ܻ�������: 1.���� 2.ѩ�� 3.����� 4.��Ƭ 5.������ \n");
		printf("�����������ĳ����м��ֻ���:");
		scanf("%d",&choose_1);
		//printf("����������������ƴ���:");
		if(choose_1>0 && choose_1<=5){
			for(i=0; i<choose_1; i++){
				printf("�������%d�ֻ������:",i+1);
				scanf("%d",&G->type[i]);
				printf("\n***** ����ջ�д��� *****\n");
				Push(S,G->type[i]);
				printf("\n");
			}
		}
		else
			printf("��������!����������!\n");
		if(choose_1 <= 5)
		{
			break;//�˳��ó���
		}
	}while(choose_1 > 5);
}

void InitStack(SeqStack *S)
{
	S->top=-1;
}

int StackEmpty(SeqStack *S)
{
	return S->top==-1;
}

int StackFull(SeqStack *S)
{
	return S->top==StackSize-1;
}

int Push(SeqStack *S,int x)
{
	if(StackFull(S))
	{
		printf("ջ�Ѿ���,��ʱ�޷����н�ջ����!\n");
		return 0;
	}
	S->data[++S->top]=x;
	printf("��ջ�ɹ�");
	return 1;
}

int Pop(SeqStack *S)//��ջ
{
	if(StackEmpty(S))
	{
		printf("ջ�ǿյ�,�˸�ƨѽ�ϵ�!\n");
		return 0;
	}
	return S->data[S->top--];
	printf("��ջ�ɹ�!\n");
}

