//��������������������ƶ��ķ���
//������Խ��׳Խ��
//д����ջ һ��ջ����һά�� ����һ��ջ�����ά��
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "wangjie.h"

#define MAX 10//�Թ������С
#define MAX1 200
#define random(i) (rand()%i)

typedef struct Maze{ //�ṹ�塪���Թ�
	int maze[MAX][MAX]; //���Ͻ�Ϊ��� ���½�Ϊ�յ� 
}maze;
maze *M;

typedef struct Stack{ //ջnumber1
	int top;
	int use[MAX1];
}stack;
stack *S;

typedef struct ZhonZi{
	long zhonzi;
}Zhonzi;
Zhonzi *Z;

typedef struct Stack1{ //ջnumber2
	int top1;
	int use1[MAX1];
}stack1;
stack1 *S1;
struct timespec {//��Ҫ��д����
	time_t   tv_sec;        /*  �� seconds */
	long     tv_nsec;       /* ���룬10-9�� nanoseconds */
};

void Create(void);//�Թ�����
void Solve(void);//�Թ����
void InitStack(void);//ջ�ĳ�ʼ��
int StackEmpty(stack *S);//��ջ��
int StackFull(stack *S);//��ջ��
int Push(stack *S,int m);//��ջ
int Pop(stack *S);//��ջ
//����Ϊջnumber2�ĺ���
int StackEmpty1(stack1 *S1);//��ջ��
int StackFull1(stack1 *S1);//��ջ��
int Push1(stack1 *S1,int m);//��ջ
int Pop1(stack1 *S1);//��ջ


int main(void)
{
	int i0=0, j0=0;
	int i=0, j=0;
	Z->zhonzi=0;//��ʼ��
	system("color F1");
	kaishi();
	system("pause");
	M=(maze *)malloc(sizeof(maze));//���붯̬�ռ�
	S=(stack *)malloc(sizeof(stack));//Ϊջ���붯̬�ռ�
	Z=(Zhonzi *)malloc(sizeof(Zhonzi));//Ϊ���ӵĽṹ�����붯̬�ռ�
	S1=(stack1 *)malloc(sizeof(stack1));//Ϊջnumber2���붯̬�ռ�
	InitStack();//�˳�ʼ�����Խ�����ջ����ʼ��
	for(i0=0; i0<MAX; ++i0)
		for(j0=0; j0<MAX; ++j0)
			M->maze[i0][j0]=0;//ȫ����ʼ��Ϊ��λ 1Ϊǽλ
		printf("��ӭ�����Թ�������,���ǽ�Ϊ���ҵ����·��\n");
		Create();
		printf("��λ:�� ǽλ:! ��ʱ���Թ�Ϊ:\n");
		M->maze[0][0]=0;
		M->maze[MAX-1][MAX-1]=0;//����յ�Ϊ�� �Է���ŪΪǽ
		for(i=0; i<MAX; i++){
			for(j=0; j<MAX; j++){
				if(M->maze[i][j] == 0)//��λ
					printf("��");
				if(M->maze[i][j] == 1)//ǽλ
					printf("!");
				printf("\t");
				if(j == (MAX-1))//����һ�е�ĩβ�ͻ���
					printf("\n\n");
			}		
		}
		Solve();
		printf("��λ:�� ǽλ:! ·��:$ ·��Ϊ:\n");
		for(i=0; i<MAX; ++i){
			for(j=0; j<MAX; j++){
				if(M->maze[i][j] == 0)//��λ
					printf("��");
				else if(M->maze[i][j] == 1)//ǽλ
					printf("!");
				else if(M->maze[i][j] == 2)//·��λ
					printf("$");
				printf("\t");
				if(j == (MAX-1))//����һ�е�ĩβ�ͻ���
					printf("\n\n");	
			}
		}
		return 0;
}

