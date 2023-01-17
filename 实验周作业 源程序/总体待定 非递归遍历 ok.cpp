#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include "wangjie.h"


typedef struct node {//节点
	char data;
	struct node *lchild;
	struct node *rchild;
	struct node *father;
}Node ,*BiTree;
BiTree T;
Node *node;
int k=0;//k=0进入左孩子,k=1进入右孩子

int length=0;//记录总节点个数,用于形象输出判断
int dd=0;//判断树是否已经建立,建立的话就将dd=1;否则为零(并提示)
int ii=0;

typedef struct tree{//根节点
	Node *root;
}Tree;
Tree tree;


//以下为函数声明
//void InitStack(SeqStack *S);//置栈空
void PreOrderTraverse2(BiTree T);//前序非递归遍历
void PostOrderTraverse2(BiTree T);//后序非递归遍历
//void InOrderTraverse2(BiTree T);//中序非递归遍历
//int Push(SeqStack *S,DataType x);//进栈
//DataType Pop(SeqStack *S);//退栈
void insert(Tree *tree,char value);//写入树中数据
void ForTree(void);//建立一棵树
void menu(void);


int main(void)
{
	int tuichu=0, tuichu0=0;//=1时退出
	int choose0=0, xuanze=0, choose1=0;
	T=(BiTree)malloc(sizeof(BiTree));
	system("color F1");
	kaishi();
	system("pause");
	do{
kaishi:
		menu();
		scanf("%d",&choose0);
		switch(choose0)
		{
		case 1 :
			xuanze=1; goto chulai;
			break;
		case 2 :
			xuanze=2; goto chulai;
			break;
		case 3:
			xuanze=3; goto chulai;
			break;
		case 4:
			xuanze=4; goto chulai;
			break;
		case 5:
			xuanze=5; goto chulai;
			break;
		case 6:
			xuanze=6; goto chulai;
			break;
		case 7:
			xuanze=7; goto chulai;
			break;
		case 8:
			xuanze=8; goto chulai;
			break;
		case 9:
			xuanze=9; goto chulai;
			break;
		case 10:
			xuanze=10; goto chulai;
			break;
		case 11:
			xuanze=11; goto chulai;
			break;
		case 12:
			xuanze=12; goto chulai;
			break;
		case 13:
			xuanze=13; goto chulai;
			break;
		case 14:
			tuichu0=1;
			break;
		default :
			printf("输入有误,请重新输入!\n");
		}
	}while(tuichu0 == 1);
chulai:
	if(xuanze == 1)
	{
		//写二叉树的非递归遍历的东西……
		T=tree.root;//也就是代表T=node的一种外部写法
		printf("请先建立树\n");
		ForTree();
		do{
			printf("请选择非递归遍历种类\n");
			printf("1.先序遍历 2.后序遍历 3.中序遍历 4.退出\n");
			scanf("%d",&choose1);
			switch(choose1)
			{
			case 1:
				PreOrderTraverse2(tree.root);
				break;
			case 2:
				printf("不要意思!仍然在建立中!\n");
				//PostOrderTraverse2(tree.root);
				break;
			case 3:
				printf("不要意思!仍然在建立中!\n");
				//InOrderTraverse2(tree.root);
				printf("等下写\n");
				break;
			case 4:
				tuichu=1;
				break;
			default:
				printf("输入有误,请重新输入!\n");
			}
		}while(tuichu==1);
	}
	if(xuanze == 2)
	{
		//写校园导游图……
		printf("\n请退出单独查看校园导游图程序\n");
		printf("!!!建立中\n");
	}
	if(xuanze == 3)
	{
		printf("\n请退出单独查看运动会分数统计程序\n");
		//运动会分数统计
	}
	if(xuanze == 4)
	{
		printf("\n请退出单独查看一元多项式程序\n");
		//一元多项式计算
	}
	if(xuanze == 5)
	{
		printf("\n请退出单独查看迷宫求解\n");
		//迷宫求解
	}
	if(xuanze == 6)
	{
		printf("\n请退出单独查看文章编辑\n");
		//文章编辑
	}
	if(xuanze == 7)
	{
		printf("\n请退出单独查看joseph程序\n");
		//joseph环
	}
	if(xuanze == 8)
	{
		printf("\n请退出单独查看扑克牌游戏程序\n");
		//扑克牌游戏
	}
	if(xuanze == 9)
	{
		printf("\n请退出单独查看商品货架管理程序\n");
		//商品货架管理
	}
	if(xuanze == 10)
	{
		printf("\n请退出单独查看行文本编译器\n");
		//行文本编译器
	}
	if(xuanze == 11)
	{
		printf("\n请退出单独查看祖业调度程序\n");
		//作业调度
	}
	if(xuanze == 12)
	{
		printf("\n请退出单独查看教学计划编制问题\n");
		//教学计划编制问题
	}
	if(xuanze == 13)
	{
		printf("\n请退出单独查看航空客运订票系统\n");
		//航空客运订票系统
	}
	else{
		goto kaishi;
	}
	return 0;
}

