#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wangjie.h"

struct STU1{//��
	char name1[20];//ѧУ����
	int grade1[20];//ѧУ�ɼ� ��Ŀ����20��
};
struct STU1 stu1[100];

struct STU2{//Ů
	char name2[20];//ѧУ����
	int grade2[20];//ѧУ�ɼ� ��Ŀ����20��
};
struct STU2 stu2[100];

int m=0, w=0, n=0;//m:���ӱ�����Ŀ���� w:Ů�ӱ�����Ŀ���� n:�μ�ѧУ�ĸ���


void Gradewoman(int i);//Ů����Ŀ�ɼ�
void Grademan(int i);//������Ŀ�ɼ�
void Create(void);//����
void insert_sort(int *array,int length);//ֱ�Ӳ��������㷨
void menu_1(void);//�˵�
void paihang(void);
void SUM(void);//�����ѧУ���ܷ�
void chazhao_1(void);//����
void paihang_1(void);//ѧУ����

int main(void)
{
	int choose_1=0;
	system("color F1");
	kaishi();
	system("pause");
	do{
		menu_1();
		printf("��ѡ��:");
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
			//�˳�
			printf("�����˳�!\n");
			break;
		default :
			printf("��������!,����������!\n");
		}
	}while(choose_1 != 6);
	return 0;
}

void paihang_1(void)
{
	int i=0, j=0, j1=0;
	int sum[20]={0}, sum1[20]={0}, sum2[20]={0};//���������±�c���Բ�����дδ֪��Ŷ!
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
			sum1[i]+=stu1[i].grade1[j];
		for(j1=0; j1<w; j1++)
			sum2[i]+=stu2[i].grade2[j];
		sum[i]=sum1[i]+sum2[i];
	}
	printf("ÿ��ѧУ���ܷ�:\n");
	for(i=0; i<n; i++)
		printf("��%d����%s��:%d\t",i+1,stu1[i].name1,sum[i]);
	insert_sort(sum,n);//ֱ�Ӳ��������㷨
	printf("\n����Ϊ\n");
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
	for(i=0; i<m; i++)//������ѧУ�����ӳɼ����뵽һ������
	{
		for(j=0; j<n; j++){
			chengji[i]=stu1[j].grade1[i];
		}
	}
	for(i=0; i<w; i++)//����ͬ��
	{
		for(j=0; j<n; j++){
			chengji1[i]=stu2[j].grade2[i];
		}
	}
	printf("�μӱ���������ѧУ��������:");
	for(i=0; i<n; i++){
		printf("%s\t",stu1[i].name1);
		if((i+1)%4 == 0)
			printf("\n");
	}
	printf("\n������ѧУ������:");
	getchar();
	scanf("%s",&name_1);
	for(i=0; i<n; i++)
	{
		if(strcmp(stu1[i].name1,name_1) == 0){
			printf("��У������,Ů�ӳɼ�Ϊ\n");
			//!!!!!!
			printf("����:\n");
			for(j=0; j<m; j++)
			{
				printf("%d\t",stu1[i].grade1[j]);
			}
			printf("\nŮ��:\n");
			for(j1=0; j1<w; j1++)
			{
				printf("%d\t",stu2[i].grade2[j1]);
			}
			printf("\n");
		}
	}
}
void SUM(void)//�������ѧУ�ܷ�
{
	int k1=0, k2=0, i=0, j=0;
	for(i=0; i<n; i++)
	{
		printf("��%d��ѧУ���ܷ�ͳ��\n",i+1);
		int sum1=0, sum2=0;
		printf("��У������Ϊ:%s\n",stu1[i].name1);
		printf("��У���ӳɼ��ܺ�Ϊ:\n");
		for(k1=0; k1<m; k1++){
			printf("��%d��:\n",k1+1);
			for(j=0; j<m; j++)
			{
				sum1 += stu1[i].grade1[j];
			}
			printf("�ܺͳɼ�Ϊ:%d\n",sum1);
		}
		printf("��У��Ů�ӳɼ��ܺ�Ϊ:\n");
		for(k2=0; k2<w; k2++){
			printf("��%d��:\n",k2+1);
			for(j=0; j<w; j++)
			{
				sum2 += stu2[i].grade2[j];
			}
			printf("�ܺͳɼ�Ϊ:%d\n",sum2);
		}
	}
}

void paihang(void)//�������ѧУ�ĳɼ�����
{
	int chengji[20], chengji1[20];
	int i=0, j=0;
	for(i=0; i<m; i++)//������ѧУ�����ӳɼ����뵽һ������
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
	printf("������������ӵ���Ŀ�ɼ�����\n");
	insert_sort(chengji,m);
	for(i=0; i<m; i++){
		printf("%d\t",chengji[i]);
	}
	//
	printf("\n");
	printf("���������Ů�ӵ���Ŀ�ɼ�����\n");
	insert_sort(chengji1,m);
	for(i=0; i<w; i++){
		printf("%d\t",chengji1[i]);
	}
	printf("\n");
}

void menu_1(void)
{
	printf(" 1.���� 2.�ɼ����� \n");
	printf(" 3.�ɼ��ܺ� 4.���� \n");
	printf(" 5.ѧУ���� 6.�˳�\n");
}
void Create(void)
{
	int i=0, j=0;
	printf("������μ���Ŀ��ѧУ����:");
	scanf("%d",&n);
	printf("\n");
	printf("\n���������ӱ�����Ŀ����:");
	scanf("%d",&m);
	printf("\n");
	printf("\n������Ů�ӱ�����Ŀ����:");
	scanf("%d",&w);
	printf("���������������ӱ���ÿ���ӵĳɼ�\n");
	for(j=0; j<n; j++)
	{
		printf("�������%d��ѧУ������:",j+1);
		getchar();
		scanf("%s",&stu1[j].name1);
		stu2[j].name2[20]=stu1[j].name1[20];//ͬ������
		printf("���ٴ������У����Ŀ�ɼ�\n");
		printf("*** ���� ***\n");
		Grademan(j);
		printf("*** Ů�� ***\n");
		Gradewoman(j);
	}	
}

void Grademan(int t)//������Ŀ�ɼ�
{
	//
	int i=0;
	for(i=0; i<m; i++){
		printf("�������%d����Ŀ�ĳɼ�:",i+1);
		scanf("%d",&stu1[t].grade1[i]);
		printf("\n");
	}
}

void Gradewoman(int t)//Ů����Ŀ�ɼ�
{
	int i=0;
	for(i=0; i<m; i++){
		printf("�������%d����Ŀ�ĳɼ�:",i+1);
		scanf("%d",&stu2[t].grade2[i]);
		printf("\n");
	}
}

void insert_sort(int *array,int length)//ֱ�Ӳ��������㷨
{
	//Ŀ��:����С��������
	int i , j , temp;
	if(length <= 1)//С�ڵ���1�ĳ���Ҳ����Ҫ������!
		return;
	for(i=1; i<length-1; i++){
		temp=array[i];
		j=i-1;
		while(j>=0 && temp<array[j]){//û�е�����ͷ�Ǹ��Һ����С��ǰ�������ʱ
			array[j+1]=array[j];
			--j;
		}
		array[j+1]=temp;//j�������Ȼ-1��,����+1����ȥ
	}
}