void Create(void)//�Թ�����
{
	//
	int ok=1, ok0=1;//��������ʧ��ʱ
	while(ok == 1){
		for(int i=0; i<MAX; ++i){
			int geshuqiang=0;
			printf("�������%d���ж��ٸ�ǽλ:",i+1);
			scanf("%d",&geshuqiang);
			if(geshuqiang < MAX && geshuqiang != 0){//�ж��Ƿ����
				if(i == (MAX-1))
					ok=0;//���м�Ϊ��ȷ����ֱ�����һ���� ��������,�������Ҫ�ָ�
				while(ok0 == 1){
					printf("�������������%d��ǽ��λ��� ��Ŵ������� ( 1-%d ) :",i+1,MAX);
					for(int j=0; j<geshuqiang; ++j){
						int k=0;
						scanf("%d",&k);
						if(k>0 && k<=MAX){
							M->maze[i][k-1]=1;
							ok0=0;
						}
						else{
							printf("��������,����������!\n");
							break;
						}
					}
				}
				ok0=1;//�ָ� �Ͼ�������ܻ�����һ��
			}
			else if(geshuqiang == 0){
				printf("");
				if(i == (MAX-1))
					ok=0;//���м�Ϊ��ȷ����ֱ�����һ���� ��������,�������Ҫ�ָ�
			}
			else{
				printf("\n��������,��ȫ����������!\n");
				break;
			}
		}
	}
}

void Solve(void)//����ʹ���������������ķ�ʽȥ��
//���ϴ󲿷̶ֽ̳��� �涨������ĳһ����ǰ��,�����谭���ת��
{
	//����: 1Ϊǽλ 0Ϊ��λ ����2 Ϊ�ƶ�λ
	int choose=1;
	int direction=0;
	int k1=0, k2=0;
	int ji1=0,ji2=0;//��¼����һ��λ��
	struct timespec time1 = { 0, 0 };
	M->maze[k1][k2]=2;//��ʱΪ���λ
	M->maze[MAX-1][MAX-1]=0;
	Push(S,0);
	Push1(S1,0);
	do{	
		srand(time1.tv_nsec);//����ֵ0�� 1�� 2�� 3�� NULL��д0
		//Z->zhonzi++;//ͨ���ı����ӵĴ�Сʹ�÷����ܹ���ѭ��
		direction=rand()%4;// (int)[0,4)  c�����Ƿ���������,����java�Ƿ���double��
		if(direction == 0){//����
			if((k2-1) >= 0 && M->maze[k1][k2-1] != 1 && M->maze[k1][k2-1]){//����:û��ǽ��δ������δ�߹�
				if((k1 == ji1 && (k2-1) != ji2) || ((k2-1) == ji2 && k1 != ji1) || (k1 != ji1 && (k2-1) != ji2)){//�����ظ�
					choose=0;//���ں��������˲�����
					ji1=k1; ji2=k2;
					k2=k2-1;
					M->maze[k1][k2]=2;//����ƶ�λ
					if(!StackFull(S))//���ջû���ͽ�ջ����
						Push(S,k1);
					if(!StackFull1(S1))
						Push1(S1,k2);
				}
				else
					choose=0;
			}
		}
		else if(direction == 1){//����
			if(M->maze[k1][k2+1] != 1 && (k2+1)<=(MAX-1) && M->maze[k1][k2+1] != 2){//����:û��ǽ��δ������δ�߹�
				if((k1 == ji1 && k2+1 != ji2) || (k2+1 == ji2 && k1 != ji1) || (k2+1 != ji2 && k1 != ji1)){//�����ظ�
					choose=0;//���ں��������˲�����
					ji1=k1; ji2=k2;
					k2=k2+1;
					M->maze[k1][k2]=2;//����ƶ�λ
					if(!StackFull(S))//���ջû���ͽ�ջ����
						Push(S,k1);
					if(!StackFull1(S1))
						Push1(S1,k2);
				}
				else
					choose=0;
			}
		}
		else if(direction == 2){//����
			if(k1-1 >= 0 && M->maze[k1-1][k2] != 1 && M->maze[k1-1][k2] != 2){//����:û��ǽ��δ������δ�߹�
				if((k1-1 == ji1 && k2 != ji2) || (k1-1 != ji1 && k2 == ji2) || (k1-1 != ji1 && k2 != ji2)){//�����ظ�
					choose=0;//���ں��������˲�����
					ji1=k1; ji2=k2;
					k1=k1-1;
					M->maze[k1][k2]=2;
					if(!StackFull(S))//���ջû���ͽ�ջ����
						Push(S,k1);
					if(!StackFull1(S1))
						Push1(S1,k2);
				}
				else
					choose=0;
			}
		}
		else if(direction == 3){//����
			if(M->maze[k1+1][k2] != 1 && (k1+1)<=(MAX-1) && M->maze[k1+1][k2] != 2){//����:û��ǽ��δ������δ�߹�
				if((k1+1 != ji1 && k2 == ji2) || (k1+1 == ji1 && k2 != ji2) || (k1+1 != ji1 && k2 != ji2)){//�����ظ�
					choose=0;//���ں��������˲�����
					ji1=k1; ji2=k2;
					k1=k1+1;
					M->maze[k1][k2]=2;
					if(!StackFull(S))//���ջû���ͽ�ջ����
						Push(S,k1);
					if(!StackFull1(S1))
						Push1(S1,k2);
				}
				else
					choose=0;
			}
		}
		else
			printf("");//����ɶҲ���Ǿ���һ��
		if(choose == 1){//����ֻ�ܻ���һλ ������ĸ�if���������Ļ����� ��choose=1
			M->maze[k1][k2]=0;//�Ļؿ�λ ��λ����
			//printf("���е�����һ����!\n");                                            //��һ����Ե�޹ʲ��Ͻ��� !!!!!!!!!
			//k1=ji1; k2=ji2;
			//printf("k1=%d,k2=%d \n",k1,k2);
			//system("pause");
			if(!StackEmpty(S))//����ջ�ĺ���ȳ�
				k1=Pop(S);
			if(!StackEmpty1(S1))
				k2=Pop1(S1);
			if(k1==0 && k2==0 && S->top == -1 && S1->top1 == -1){//��������ԭ��
				Push(S,k1);
				Push1(S1,k2);
			}
			//Sleep(1000);
		}
		choose=1;//�ָ� �����´��ж�
	}while(M->maze[MAX-1][MAX-1] != 2);//����:�ѵ����յ�
	M->maze[0][0]=2;
}

