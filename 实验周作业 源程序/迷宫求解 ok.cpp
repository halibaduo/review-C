//������Ϊ�Թ����
/*��Ŀ��ſ������Ϊ��һ����������������ɵĴ��������У���һ������һ���յ㣬��������ֻ��
һ��ͨ���ܴ���㵽�յ�,���ҵ���ƶ�ֻ���������ң�һ��,���˹�����ȥ��Ѱͨ·
'!'Ϊ����λ�� '$'Ϊ�߹���λ�� �кܴ��bug���ڣ�����*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "wangjie.h"
#include <time.h>
#include <math.h>

#define MAXSIZE 10//�����е����Թ���С
typedef struct MiGon{
	char ch1[MAXSIZE][MAXSIZE];//�Թ��Ĵ��ڸ���
	char ch2[MAXSIZE][MAXSIZE];//���ߵĸ���
}migon;
migon *E;

void Monster(void);//���ù���λ��
void silu(void);//��·��������
void find_3(void);//��Ѱ��·

int dd=0;

int main(void)
{
	int i=0, j=0;
	system("color F1");
	kaishi();
	system("pause");
	srand(time(0));
	E=(migon *)malloc(sizeof(migon));
	//��ʼ��
	//��ʼ������ͨ��Ϊ����ͨ��
	for(i=0; i<MAXSIZE; i++){
		for(j=0; j<MAXSIZE; j++){
			E->ch1[i][j]='0';
			E->ch2[i][j]='0';
		}
	}
	printf("\n�������Ѿ���ʼ������ͨ��,���ǵ���������Ͻ��Ǹ�·��,�յ������½��Ǹ�����\n");
	printf("·���ϴ��ںܶ�ܶ����,������������!������̭\n");
	printf("·���ϻ��кܶ�����·\n");
	printf("��һ�����յ��·��!!!\n");
	printf("����������������ÿһ�е���������λ�ð�!\n");
	Monster();//���ɹ��ﺯ��
	printf("\n **** �Ե�Ƭ��,�����Զ����ɲ�����· **** \n");//��·��'1'��ʾ,��·��'0'��ʾ
	silu();//��ǰ������ɹ�������Ļ�һ�������Ƴ���
	Sleep(1000);//����1��
	printf("\n **** �������������ǵ�ϵͳ���������ҵ�һ��ͨ·�� **** \n");
	find_3();
	return 0;
}

void find_3(void)
{
	//Ĭ�������ƶ����������������,�ٲ��оͷ���
	//��E->ch2[][]����¼�����ߵ�·��,�߹���λ����'1'��ʾ,û�߹��ĵط���'0'��ʾ
	int i=0, j=0, k=0, k1=0, k2=0, j1=0, i1=0;//k=1�˳����ҵĳ���
	char ch_3_1[2]={'*','\0'};
	char ch_3_2[2]={'!','\0'};
	char ch_3_3[2]={'#','\0'};
	//char ch3[MAXSIZE1][MAXSIZE1];
	//for(i=0; i<MAXSIZE1; i++)
	//	for(j=0; j<MAXSIZE1; j++)
	//	ch3[i][j]='\0';
	E->ch2[0][0]='1';//E->ch2�Ǽ�¼���ƶ�λ�õ�����,������Ȼ��ʼλ��Ҳ��Ϊ'1'
	//printf("1bug1\n"); //���ԣ��������  
	do{
	//�޼�:��Ĭ��һ������Ϊ��ʼ�ƶ�����
		//����
		do{
			//printf("bug1\n");
			i++;
			if(i<=MAXSIZE-1 && E->ch1[i][j1] != '!'){//û����������û������
				//printf("1bug2\n"); //���ԣ�����ͨ��
				E->ch2[i][j1]='1';
				i1=i;
				//ch3[dd]="��";
				//strcpy(ch3[dd],"��");
				//dd++;
				if(i == MAXSIZE-1 && j1 == MAXSIZE-1)//�Ƿ񵽴��յ��ж�
					k=1;
			}
			else//����ͻ�һ��
			{
				i--;
				i1=i;
				k1=1;
			}
			if(i == MAXSIZE-1 && j1 == MAXSIZE-1)//�Ƿ񵽴��յ��ж�
				k=1;
		}while(k1 != 1);
		//����
		k1=0;//�ָ�
		do{
			//printf("1bug3\n"); //���ԣ������޽���bug3
			j++;
			if(j<=MAXSIZE-1 && E->ch1[i1][j] != '!'){//û������������û����
				E->ch2[i1][j]='1';
				j1=j;
				//ch3[dd]="��";
				i1++;//�������˾Ͳ�������
				//printf("bug4\n");//���ԣ�δ�������
				if(i1 <= MAXSIZE-1 && E->ch1[i1][j] != '!'){
					k2=1;
					i1--;
				}
				//	strcpy(ch3[dd],"��");
				//dd++;
				if(i1 == MAXSIZE-1 && j == MAXSIZE-1)//�Ƿ񵽴��յ��ж�
					k=1;
			}
			else{
				j--;
				j1=j;
				k2=1;
			}
		}while(k2 != 1);
		if(i1 == MAXSIZE-1 && j1 == MAXSIZE-1)//�Ƿ񵽴��յ��ж�
			k=1;
		if(E->ch1[i1+1][j1] == '!' && E->ch1[i1][j1+1] == '!')//���䴦��
		{
			i1=i1-2;
			j++;
			j1++;
		}
		k2=0;//�ָ�
		dd++;
		if(dd == (int)pow(1000,2))
			k=1;
	}while(k !=1 );
	printf("\n·��Ϊ��*��:\n");
	for(i=0; i<MAXSIZE; i++)
		for(j=0; j<MAXSIZE; j++){
			if(E->ch2[i][j] == '1')//�ƶ�λ��
				printf("%3s",ch_3_1);
				//printf("*");
			if(E->ch1[i][j] == '!')//����λ��
				printf("%3s",ch_3_2);
				//printf("!");
			if(E->ch2[i][j] == '0')//��
				printf("%3s",ch_3_3);
				//printf("#");
			if((j+1) == MAXSIZE)
				printf("\n");
		}
		//	for(i=0; i<MAXSIZE1; i++){
		//	printf("%s\t",ch3[i]);
		//if((i+1)%10 == 0)
		//printf("\n");
		//}
		
}

void Monster(void)//��Ϊѡ��ÿ��3���Ĺ����λ��
{
	int i=0, j=0, choose_3, j1=0, j2=0, choose_4=0;
	printf("����������Ҫ�㱾�������в���,���������ǵĳ����������������λ��? 1:��  2.����");
	scanf("%d",&choose_4);
	if(choose_4 ==1){
	for(i=0; i<MAXSIZE; i++){
		while(j<3){
			printf("\n���������ң��������%d�е�%d��Ϊ����λ��:",i+1,j+1);
			scanf("%d",&choose_3);
			if(choose_3 <= MAXSIZE)
			{
				E->ch1[i][choose_3-1]='!';//��ǹ���
				j++;
			}
			else
			{
				for(j2=0; j2<MAXSIZE; j2++)
					for(j1=0; j1<MAXSIZE; j1++)
						E->ch1[j2][j1]='0';
				printf("\n ****** ��������!����������! ******\n");
				i=0;
				j=0;
			}
		}
		j=0;
	}
	}
	else{
		//
		for(i=0; i<MAXSIZE; i++){
			for(j=0; j<3; j++){
				E->ch1[i][rand()%MAXSIZE]='!';//�ӵ�һ�п�ʼ�����,ÿ����������������� �п����ص�,ռʱ�����ص�
			}
		}
	}
	//�����ܱ���ҽ���㡢�յ��ɹ���Ĵ�������ʱ���������Ϊ����,ʹ��㡢�յ��
	E->ch1[0][0]='0';
	E->ch1[MAXSIZE-1][MAXSIZE-1]='0';
}

void silu(void)
{
	//�����������
	int i=0, a=0, b=0, c=0, j=0;
	for(i=0; i<MAXSIZE; i++){
		a=rand()%MAXSIZE;
		b=rand()%MAXSIZE;
		c=rand()%MAXSIZE;
		E->ch1[i][a]='!';//������ǰ�淢���غϵ����
		E->ch1[i][b]='!';
		E->ch1[i][c]='!';
	}
	//�����ܱ���ҽ���㡢�յ��ɹ���Ĵ�����Ϊ����
	/*for(i=0; i<MAXSIZE; i++)
		for(j=0; j<MAXSIZE; j++)
		{
			if(E->ch1[i][j] == '!' && i<MAXSIZE-1 && j<MAXSIZE-1)
				E->ch1[i+1][j-1]='0';
		}
	*/
	E->ch1[0][0]='0';
	E->ch1[1][0]='0';
	E->ch1[MAXSIZE-1][MAXSIZE-1]='0';
}