void PreOrderTraverse2(BiTree T)//前序非递归遍历
{
	int keai=0, keai0=0;//为1就跳到另一个条件
	int dddd=0;
	BiTree p=NULL; //再次定义一个变量取代替真实树，防止树的结构体指针在运用完本程序后位置出现未知的错误
	p=(Node *)malloc(sizeof(Node));
	p=T;
	while (dddd != length/* || !StackEmpty(S)*/) //树的该位置不为空且此时的栈内也不为0
	{
		
		if(keai == 0 ){ // 如愿该位置不为空
			printf("%c\t",p->data);
			dddd++;
			if(p->lchild != NULL){
				p = p->lchild; //先序遍历 根>左孩子>右孩子 出现问题的地方，根本就不能出现这行代码出错的机会
				keai0=0;
			}
			else
				keai0=1;
			if(keai0 == 1){
				keai=1;
			}
		}
		else if(keai == 1)//进入的话说明此时 ***该位置的左孩子*** 上为空
		{
			//Pop(S); //出栈
			p=p->father;
			p = p->rchild;//左上为空，自然移动到右孩子上
			keai=0;
		}
	}
	//printf("此处的bug\n"); //顺利经过
	printf("\n");
	//cout << endl; 
}

/*void PostOrderTraverse2(BiTree T)//后序非递归遍历
{
	int dd=0;
	BiTree p=NULL, p1=NULL; //再次定义一个变量取代替真实树，防止树的结构体指针在运用完本程序后位置出现未知的错误
	p=(Node *)malloc(sizeof(Node));
	p1=(Node *)malloc(sizeof(Node));
	p1=p;//不会轻易改变量
	if(p1->lchild==NULL && p1->rchild==NULL){//只有树根的树特殊处理
		printf("%c\n",p1->data);
		p1->data='!';
		dd++;//好跳过后面的while循环
	}
	p1=p1->lchild;//先左结点起步
	while(dd != length)
	{
		if(p1->lchild==NULL || p1->data!='!')
		{
			if(p1->data != '!')//无左右结点,且未访问过
			{
				printf("%c",p1->data);
				dd++;
				p1->data='!';//标记
				p1=p1->father;//立马放回位置
			}
			if(p1->lchild== NULL)
			{
				p1=p1->father;
				if(p1->rchild!=NULL){
					p1=p1->rchild;
					printf("%c\t",p1->data);
					p1->data='!';//标记
					p1=p1->father;//返回位置
				}
			}
		}
		else if(p1->lchild != NULL)//条件:左结点不为空
		{
				while(p1->lchild != NULL)
					p1=p1->lchild;
				printf("%c\t",p1->data);
				p1->data='!';
				p1=p1->father;//返回位置
				dd++;			
		}
		else if (p1->rchild != NULL){//让右孩子先进入栈中,后出,所以符合后序遍历的规范
			while(p1->rchild != NULL)
				p1=p1->rchild;
			printf("%c\t",p1->data);
			p1->data='!';
			dd++;
			p1=p1->father;
		}
	}
	printf("\n");
}*/


void insert(Tree *tree,char value)//写入树中数据
{
	Node *node=(Node *)malloc(sizeof(Node)); //Node等价于*BiTree 则node == T 
	//p和T是一样，此时的T和node又是一样的
	node->data=value;//已经将指向数据的指针弄好了
	//printf("T->data=%c",T->data); //这一行说明T=node有效
	node->lchild=NULL;
	node->rchild=NULL;
	
	/*判断树是否为空*/
	if(tree->root == NULL)//是空树的话
	{
		tree->root=node;
	}
	else//不是空树的话
	{
		//左数小于根节点，右树大于根节点
		Node *temp = tree->root;//temp一直是那个根结点
		while(temp!=NULL)//进入这里的时候说明根结点已经有了
		{
			printf("请选择:(进入左边输入0,进入右边输入1):");
			scanf("%d",&k);
			if(k == 0)//进入左儿子
			{
				if(temp->lchild==NULL)//如果左结点还为空的话
				{
					temp->lchild=node;
					node->father=temp;
					return;
				}
				else
				{
					temp=temp->lchild;//换到下一层次
				}
			}
			else if(k == 1)//否则的话肯定是进入右儿子,即使是相等也是进入右儿子
			{
				if(temp->rchild==NULL)//如果右结点还是空的话
				{
					temp->rchild = node;
					node->father=temp;
					return;
				}
				else//否则就进入下一层次
				{
					temp=temp->rchild;
				}
			}
		}
	}
}

void ForTree(void)//建立一棵树
{
	int i  = 0;
	int n;//记录总结点数
	tree.root = NULL;
	printf("\n请输入一个数来确定树中结点的多少:");
	scanf("%d",&n);
	length=n;
	for(i=0;i<n;i++)
	{
		int temp;
		getchar();
		printf("\n请输入一个数来填入第%d个节点:",i+1);
		scanf("%c",&temp);
		insert(&tree,temp);
	}
	printf("\n建立完成!\n");
	printf("\n");
}
void menu(void)
{
	printf(" \n请选择:\n");
	printf(" 1.二叉树的非递归遍历	2.校园导游图 \n");
	printf(" 3.运动会分数统计	4.一元多项式计算 \n");
	printf(" 5.迷宫求解		6.文章编辑 \n");
	printf(" 7.joseph环		8.扑克牌游戏 \n");
	printf(" 9.商品货架管理		10.行文本编译器 \n");
	printf(" 11.作业调度		12.教学计划编制问题 \n");
	printf(" 13.航空客运订票系统 14.退出\n");
}

