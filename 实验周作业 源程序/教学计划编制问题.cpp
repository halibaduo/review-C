//��ѧ�ƻ���������
/*��Ȼ��רҵ�ֺܶ���,��ͬ��רҵ���ܾʹ��ڲ�ͬ��ѧϰ������ ��Ҳ����˵��רҵֻ����Щ�꼶�����ϣ�
һ��=��ѧ�� ��ͬרҵ���в�ͬ�Ŀγ� 
����ÿ��ѧ�ڵ�ʱ����ȣ�ѧ����� �γ̵��Ⱥ�˳��Ҳ�������� ������ 
�ּ���û�ſγ�ֻռһ��ѧ�� */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "wangjie.h"

#define MAX 20

typedef struct Term{
	char course[MAX][MAX]; //ÿһ�еĴ���һ�ſγ�
}term;
term subject[MAX];//����רҵ


void menu(void);//��ʾ�����רҵ������
void menu_1(void);//��ʾ������γ̵�����
char* ForName(int i);//����רҵ����
char* ForName_1(int i);//���ؿγ�����
void look(void);//�������רҵ�����


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
			printf("��ӭ������ѧ�ƻ������������,���ǽ�������!\n");
			printf("�������רҵ���������:\n");
			menu();
			printf("��������ӵ���൱�ϵ�һ�������,�㽫������רҵ����Ҫѧϰ��Щ�γ�!\n");
			for(i=0; i<7; i++){
				printf("���������Ǵ� **** ��%d��רҵ��%s�� **** ��ʼ:\n",i+1,ForName(i+1));
				printf("�γ���:\n");
				menu_1();
				//����
				do{
					printf("���������Ҫѧ�м��ſγ��أ�������:");
					scanf("%d",&choose);
					if(choose <= 8){
						for(j=0; j<choose; j++){
							printf("�������%d�ſγ̵Ĵ���:",j+1);
							scanf("%d",&choose_1);
							strcpy(subject[i].course[j],ForName_1(choose_1));
						}
					}
					else
						printf("��������!����������!\n");
				}while(choose > 8);
			}
			printf("�������������רҵ�����пγ̣�˳��δ�䣩\n");
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
		printf("��%d��רҵ��%s��:",i+1,ForName(i+1));
		printf("����רҵ�����¿γ�:");
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
/*�γ���:���Ӽ�������ɢ��ѧ��������ơ����ݽṹ������ϵͳ����������ԭ��΢��ϵͳ�������ϵͳ�ṹ��
����ԭ����������硢���ݿ�ϵͳ��������̡��˹����ܡ������ͼ��ѧ������ͼ���������ͨѶԭ��
��ý����Ϣ�������������źŴ�����������ơ�������㡢�㷨������������Ϣ��ȫ
	��Ӧ������ѧ��������Ϣ�Կ����ƶ����㡢������������������˻�������ơ��������������*/
	printf("\n 1.���Ӽ���     2.��ɢ��ѧ ");
	printf("\n 3.�������     4.���ݽṹ");
	printf("\n 5.����ϵͳ     6.��������ԭ��");
	printf("\n 7.���������     8.�˹�����");
	printf("\n");
}

char* ForName_1(int i)
{
	//
	if(i == 1)
		return "���Ӽ���";
	else if(i == 2)
		return "��ɢ��ѧ";
	else if(i == 3)
		return "�������";
	else if(i == 4)
		return "���ݽṹ";
	else if(i == 5)
		return "����ϵͳ";
	else if(i == 6)
		return "��������ԭ��";
	else if(i == 7)
		return "���������";
	else if(i == 8)
		return "�˹�����";
	else
		return "������δ֪����!\n";
}

void menu(void)
{
	printf("\n 1.�������ѧ�ڼ���     2.�Զ���");
	printf("\n 3.��Ϣ��ȫ     4.����������");
	printf("\n 5.ͨ�Ź���     6.���ݿ�ѧ");
	printf("\n 7.�����ݼ���     \n");
}

char* ForName(int i)
{
	if(i == 1)
		return "�������ѧ�ڼ���";
	else if(i == 2)
		return "�Զ���";
	else if(i == 3)
		return "��Ϣ��ȫ";
	else if(i == 4)
		return "����������";
	else if(i == 5)
		return "ͨ�Ź���";
	else if(i == 6)
		return "���ݿ�ѧ";
	else if(i == 7)
		return "�����ݼ���";
	else
		return "������δ֪�Ĵ���";
}