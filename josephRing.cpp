#include <stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct Node
{
	int code;
	int psword;
	struct Node *next; 
}Node;
void InitRing(Node *&L,int n)
{
	L=(Node *)malloc(sizeof(Node));
	L->next=NULL;
	int i,p;
	Node *s,*r;
	r=L;
	printf("请按顺序输入%d个密码",n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p);
		s=(Node *)malloc(sizeof(Node));
		s->code=i;
		s->psword=p;
		r->next=s;
		r=s;
		
	}
	s->next=L->next;
}

void DelNode (Node *L,int m,int n)
{
	Node *s,*r,*t;
	int flag,i,q,p;
	s=L;
	
	for(flag=n;flag>=1;flag--)
	{
		i=1;
		while(i<m)
		{
			s=s->next;
			i++;
		
		}
		
		r=s->next;
		s->next=r->next;
		q=r->code;
		m=r->psword;
		free(r);
		printf("%d ",q);
	}
	
}

void main()
{
	Node *L;
	int m,n;
	printf("请输入m和n的值\n");
	scanf("%d %d",&m,&n);
	InitRing(L,n);
	DelNode (L,m,n);

}