#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include "wangjie.h"

#define MAX 50

char filename[MAX];//�����ļ���
typedef struct File{
	char name[MAX];//����
	char grade[MAX];//�ɼ�
	char sex;//�Ա�,mΪ��,wΪŮ
	//
}File;
File F[MAX];
File F1[MAX];//������֤�Ƿ�ɹ���F�е�������ת�ļ���F1��
//���ǲ������붯̬�ռ��,�����������ָ��Ļ�������Ҫ���붯̬�ռ��
int people=0;

void Setup(void);//����ļ�����

int main(void)//����������̫����,��������ά������չ
{
	int i=0, j=0;
	system("color F1");
	kaishi();
	//��ʼ��
	for(i=0; i<MAX; i++)
	for(j=0; j<MAX; j++){
		F[i].grade[j]='\0';
		F[i].name[j]='\0';
		F1[i].grade[j]='\0';
		F1[i].name[j]='\0';
	}
	system("pause");
	FILE *fp;
	printf("�������ڿ��Դ���һ���ļ�,��������������ļ�������!���������ѡ��β׺.dat��:");
	gets(filename);
	fp=fopen(filename,"w+");//��д��filename�ļ� fp�ļ�ָ��ָ�� �ļ����׵�ַ ��fopen��������
	if(fp == NULL)
	{
		printf("�ļ���ʧ��!\n");
		exit(0);
	}
	else
	{
		//
		printf("�ļ��Ѿ��ɹ���!��ô�������ھͿ�ʼ����ļ����ݰ�!\n");
		Setup();
		rewind(fp);//��ɺ�ſ�ʼ���к������
		//fprintf(fp,"\n");
		fprintf(fp,"��Ա��Ϣ����:\n");
		fprintf(fp,"����:\t\t\t�ɼ�:\t\t\t�Ա�:\n");
		for(i=0; i<MAX; i++){//���Խ����е����ݶ���
			fwrite(&F[i],sizeof(struct File),1,fp);// size*count
			fprintf(fp,"\n");
		}
		printf("�����ļ��гɹ�!\n");
		printf("���������ǲ鿴һ���ļ��е�����\n");
		//rewind(fp);//ʹ�ļ�ָ��ָ��ͷ��
		fseek(fp,0,SEEK_SET);//���ô��д���������д��� ͬ����
		fread(&F1[0],sizeof(struct File),1,fp);
		for(i=0; i<people; i++)
		{//�˺�̴�����Բ���F1,�����轫�Լӵ�fprintf,�뻻�д���ɾ����
			printf("��%d���˵�����:%s",i+1,F[i].name);
			printf("\n��%d���˵Ŀ��Գɼ�:%s",i+1,F[i].grade);
			printf("\n��%d���˵��Ա���:",i+1);
			if(F[i].sex == 'm'  || F[i].sex == 'M')
				printf("��\n");
			else if(F[i].sex == 'w' || F[i].sex == 'W')//ע��:���ﲻ����д����if �����else ����else��佫�쳣���
				printf("Ů\n");
			else
				printf("!**** ���ִ��� ****!\n");
			printf("\n\n");
		}
	}
	fclose(fp);
	return 0;
}


void Setup(void)
{
	int i=0, j=0;
	printf("�������ļ���һ����Ҫ�洢������:");
	scanf("%d",&people);
	for(i=0; i<people; i++)
	{
		//
		printf("�������%d�˵�����:",i+1);
		//scanf("%s",F[i]->name); //��ס�Լ��Ĵ���!!!
		getchar();//ע����һ�е�getchar()������getchar(),ֻ����һ�е�getchar()��Ҫ����
		//fflush(stdin);
		gets(F[i].name);
		printf("\n�������%d���˵Ŀ��Գɼ�:",i+1);//���ҷ��ִ����ֻ����λ���ĺ�һλ,Ҳ���ǵ�һλ�ǲ������,δ��ȡ��
		//getchar(); //���е�getchar()ʹ�õ�һ���ַ����س�ȡ��
		gets(F[i].grade);
		//scanf("%s",F[i].grade);
		//printf("\n !!! �ոն�ȡ����Ϊ%s !!! \n",F[i].grade); //��֤bug����
		printf("\n�������%d���˵��Ա�m:�� or w:Ů��:",i+1);
		scanf("%c",&F[i].sex);
		printf("\n ***** ��%d���˵���Ϣ¼�����! *****\n",i+1);
	}
}