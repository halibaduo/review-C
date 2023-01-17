//校园导游图
/*原理: 创建一个结构体 结构体里面储存顶点信息,一个二维数组,一维下标,和二维下标分别代表起点与终点 顶点数和边数
运用一个行数去记录下一维的下标,在求最短路径的时候,就如此，将前驱下标改变,从而知道了该如何走
每条边的权值就用来储存地点之间的距离
*/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "wangjie.h"

#define MAX 30//最多30个地址暂时
#define MAXINT 32451//权值的最大值 

typedef struct{
	char vexs[MAX][MAX];//一维放数
	int arcs[MAX][MAX];//起终点
	int vexnum;//当前点数
	int	arcnum;//当前边数
}AMGraph;
AMGraph G;

int Path[MAX][MAX];//记录前一序号
int D[MAX][MAX];//记录最短路径


int LocateVex(AMGraph G,char* vexs);//获取地点的一维下标
void Create(AMGraph G);//创建
void ShortestPath(AMGraph G);
void DisplayPath(AMGraph G,int begin,int temp);



int LocateVex(AMGraph G,char* vexs)
{
	//
	int i=0;
	for(i=0; i<G.vexnum; i++)
	{
		if(strcmp(G.vexs[i], vexs) == 0) return i;//找到了就返回他的一维下标
	}
	return -1;//否则返回-1
}

void Create(AMGraph G)//创建
{
	//
	int i=0, j=0;
	char xuanze[10]={'\0'};
	char name1[10]={'\0'};//两个地点,并初始化
	char name2[10]={'\0'};
	printf("请输入总地点数:");
	scanf("%d",&G.vexnum);
	printf("\n请输入当前总可通行的边数:");
	scanf("%d",&G.arcnum);
	printf("\n接下来请输入标点数的名称!\n");
	for(i=0; i<G.vexnum; i++)
	{
		printf("请输入第%d个地点的名称:",i+1);
		getchar();
		gets(G.vexs[i]);//就相当于将第i+1行用来开始储存
		printf("\n");
	}
	for(i=0; i<G.vexnum; i++){
		for(j=0; j<G.vexnum; j++)
		{
			if(i != j)
				G.arcs[i][j]=MAXINT;//每一个地点之间的距离初始化为最大值MAXINT
			else
				G.arcs[i][j]=0;//自己到自己肯定为0吧!
		}
	}
	printf("接下来输入各个地点的距离（权值）!\n");
	for(i=0; i<G.vexnum; i++)
		for(j=0; j<G.vexnum; j++)
		{
			if(i != j){
				printf("请问第%d个地点（%s）于第%d个顶点（%s）之间有通路吗？（yes or no）\n",i+1,G.vexs[i],j+1,G.vexs[j]);
				printf("请输入:");
				gets(xuanze);
				if( strcmp(xuanze,"yes") == 0 || strcmp(xuanze,"YES") == 0 )
				{
					printf("\n那么请输入这两个地点之间的距离:");
					scanf("%d",&G.arcs[i][j]);
					G.arcs[j][i]=G.arcs[i][j];//无向图,也就是说两边都可以通过 双向通道
				}
				else
				{
					printf("好的,请准备好回答下一个问题!\n");
				}
			}
			else
				printf("第%d个到第%d个地点,当然不用说可以的，哈哈哈\n",i+1,j+1);
		}
}
//接下来才是重要代码
void ShortestPath(AMGraph G)
{
	int i=0, j=0, k=0;
	for(i=0; i<G.vexnum; i++)
	{
		for(j=0; j<G.vexnum; j++)
		{
			D[i][j]=G.arcs[i][j];//用另外的二维数组D[][]来记录下两个地点之间的最短距离
			if(D[i][j] < MAXINT && i!=j)
				Path[i][j]=i;
			else
				Path[i][j]=-1;//否则就记录为-1
		}
	}
	for(k=0; k<G.vexnum; k++)//细节:变量k放在最外层
	{
		for(i=0; i<G.vexnum; i++)
		{
			for(j=0; j<G.vexnum; j++)
			{
				if(D[i][k]+D[k][j] < D[i][j]){//细节:k放在最外面的for循环
					D[i][j]=D[i][k]+D[k][j];//分段走路径要小于两个地点直接相通路径
					Path[i][j]=Path[k][j];//将前一下标换为、就k、j的
				}
			}
		}
	}
}

void DisplayPath(AMGraph G,int begin,int temp)
{
	if(Path[begin][temp] != -1)//不为-1就说明之间存在通路
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
	//G=(AMGraph)malloc(sizeof()); // 非指针,所以你会发现你无法写下去了!!!
	printf("欢迎来到校园导游图!\n");
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
	printf("校园导游图建立完成!\n");
	ShortestPath(G);
	while(choose == 1)
	{
		printf("请输入起点的名称:");
		gets(start);
		printf("请输入终点的名称:");
		gets(destination);
		num_start=LocateVex(G,start);
		num_destination=LocateVex(G,destination);
		DisplayPath(G,num_start,num_destination);
		printf("%s\n",G.arcs[num_destination]);
		printf("两个地点之间的距离为%d\n",D[num_start][num_destination]);
		printf("\n输入1结束,输入其他的数结束\n");
		scanf("%d",&choose);
		printf("\n");
	}
	return 0;
}
