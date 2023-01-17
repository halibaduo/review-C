//目的,将别人的非递归遍历搞明白
//层次遍历输入 成树
#include <stdio.h>
#include <stdlib.h>
#include "wangjie.h"
#define N 20
 
//二叉树结点的结构体表示形式
typedef struct tree
{
    char ch;//结点元素
    struct tree *lchild;//左结点
	struct tree *rchild;//右结点
}BitTree;
 
//创建二叉树，利用递归的方法
//按前序次序输入。 如 A # #(#表示空树)
BitTree *CreateTree(void)//创建二叉树的函数 采用了递归的方式去创建二叉树 
{
	BitTree *bt;
	bt=(BitTree *)malloc(sizeof(BitTree));//申请动态空间
    char ch1;
	fflush(stdin);//有个缓冲区没有解决呢！！！
	//getchar(); //如果此处是写getchar()的话不是读取了回车 而是字符
    scanf("%c",&ch1);
    if (ch1 == '#')
        return NULL;
    else
    {
        bt->ch=ch1;
        bt->lchild=CreateTree();//左节点
        bt->rchild=CreateTree();//右节点
        return bt;
    }
}
 
//前序遍历的非递归实现
/*
 思想：利用栈来实现；根结点进栈，之后栈非空，弹出，接着根节点的右结点进栈，
 之后，左节点进栈；接着，弹出栈顶元素（输出）,
 此结点的右结点进栈，之后左节点进栈，弹出栈顶元素（输出）...一直这样下去，
 直到栈为空。
 */
void PreOrder(BitTree *bt) //前序遍历
{
    BitTree **s;//特殊的建立栈的方式00
	//指向指针的指针也就是说可以做储存指针的数组
	BitTree *p;
	int top=-1; 
	//创建栈；
	s=(BitTree **)malloc((N+1)*sizeof(BitTree *));
	//初始化栈;
	s[++top]=bt;
	//非递归前序遍历;
	while(top!=-1)//先将“根”结点输出,再讨论其它
	{
		p=s[top--];
		printf("%c\t",p->ch);    //栈的特点，先进后出；
		if(p->rchild)//先进后出,所以右节点先进栈，再是左节点进栈
			s[++top]=p->rchild;//右结点进栈操作 （结点为指针）
		if(p->lchild)
			s[++top]=p->lchild;//左结点进栈操作 （结点为指针）
	}
	free(s);
}
 
 
//中序遍历，非递归实现
/*
 思想：利用栈。从根节点开始循环，只要有左子节点则进栈，直到左子节点为空。
 接着弹出栈顶输出，判断该结点是否有右子节点，
 若有则进栈，若没有继续弹栈。有右子节点的情况，判断该节点是否有左子节点，
 有则进栈，直到左子节点为空；若该右子节点没有
 左子节点，则弹栈；判断弹出的节点，是否有右子节点，若有则进栈，没有继续弹栈；
 接着又要判断刚进栈的这个节点，是否有左子节点，
 有则进栈，没有则继续弹栈。重复下去....
 栈空，是判定条件。
 */
void InOrder(BitTree *bt) //左节点一溜烟下去就对了，再来判断右节点 逻辑太厉害了！！！
{
	BitTree **s;
    BitTree *p,*q; //后进先出,也是用栈
    int top=-1;
	//创建栈；
	s=(BitTree **)malloc((N+1)*sizeof(BitTree *));
	//非递归中序遍历；
    if(bt)
    {
        while(bt)   //一直遍历左子树直到该结点的左孩子空为止；
        {
            s[++top]=bt;   //将所有左孩子存入栈中；
            bt=bt->lchild;     //指向下一个左子树；
        }
        while(top!=-1)  //栈空时结束循环；
        {
            p=s[top--];//刚开始将最p指向左下角的左孩子，并且移向该结点的父结点；
            printf("%c\t",p->ch);  //输出左下角的结点；
            while(p->rchild)  //遍历移动后结点有没有右结点;如果拥有的话 -- “是先输出的”
            {//上一行判断为该结点是否有可能已经是中结点了，所以可能还需要右结点输出
                s[++top]=p->rchild;   //将这个结点的右子树入栈；
                q=p->rchild;		  //这个右子树结点赋给q；
                while(q->lchild)      //判断结点q有没有左子树； 也就是说这个结点有可能又是个有
                {
                    s[++top]=q->lchild;  //有左子树，将与这个结点相连的所有左子树都入栈；
                    q=q->lchild;
                }
                break;   //结束当前循环，回到第二个while循环继续刚才的步骤；
            }
        }
    }
}
 
//后序遍历，非递归实现
/*
 算法思想:利用栈来实现。从根结点开始,只要左子节点非空,则进栈,直到左子节点
 为空为止。取出栈顶元素(只是取,并非弹栈),判断:
 1:取出的栈顶元素是否有右子节点,或者右子节点是否被访问过,若满足条件(无右子
 节点,或者右子节点被访问过),则输出该结点，同时弹栈,并且记录下该访问的节点。
 2:取出的栈顶元素，若有右子节点，且未被访问过，则指针继续移动到右子节点，
 重复一开始是否又左子节点的判断。
*/
void PostOrder(BitTree *bt) // -- 左右中 --
{	
	BitTree **s;
	BitTree *p;
    int top=-1;
	//创建栈；
	s=(BitTree **)malloc((N+1)*sizeof(BitTree *));
	//非递归后序遍历；
    do
    {
        while(bt)     //一直遍历左子树直到该左子树的左孩子空为止；和上一个一样的逻辑
        {
            s[++top]=bt;     //将所有左孩子存入栈中；
            bt=bt->lchild;   //指向下一个左子树；
        }
        p=NULL;
        while(top!=-1)
        {
            bt=s[top];
            if(bt->rchild==p)  //p:表示为null，或者右子节点被访问过了; //“为母则刚”;
            {
                printf("%c\t",bt->ch);   //输出结点数据域;
                top--;           //输出以后，top--;
                p=bt;  //p记录下刚刚访问的节点;
            }
            else
            {
                bt=bt->rchild;   //访问右子树结点;
                break;//跳出本程序的while
            }
        }
    }while(top!=-1);
}
 
int main(void)
{
	system("color F1");
	kaishi();
	system("pause");
    printf("请以顺序输入二叉树(#表示该结点的子结点为空)(先左结点后右结点):\n");
    BitTree *btr;
	btr=(BitTree *)malloc(sizeof(BitTree));
	btr=CreateTree();
    printf("前序遍历非递归实现：\n");
    PreOrder(btr);
    printf("\n");
    printf("中序遍历非递归实现：\n");
    InOrder(btr);
    printf("\n");
    printf("后序遍历非递归实现：\n");
    PostOrder(btr);
    printf("\n");
    return 0;
}