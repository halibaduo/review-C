//��ҵ���ȳ���
/*ְԱ������ 1.���� 2.�������� 3.ְ�� ����֮�����ϵȫ����һ����������(����) 
������������֮ǰ��Ҫ������򱨸�(�ύ����),Ȼ����Ƿ��˵������,
���а���: ���˹��� ����ţ�ÿ������Ŷ�Ӧһ������  ����:�߻���ָʾ�����顢������
���е���Щȫ���� **����** ������,ͬʱҲ��Ҫ�������һ���ļ�*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "wangjie.h"

#define QueueSize 100
#define MAX 3

typedef struct Work{
	char task[MAX][MAX];//task[0]:���� task[1]:���ž��� task[2]:ְ��
}Work;
Work W[MAX];

typedef struct cirQueue{
	int data[QueueSize];//һάȫ��Ϊһ,��������
	int rear;//βָ��
	int front;//ͷָ��
	int count;//����
}CirQueue;
CirQueue *Q;

void InitQueue(CirQueue *Q);//��ʼ������
int QueueEmpty(CirQueue *Q);//�ж��п�
int QueueFull(CirQueue *Q);//�ж�����
int EnQueue(CirQueue *Q,int x);//���
int DeQueue(CirQueue *Q);//����
void Anpai(void);//���Ź���
char* ForName(int i);//��������
char* ForName_1(int i);//��Ա����
char* ForWork();//�����������

char kk[15]; //��һ��λ�ü�¼������,�ڶ���λ�ü�¼���ž�����,������λ�ü�¼ְ���Ĺ���
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
	printf("����˾һ����������,�����г�������,�������˶���������İ����¹�����!\n");
	printf("�����µ�������ֱ���: 1.���� 2.���ž��� 3.ְ�� \n");
	printf("���ǵĹ���Ҳ���¿��Է�Ϊ4��!\n");
	printf("�ֱ�Ϊ: 1.�߻� 2.ָʾ 3.���� 4.���� \n");
	printf("�����������������������˵Ĺ���,���ǵ�ϵͳ����С��㽫����������!\n");
	Anpai();
	printf("������������������˳����:\n");
	for(i=0; i<3; i++)
	{
		//strcpy(str_1,DeQueue(Q));
		chulai=DeQueue(Q);
		if(strcmp("����",ForName_1(chulai)) == 0)
			printf("����%s���Ĺ�����:%s",ForName_1(chulai),kk);//������Ϊ����3��%s�Ͳ�������Сʱ��bug,Ц����,��������,cao����
		else if(strcmp("���ž���",ForName_1(chulai)) == 0)
			printf("����%s���Ĺ�����:%s",ForName_1(chulai),kk1);
		else if(strcmp("ְ��",ForName_1(chulai)) == 0)
			printf("����%s���Ĺ�����:%s",ForName_1(chulai),kk2);
		printf("\n");
	}
	return 0;
}

void Anpai(void)
{
	//
	int i=0, choose=0, choose_1=0, d=0, yiqian=0;
	do{
		printf("��������Ҫ�Ȱ���˭������,�����������1-3��:");
		scanf("%d",&choose_1);
		//i=choose_1-1;
		d++;
		printf("�˿��밲�� %s �Ĺ���!\n",ForName_1(choose_1));
		do{
			printf("�������Ĺ����ǣ����������1-4��:");
			scanf("%d",&choose);
			if(choose == yiqian)
				d--;
			yiqian=choose;//������һ���Ĵ���
			printf("\n��ѡ������Ĺ�����:%s",ForName(choose));
			if(strcmp("����",ForName_1(choose_1)) == 0)
				strcpy(kk,ForName(choose));//
			if(strcmp("���ž���",ForName_1(choose_1)) == 0)
				strcpy(kk1,ForName(choose));
			if(strcmp("ְ��",ForName_1(choose_1)) == 0)
				strcpy(kk2,ForName(choose));
			//printf("bug1\n"); //˳��ͨ��
			strcpy(&W[i].task[i][0],ForName_1(choose));
			//printf("bug2\n"); //˳��ͨ��
			EnQueue(Q,choose_1);
			printf("��������°�������,������밲����һ���˵�����!\n");
			for(i=1; i<=3; i++)
			if(i == choose_1)
				printf("\n %s�������Ѿ����ź���!",ForName_1(choose_1));
		}while(choose!=1 && choose!=2 && choose!=3 && choose!=4);
		
	}while(d != 3);
}

char* ForName_1(int i)
{
	if(i == 1)
		return "����";
	else if(i == 2)
		return "���ž���";
	else if(i == 3)
		return "ְ��";
	else
		return " **** ����δ֪���� **** ";
}

char* ForName(int i)
{
	if(i == 1)
		return "�߻�";
	else if(i == 2)
		return "ָʾ";
	else if(i == 3)
		return "����";
	else if(i == 4)
		return "����";
	else
		return " **** ����δ֪���� **** ";
}

void InitQueue(CirQueue *Q)
{
	Q->count=0;//������ʼ��Ϊ��
	Q->front=Q->rear=0;
}

int QueueEmpty(CirQueue *Q)
{
	return Q->count==0;
}

int QueueFull(CirQueue *Q)
{
	return Q->count==QueueSize;//������ȷ�Ƕ�Ӧ�����±��(����ʱ��)
}

int EnQueue(CirQueue *Q,int x)
{
	//
	//printf("Ҫ���������,���ǽ����˶���!\n"); //˳��ͨ��
	if(QueueFull(Q))
	{
		printf("�����Ѿ�����,������˼,�Ѿ��޷����������!\n");
		return 0;
	}
	//printf("bug1\n"); //˳��ͨ��
	Q->count++;
	//strcpy(&Q->data[Q->rear],str);
	//printf("bug2\n");
	Q->data[Q->rear]=x;//���ݽ���
	Q->rear=(Q->rear+1)%QueueSize;
	//printf("bug3\n");
	printf("\n *** ��ӳɹ� *** \n");
	return 1;
}

int DeQueue(CirQueue *Q)
{
	//char str_1[20]={'\0'};
	int temp=0;
	if(QueueEmpty(Q))
	{
		printf("\n����Ϊ��,��ʱ�޷����г��Ӳ��� \n");
		return 1;//����
	}
	Q->count--;
	//strcpy(str_1,Q->data[Q->front]);
	temp=Q->data[Q->front];
	Q->front=(Q->front+1)%QueueSize;
	return temp;
}