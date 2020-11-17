#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	char data;
	struct Node *lchild;
	struct Node *rchild;
}*BiTree,BiNode;

void CreatBiTree(BiNode *&bt)
{
	char ch;
	ch=getchar();
	if(ch=='*')
		bt=NULL;
	else
	{
		bt=(BiTree)malloc(sizeof(BiNode));
		bt->data=ch;
		CreatBiTree(bt->lchild);
		CreatBiTree(bt->rchild);
	}
}

void PreOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		printf("%c",bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}

}

void InOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		InOrder(bt->lchild);
		printf("%c",bt->data);
		InOrder(bt->rchild);
	}
}

void PostOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf("%c",bt->data);
	}
}

void main()
{
	BiTree root;
	printf("���������У�");
	CreatBiTree(root);
	printf("���������\n");
	PreOrder(root);
	printf("\n���������\n");
	InOrder(root);
	printf("\n���������\n");
	PostOrder(root);
	printf("\n");
}