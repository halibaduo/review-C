//���±༭
//һ���������ֽڣ����λ����1,�ó��󻹵�/2
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "wangjie.h"
#include <math.h>
#include <string.h>

#define MAXSIZE_4 100 //�����и���

int wenzi(char str[]);//������Ŀ
int shuzi(char str[]);//������Ŀ
int kongge(char str[]);//�ո���Ŀ
int zimu(char str[]);//��ĸ��Ŀ
int xunzhao(char str[], char ch);//Ѱ����ͬ��ĸ�ĸ���
int xunzhao_1(char str[],char str1[]);//Ѱ���ַ���
void shanchu_1(char str[],char str2[]);//ɾ����,��Ȼǰ��

int main(void)
{
	int sum_4=0, sum_4_1=0, sum_4_2=0, sum_4_3=0, sum_4_4=0, sum_4_5=0, sum_4_6=0;
	char ch4_1;
	char str1[10]={'\0'}, str2[10]={'\0'};
	system("color F1");
	kaishi();
	system("pause");
	char str[MAXSIZE_4]={'\0'};//���岢��ʼ��
	printf("������һ����������Ķ���:");
	gets(str);
	sum_4_1=wenzi(str);
	printf("���ַ�������%d������!\n",sum_4_1);
	sum_4_2=shuzi(str);
	printf("���ַ�������%d������!\n",sum_4_2);
	sum_4_3=kongge(str);
	printf("���ַ�������%d���ո�!\n",sum_4_3);
	sum_4_4=zimu(str);
	printf("���ַ�������%d����ĸ!\n",sum_4_4);
	sum_4=sum_4_1+sum_4_2+sum_4_3+sum_4_4;;
	printf("���ַ�����һ����%d����!\n",sum_4);
	printf("������һ����ĸ,���ǰ���Ѱ���ڸó������ж��ٸ�:");
	getchar();
	scanf("%c",&ch4_1);
	sum_4_5=xunzhao(str,ch4_1);
	if(sum_4_5 != 0)
		printf("���ַ���������%d��!\n",sum_4_5);
	else
		printf("������!\n");
	printf("������һ���ַ���,���ǰ�����Ѱ��:");
	gets(str1);
	sum_4_6=xunzhao_1(str,str1);
	if(sum_4_6 != 0)
		printf("���ַ�������ʼλ���ڵ�%d����ĸ\n",sum_4_6);
	else
		printf("������!\n");
	printf("���ַ���Ϊ%s\n",str);
	printf("������һ��ȥɾ��:");
	gets(str2);
	shanchu_1(str,str2);
	return 0;
}

void shanchu_1(char str[], char str2[])
{
	int n=0, i=0, j=0, k=0;
	n=xunzhao_1(str,str2);
	k=strlen(str2);
	for(i=n-1,j=0; j<k  ; i++,j++)
	{
		str[i]=str[i+k];
	}
	printf("�˿̵��ַ���Ϊ%s!\n",str);
}

int xunzhao_1(char str[], char str1[])
{
	//
	int i=0, j=0, m=1, n=0, j1=0, k=0;//mΪ��ͬ��ĸ����
	for(i=0; str[i]; i++)
	{
		if(str[i] == str1[0])
		{
			j1=i;
			for(j=i+1,k=1; str1[j]; j++,k++)
			{
				if(str[j] == str1[k])
				{
					m++;
				}
				if(str[j] != str[k])
					break;
			}
		}
	}
	n=strlen(str1);
	if(n == m)
		return j1;
	else
		return 0;
}

int xunzhao(char str[],char ch)
{
	int xunzhao1=0, i=0;
	for(i=0; str[i]; i++)
	{
		if(str[i] == ch)
			xunzhao1++;
	}
	return xunzhao1;
}

int wenzi(char str[])
{
	int wenzi1=0, i=0;
	for(i=0; str[i]; i++)
	{
		if(str[i] < 0 )//���λΪ1(����),�����ֽ�
			wenzi1++;
	}
	wenzi1=wenzi1/2;
	return wenzi1;
}

int shuzi(char str[])
{
	int shuzi1=0, i=0;
	for(i=0; str[i]; i++)
	{
		if(str[i]>='0' && str[i]<='9')
			shuzi1++;
	}
	return shuzi1;
}

int zimu(char str[])
{
	int zimu1=0, i=0;
	for(i=0; str[i]; i++)
	{
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			zimu1++;
	}
	return zimu1;
}

int kongge(char str[])
{
	int kongge1=0, i=0;
	for(i=0; str[i]; i++)
	{
		if(str[i] == ' ')
			kongge1++;
	}
	return kongge1;
}