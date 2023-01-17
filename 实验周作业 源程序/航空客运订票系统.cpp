#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "wangjie.h"

#define MAX 20

typedef struct Plane{
	//
	char destination[MAX][MAX];//�յ�վ ��һάȥ�洢
	int flightnumber;//�����
	int airplanenumber;//�ɻ���
	int time;//����ʱ��(int)
	int ridenumber;//�������� ��Ϊ20
	int ticket;//��Ʊ��
}plane;
plane P[MAX];//����

struct People{
	char name[MAX][MAX];//һά������
	int flightnumber_1;//�����
	int grade;//�ȼ� 1��Ӧ��ͳ�׼�
};
struct People people[MAX];//�˵���Ϣ


int choose=0;
char* ForTime(int i);//�������
char* ForName(int i);//����
void menu(void);//����ɻ���


int main(void)
{
	/*�յ�վ��������š��ɻ��š��������գ����ڼ�����
	��Ա�����Ʊ�����Ѷ�Ʊ�Ŀͻ��������������֡���Ʊ������λ�ȼ�1��2��3���Լ��Ⱥ��油�Ŀͻ�������*/
	int i=0, j=0, choose_1=0, choose_2;
	int jixia=0, k=0;
	char str[10];
	system("color F1");
	kaishi();
	system("pause");
	//P=(plane )malloc(sizeof(plane));
	//people=(People *)malloc(sizeof(People));
	for(i=0; i<MAX; i++)//��ʼ��,��ͬ
		for(j=0; j<MAX; j++)
			P->destination[i][j]='\0';
	//
	for(i=0; i<MAX; i++)
		P[i].ticket=0;
	printf("�����������ǿ�ʼ���ú����ϸ��!\n");
	printf("���ʸ÷ɻ���һ���ж��ٺ���:");
	scanf("%d",&choose);
	for(i=0; i<choose; i++)
	{
		printf("��������ʼ�����%d�Һ������Ϣ!\n",i+1);
		printf("�����յ�վ��:");
		getchar();
		gets(P[i].destination[i]);
		printf("���ĺ������:");
		scanf("%d",&P[i].flightnumber);
		printf("���ķɻ�����:");
		scanf("%d",&P[i].airplanenumber);
		printf("�ú���Ŀ�ʼ����ʱ���ǣ�1Ϊ����һ�����ƣ�:");
		scanf("%d",&P[i].time);
		printf("���ĳ��������ǣ�<20��:");
		scanf("%d",&P[i].ridenumber);
	}
kaitou:
	printf("��������������һ���˿�,��ǰȥ��Ʊ!(һ��������)\n");
	for(i=0; i<3; i++){
		printf("����,����,������Ĺ���:");
		getchar();
		gets(people[i].name[0]);
		printf("��������Ҫ�����ĺŷɻ�,������÷ɻ��ĺ����:");
		menu();
		printf("������:");
		scanf("%d",&choose_1);
		for(j=0; j<choose; j++)
		{
			if(P[j].flightnumber == choose_1)
			{
				people[i].flightnumber_1=P[j].flightnumber;//����Ŵ���,����ʹ��������Һ���ŵ�Ŷ������
				printf("\n����������Ҫ��˵ļ���1-3��:");
					scanf("%d",&choose_2);
				if(choose_2>=1 && choose_2<=3)
					people[i].grade=choose_2;
				else{
					printf("��ѽ,����,ϲ��������,����ͳ����߼���3�ɣ�����Ҳ���ǻ��ҵ�Ǯ,hahaha\n");
					people[i].grade=3;
				}
				printf("����,�Ѿ�Ϊ��������,�ú�����%s����10�����!��Ʊ���ú�\n",ForTime(P[j].time));
				P[j].ticket++;
				break;
			}
			else if(j==choose){
				printf("������˼����,û���ҵ�����˵�ĵĺ����,�����鿴������ٰ���!\n");
				goto kaitou;
			}
		}
		printf("\n *** ��%d��ģ�������Ϣ¼�����! *** \n",i+1);
	}
	printf("������Ҫ���Ǹ����������˵ĺ�����Ϣ��(yes or no):");
	getchar();
	gets(str);
	if(strcmp(str,"yes") == 0 || strcmp(str,"YES") == 0)
	{
		//
		for(i=0; i<3; i++)
		{
			printf("��%d�˵���Ϣ����:\n",i+1);
			printf("\n����:%s",people[i].name);
			printf("\n��������:%s",ForName(people[i].grade));
			//for(j=0; j<choose; j++){
			for(k=0; k<MAX; k++)//��ʵ�˴���MAX���Ը�Ϊ3,����ʵ��,������˵����MAX����
			{
				if(P[k].flightnumber == people[i].flightnumber_1 )
					jixia=k;
			}
			//}
			printf("\n�յ�վ:%s",P[jixia].destination[jixia]);
			printf("\n�����:%d",P[jixia].flightnumber);
			printf("\n�ɻ���:%d",P[jixia].airplanenumber);
			printf("\n����ʱ��:%s",ForTime(P[jixia].time));
			printf("\n��������:%d",P[jixia].ridenumber);
			printf("\n�ú�����Ʊ��:%d",(P[jixia].ridenumber-P[jixia].ticket));
			printf("\n");
		}
	}
	else{
		printf("���������ϼ����˳�,ף���������!");
		Sleep(2000);
		exit(0);
	}
	return 0;
}

char* ForName(int i)
{
	if(i == 1)
		return "����";
	else if(i == 2)
		return "�м�";
	else if(i == 3)
		return "�߼�";
	else
		return "����δ֪����";
}

char* ForTime(int i)//�������
{
	//1��������һ,����
	if(i == 1)
		return "����һ";
	else if(i == 2)
		return "���ڶ�";
	else if(i == 3)
		return "������";
	else if(i == 4)
		return "������";
	else if(i == 5)
		return "������";
	else if(i == 6)
		return "������";
	else if(i == 7)
		return "������";
	else
		return "����!��С������";
}

/*������д��:����*/

void menu(void)
{
	int i=0;
	printf("��ǰ�������:\n");
	for(i=0; i<choose; i++)
	{
		printf("%5d\t",P[i].flightnumber);
		if((i+1)%4 == 0)
			printf("\n");
	}
	printf("\n");
}