//joseph�� ˳ʱ��Χ��һȦ
//num[i][j]=0 :�� num[i][j]=1 :��
//һάΪ���� ��ά����һ��Ϊ���
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "wangjie.h"

#define MAX 20

typedef struct People{
	int num[MAX][MAX];//����
	int num1;//������
	int num2[MAX];//����
}people;
people *P;

void youxi(int d);

int main(void)
{
	int people1=0, i=0, mima=0, choose_1, j=0;
	system("color F1");
	kaishi();
	system("pause");
	P=(people *)malloc(sizeof(people));
	printf("һ���ж�����,������:");
	scanf("%d",&people1);
	P->num1=people1;
	for(i=0; i<people1; i++)
		for(j=0; j<people1; j++)
			P->num[i][j]=1;//ȫ��
	printf("ÿ���˶���һ������,��ô������������������ÿһ���˵����������!\n");
	for(i=0; i<people1; i++)
	{
		printf("�������%d���˵���������:",i+1);
		scanf("%d",&mima);
		printf("\n");
		P->num2[i]=mima;
	}
	printf("�����������ǿ�ʼ��Ϸ!\n");
	printf("�������ϵ����,��������������һ������ֵ,������:");
	scanf("%d",&choose_1);
	printf("\n");
	choose_1=choose_1%people1;
	youxi(choose_1);
	return 0;
}

void youxi(int d)
{
	int i=0, j=0, k=0, chuqu=0, kk=0;
	for(i=0; i<MAX; i++)
	{
		P->num[d][i]=0;//����������ȫ�˳�
	}
	//printf("haha");
	j=P->num2[d];//������d����,���ѳ���,�����������е����봢������
	kk++;//�˳���Ϸ���˼�һ
	do{
		//
		//printf("bug1\n"); //����ѭ����!!!
		j=j%(P->num1-kk);
		for(i=0; i<P->num1; i++)//��ʼѰ�����������Ǵ˵���
		{
			if(i == j && P->num[i][0] != 0){//���������û�˳�����
				for(k=0; k<MAX; k++){
					P->num[i][k]=0;//����������ȫ����
				}
				chuqu=1;
				j=P->num2[i];//���ø��˵���������
			}
			if(P->num[i][0] == 0)
				j++;
			if(chuqu == 1)
			{
				chuqu=0;
				kk++;
				break;
			}
		}
	}while(kk != P->num1-1);//ʣ�����һ���˵����� ������ȫ���˳���������ϵ�!!!
	for(i=0; i<P->num1; i++){
		for(j=0; j<P->num1; j++)
		{
			if(P->num[i][j] == 1){
				printf("������µ����ǵ�%d��!\n",i+1);
				break;
			}
		}
	}
}