#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 50

typedef struct 
{
	char elem[MAXSIZE];
	int top;
}seqstack;


void InitStack(seqstack *&S)
{
	S=(seqstack*)malloc(sizeof(seqstack));
	S->top=-1;
}


 int Push(seqstack *S)
 {
	 char c;
	 rewind(stdin);
	 printf("�������ַ�����");
	 c=getchar();
	 while(c!='&')
	 {
		 if(S->top==MAXSIZE-1||c=='\n')
		 {
			printf("�����ַ������Ϸ�\n");
			S->top=-1;
			Push(S);
			 return 0;
		 }
		 S->top++;
		 S->elem[S->top]=c;
		 c=getchar();
	 }
	 return true;
 }

 
 int compare(seqstack *S)
 {
	 char a,b;
	 a=getchar();
	 while(a!='@')
	 {
		 if(a=='&')
		 {
			 printf("�����ַ������Ϸ�\n");
			 S->top=-1;
			 Push(S);
			 return compare(S);
		 }

		 if(S->top==-1)
			 return 1;

		 b=S->elem[S->top];
		 S->top--;

		 if(a!=b)
			 return 1;
		
		a=getchar();
	 }

	 if(S->top>=0)
		 return 1;
	 
	 else 
		 return 0;

 }

 int main()
 {
	 seqstack *S;
	 InitStack(S);
	 Push(S);
	 if(compare(S))
		 printf("���ַ������ǻ���");
	 else
		 printf("���ַ����ǻ���");
		 return 0;

 }