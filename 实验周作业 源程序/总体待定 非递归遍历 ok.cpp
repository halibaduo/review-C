#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include "wangjie.h"


typedef struct node {//�ڵ�
	char data;
	struct node *lchild;
	struct node *rchild;
	struct node *father;
}Node ,*BiTree;
BiTree T;
Node *node;
int k=0;//k=0��������,k=1�����Һ���

int length=0;//��¼�ܽڵ����,������������ж�
int dd=0;//�ж����Ƿ��Ѿ�����,�����Ļ��ͽ�dd=1;����Ϊ��(����ʾ)
int ii=0;

typedef struct tree{//���ڵ�
	Node *root;
}Tree;
Tree tree;


//����Ϊ��������
//void InitStack(SeqStack *S);//��ջ��
void PreOrderTraverse2(BiTree T);//ǰ��ǵݹ����
void PostOrderTraverse2(BiTree T);//����ǵݹ����
//void InOrderTraverse2(BiTree T);//����ǵݹ����
//int Push(SeqStack *S,DataType x);//��ջ
//DataType Pop(SeqStack *S);//��ջ
void insert(Tree *tree,char value);//д����������
void ForTree(void);//����һ����
void menu(void);


int main(void)
{
	int tuichu=0, tuichu0=0;//=1ʱ�˳�
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
			printf("��������,����������!\n");
		}
	}while(tuichu0 == 1);
chulai:
	if(xuanze == 1)
	{
		//д�������ķǵݹ�����Ķ�������
		T=tree.root;//Ҳ���Ǵ���T=node��һ���ⲿд��
		printf("���Ƚ�����\n");
		ForTree();
		do{
			printf("��ѡ��ǵݹ��������\n");
			printf("1.������� 2.������� 3.������� 4.�˳�\n");
			scanf("%d",&choose1);
			switch(choose1)
			{
			case 1:
				PreOrderTraverse2(tree.root);
				break;
			case 2:
				printf("��Ҫ��˼!��Ȼ�ڽ�����!\n");
				//PostOrderTraverse2(tree.root);
				break;
			case 3:
				printf("��Ҫ��˼!��Ȼ�ڽ�����!\n");
				//InOrderTraverse2(tree.root);
				printf("����д\n");
				break;
			case 4:
				tuichu=1;
				break;
			default:
				printf("��������,����������!\n");
			}
		}while(tuichu==1);
	}
	if(xuanze == 2)
	{
		//дУ԰����ͼ����
		printf("\n���˳������鿴У԰����ͼ����\n");
		printf("!!!������\n");
	}
	if(xuanze == 3)
	{
		printf("\n���˳������鿴�˶������ͳ�Ƴ���\n");
		//�˶������ͳ��
	}
	if(xuanze == 4)
	{
		printf("\n���˳������鿴һԪ����ʽ����\n");
		//һԪ����ʽ����
	}
	if(xuanze == 5)
	{
		printf("\n���˳������鿴�Թ����\n");
		//�Թ����
	}
	if(xuanze == 6)
	{
		printf("\n���˳������鿴���±༭\n");
		//���±༭
	}
	if(xuanze == 7)
	{
		printf("\n���˳������鿴joseph����\n");
		//joseph��
	}
	if(xuanze == 8)
	{
		printf("\n���˳������鿴�˿�����Ϸ����\n");
		//�˿�����Ϸ
	}
	if(xuanze == 9)
	{
		printf("\n���˳������鿴��Ʒ���ܹ������\n");
		//��Ʒ���ܹ���
	}
	if(xuanze == 10)
	{
		printf("\n���˳������鿴���ı�������\n");
		//���ı�������
	}
	if(xuanze == 11)
	{
		printf("\n���˳������鿴��ҵ���ȳ���\n");
		//��ҵ����
	}
	if(xuanze == 12)
	{
		printf("\n���˳������鿴��ѧ�ƻ���������\n");
		//��ѧ�ƻ���������
	}
	if(xuanze == 13)
	{
		printf("\n���˳������鿴���տ��˶�Ʊϵͳ\n");
		//���տ��˶�Ʊϵͳ
	}
	else{
		goto kaishi;
	}
	return 0;
}

void PreOrderTraverse2(BiTree T)//ǰ��ǵݹ����
{
	int keai=0, keai0=0;//Ϊ1��������һ������
	int dddd=0;
	BiTree p=NULL; //�ٴζ���һ������ȡ������ʵ������ֹ���Ľṹ��ָ���������걾�����λ�ó���δ֪�Ĵ���
	p=(Node *)malloc(sizeof(Node));
	p=T;
	while (dddd != length/* || !StackEmpty(S)*/) //���ĸ�λ�ò�Ϊ���Ҵ�ʱ��ջ��Ҳ��Ϊ0
	{
		
		if(keai == 0 ){ // ��Ը��λ�ò�Ϊ��
			printf("%c\t",p->data);
			dddd++;
			if(p->lchild != NULL){
				p = p->lchild; //������� ��>����>�Һ��� ��������ĵط��������Ͳ��ܳ������д������Ļ���
				keai0=0;
			}
			else
				keai0=1;
			if(keai0 == 1){
				keai=1;
			}
		}
		else if(keai == 1)//����Ļ�˵����ʱ ***��λ�õ�����*** ��Ϊ��
		{
			//Pop(S); //��ջ
			p=p->father;
			p = p->rchild;//����Ϊ�գ���Ȼ�ƶ����Һ�����
			keai=0;
		}
	}
	//printf("�˴���bug\n"); //˳������
	printf("\n");
	//cout << endl; 
}

