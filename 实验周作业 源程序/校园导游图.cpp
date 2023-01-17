//У԰����ͼ
/*ԭ��: ����һ���ṹ�� �ṹ�����洢�涥����Ϣ,һ����ά����,һά�±�,�Ͷ�ά�±�ֱ����������յ� �������ͱ���
����һ������ȥ��¼��һά���±�,�������·����ʱ��,����ˣ���ǰ���±�ı�,�Ӷ�֪���˸������
ÿ���ߵ�Ȩֵ����������ص�֮��ľ���
*/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "wangjie.h"

#define MAX 30//���30����ַ��ʱ
#define MAXINT 32451//Ȩֵ�����ֵ 

typedef struct{
	char vexs[MAX][MAX];//һά����
	int arcs[MAX][MAX];//���յ�
	int vexnum;//��ǰ����
	int	arcnum;//��ǰ����
}AMGraph;
AMGraph G;

int Path[MAX][MAX];//��¼ǰһ���
int D[MAX][MAX];//��¼���·��


int LocateVex(AMGraph G,char* vexs);//��ȡ�ص��һά�±�
void Create(AMGraph G);//����
void ShortestPath(AMGraph G);
void DisplayPath(AMGraph G,int begin,int temp);



int LocateVex(AMGraph G,char* vexs)
{
	//
	int i=0;
	for(i=0; i<G.vexnum; i++)
	{
		if(strcmp(G.vexs[i], vexs) == 0) return i;//�ҵ��˾ͷ�������һά�±�
	}
	return -1;//���򷵻�-1
}

void Create(AMGraph G)//����
{
	//
	int i=0, j=0;
	char xuanze[10]={'\0'};
	char name1[10]={'\0'};//�����ص�,����ʼ��
	char name2[10]={'\0'};
	printf("�������ܵص���:");
	scanf("%d",&G.vexnum);
	printf("\n�����뵱ǰ�ܿ�ͨ�еı���:");
	scanf("%d",&G.arcnum);
	printf("\n����������������������!\n");
	for(i=0; i<G.vexnum; i++)
	{
		printf("�������%d���ص������:",i+1);
		getchar();
		gets(G.vexs[i]);//���൱�ڽ���i+1��������ʼ����
		printf("\n");
	}
	for(i=0; i<G.vexnum; i++){
		for(j=0; j<G.vexnum; j++)
		{
			if(i != j)
				G.arcs[i][j]=MAXINT;//ÿһ���ص�֮��ľ����ʼ��Ϊ���ֵMAXINT
			else
				G.arcs[i][j]=0;//�Լ����Լ��϶�Ϊ0��!
		}
	}
	printf("��������������ص�ľ��루Ȩֵ��!\n");
	for(i=0; i<G.vexnum; i++)
		for(j=0; j<G.vexnum; j++)
		{
			if(i != j){
				printf("���ʵ�%d���ص㣨%s���ڵ�%d�����㣨%s��֮����ͨ·�𣿣�yes or no��\n",i+1,G.vexs[i],j+1,G.vexs[j]);
				printf("������:");
				gets(xuanze);
				if( strcmp(xuanze,"yes") == 0 || strcmp(xuanze,"YES") == 0 )
				{
					printf("\n��ô�������������ص�֮��ľ���:");
					scanf("%d",&G.arcs[i][j]);
					G.arcs[j][i]=G.arcs[i][j];//����ͼ,Ҳ����˵���߶�����ͨ�� ˫��ͨ��
				}
				else
				{
					printf("�õ�,��׼���ûش���һ������!\n");
				}
			}
			else
				printf("��%d������%d���ص�,��Ȼ����˵���Եģ�������\n",i+1,j+1);
		}
}
//������������Ҫ����
void ShortestPath(AMGraph G)
{
	int i=0, j=0, k=0;
	for(i=0; i<G.vexnum; i++)
	{
		for(j=0; j<G.vexnum; j++)
		{
			D[i][j]=G.arcs[i][j];//������Ķ�ά����D[][]����¼�������ص�֮�����̾���
			if(D[i][j] < MAXINT && i!=j)
				Path[i][j]=i;
			else
				Path[i][j]=-1;//����ͼ�¼Ϊ-1
		}
	}
	for(k=0; k<G.vexnum; k++)//ϸ��:����k���������
	{
		for(i=0; i<G.vexnum; i++)
		{
			for(j=0; j<G.vexnum; j++)
			{
				if(D[i][k]+D[k][j] < D[i][j]){//ϸ��:k�����������forѭ��
					D[i][j]=D[i][k]+D[k][j];//�ֶ���·��ҪС�������ص�ֱ����ͨ·��
					Path[i][j]=Path[k][j];//��ǰһ�±껻Ϊ����k��j��
				}
			}
		}
	}
}

void DisplayPath(AMGraph G,int begin,int temp)
{
	if(Path[begin][temp] != -1)//��Ϊ-1��˵��֮�����ͨ·
	{
		DisplayPath(G,begin,Path[begin][temp]);
		printf("%s->",G.vexs[begin]);
	}
}

int main(void)
{
	int i=0, j=0;
	system("color F1");
	kaishi();
	system("pause");
	//G=(AMGraph)malloc(sizeof()); // ��ָ��,������ᷢ�����޷�д��ȥ��!!!
	printf("��ӭ����У԰����ͼ!\n");
	char start[10]={'\0'};
	char destination[10]={'\0'};
	int choose=1, num_start=0, num_destination=0;
	Create(G);
	for(i=0; i<MAX; i++)
	{
		for(j=0; j<MAX;j++)
		{
			//
			G.vexs[i][j]='\0';
		}
	}
	printf("\n");
	printf("У԰����ͼ�������!\n");
	ShortestPath(G);
	while(choose == 1)
	{
		printf("��������������:");
		gets(start);
		printf("�������յ������:");
		gets(destination);
		num_start=LocateVex(G,start);
		num_destination=LocateVex(G,destination);
		DisplayPath(G,num_start,num_destination);
		printf("%s\n",G.arcs[num_destination]);
		printf("�����ص�֮��ľ���Ϊ%d\n",D[num_start][num_destination]);
		printf("\n����1����,����������������\n");
		scanf("%d",&choose);
		printf("\n");
	}
	return 0;
}