void InitStack(void)
{
	S->top=-1;//��ʼ�������±�Ϊ-1
	S1->top1=-1;//��ʼ��ջnumber�������±�Ϊ-1
}
int StackEmpty(stack *S)//��ջ��
{
	return S->top==0;//�ǿյĻ��ͷ���1 ���򷵻�0
}
int StackFull(stack *S)//��ջ��
{
	return S->top==MAX1-1;//�����Ļ��ͷ���1 ���򷵻�0
}
int Push(stack *S,int m)//��ջ
{
	//
	if(StackFull(S)){
		printf("ջ����,����������ջ������!\n");
		return 0;
	}
	S->use[++S->top]=m;
	return 1;
}
int Pop(stack *S)//��ջ
{
	int fanhui=0;
	if(StackEmpty(S)){
		printf("ջΪ��,�޷����г�ջ����!\n");
		return 0;
	}
	fanhui=S->use[S->top--];
	return fanhui;//����ֵ����
}
//����Ϊջnumber2�ĺ���˵��
int StackEmpty1(stack1 *S1)//��ջ��
{
	return S1->top1==0;//�ǿյĻ��ͷ���1 ���򷵻�0
}
int StackFull1(stack1 *S1)//��ջ��
{
	return S1->top1==MAX1-1;//�����Ļ��ͷ���1 ���򷵻�0
}
int Push1(stack1 *S1,int m)//��ջ
{
	//
	if(StackFull1(S1)){
		printf("ջ����,����������ջ������!\n");
		return 0;
	}
	S1->use1[++S1->top1]=m;
	return 1;
}
int Pop1(stack1 *S1)//��ջ
{
	int fanhui=0;
	if(StackEmpty1(S1)){
		printf("ջΪ��,�޷����г�ջ����!\n");
		return 0;
	}
	fanhui=S1->use1[S1->top1--];
	return fanhui;//����ֵ����
}