/*void PostOrderTraverse2(BiTree T)//����ǵݹ����
{
	int dd=0;
	BiTree p=NULL, p1=NULL; //�ٴζ���һ������ȡ������ʵ������ֹ���Ľṹ��ָ���������걾�����λ�ó���δ֪�Ĵ���
	p=(Node *)malloc(sizeof(Node));
	p1=(Node *)malloc(sizeof(Node));
	p1=p;//�������׸ı���
	if(p1->lchild==NULL && p1->rchild==NULL){//ֻ�������������⴦��
		printf("%c\n",p1->data);
		p1->data='!';
		dd++;//�����������whileѭ��
	}
	p1=p1->lchild;//��������
	while(dd != length)
	{
		if(p1->lchild==NULL || p1->data!='!')
		{
			if(p1->data != '!')//�����ҽ��,��δ���ʹ�
			{
				printf("%c",p1->data);
				dd++;
				p1->data='!';//���
				p1=p1->father;//����Ż�λ��
			}
			if(p1->lchild== NULL)
			{
				p1=p1->father;
				if(p1->rchild!=NULL){
					p1=p1->rchild;
					printf("%c\t",p1->data);
					p1->data='!';//���
					p1=p1->father;//����λ��
				}
			}
		}
		else if(p1->lchild != NULL)//����:���㲻Ϊ��
		{
				while(p1->lchild != NULL)
					p1=p1->lchild;
				printf("%c\t",p1->data);
				p1->data='!';
				p1=p1->father;//����λ��
				dd++;			
		}
		else if (p1->rchild != NULL){//���Һ����Ƚ���ջ��,���,���Է��Ϻ�������Ĺ淶
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


void insert(Tree *tree,char value)//д����������
{
	Node *node=(Node *)malloc(sizeof(Node)); //Node�ȼ���*BiTree ��node == T 
	//p��T��һ������ʱ��T��node����һ����
	node->data=value;//�Ѿ���ָ�����ݵ�ָ��Ū����
	//printf("T->data=%c",T->data); //��һ��˵��T=node��Ч
	node->lchild=NULL;
	node->rchild=NULL;
	
	/*�ж����Ƿ�Ϊ��*/
	if(tree->root == NULL)//�ǿ����Ļ�
	{
		tree->root=node;
	}
	else//���ǿ����Ļ�
	{
		//����С�ڸ��ڵ㣬�������ڸ��ڵ�
		Node *temp = tree->root;//tempһֱ���Ǹ������
		while(temp!=NULL)//���������ʱ��˵��������Ѿ�����
		{
			printf("��ѡ��:(�����������0,�����ұ�����1):");
			scanf("%d",&k);
			if(k == 0)//���������
			{
				if(temp->lchild==NULL)//������㻹Ϊ�յĻ�
				{
					temp->lchild=node;
					node->father=temp;
					return;
				}
				else
				{
					temp=temp->lchild;//������һ���
				}
			}
			else if(k == 1)//����Ļ��϶��ǽ����Ҷ���,��ʹ�����Ҳ�ǽ����Ҷ���
			{
				if(temp->rchild==NULL)//����ҽ�㻹�ǿյĻ�
				{
					temp->rchild = node;
					node->father=temp;
					return;
				}
				else//����ͽ�����һ���
				{
					temp=temp->rchild;
				}
			}
		}
	}
}

void ForTree(void)//����һ����
{
	int i  = 0;
	int n;//��¼�ܽ����
	tree.root = NULL;
	printf("\n������һ������ȷ�����н��Ķ���:");
	scanf("%d",&n);
	length=n;
	for(i=0;i<n;i++)
	{
		int temp;
		getchar();
		printf("\n������һ�����������%d���ڵ�:",i+1);
		scanf("%c",&temp);
		insert(&tree,temp);
	}
	printf("\n�������!\n");
	printf("\n");
}
void menu(void)
{
	printf(" \n��ѡ��:\n");
	printf(" 1.�������ķǵݹ����	2.У԰����ͼ \n");
	printf(" 3.�˶������ͳ��	4.һԪ����ʽ���� \n");
	printf(" 5.�Թ����		6.���±༭ \n");
	printf(" 7.joseph��		8.�˿�����Ϸ \n");
	printf(" 9.��Ʒ���ܹ���		10.���ı������� \n");
	printf(" 11.��ҵ����		12.��ѧ�ƻ��������� \n");
	printf(" 13.���տ��˶�Ʊϵͳ 14.�˳�\n");
}

