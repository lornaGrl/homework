#include <stdio.h>
#include<string.h>
#include <stdlib.h>

#define MaxSize 100
 
typedef struct 
{
    char name[20];
    char tel[15];
} ElemType;
typedef struct 
{
    ElemType data[MaxSize];
     int length;
} SqList;
 
void InitList(SqList *&L) 
{
    L=(SqList *)malloc(sizeof(SqList));    
    L->length=0;                     
}
 
void DispList(SqList *L)  
{
    int i;
    printf("  NO           NAME           TEL   \n");
    for (i=0;i<L->length;i++)
    {
        printf("  %d           %s      %s",i+1,L->data[i].name,L->data[i].tel);
        printf("\n");
        
    }
 
    printf("Ŀǰ��ϵ��������%d\n",L->length);
        printf("\n"); 
}
 
bool ListInsert(SqList *&L,int i,ElemType e)    
{
    int j;
    if(e.name=="\0") return false;
    
	i--;                        
    for (j=L->length;j>i;j--)    
      L->data[j]=L->data[j-1];
        
    L->data[i]=e;                
    L->length++;             
    return true;               
}
 
bool ListDelete(SqList *&L,int i,ElemType &e)   
{
    int j;
   
    i--;                        
    e=L->data[i];
    for (j=i;j<L->length-1;j++)  
    {  L->data[j]=L->data[j+1];
       }
    L->length--;    
    return true;               
}
 
void menu1()
{ printf("       -----------------------------------\n");
  printf("             �ҵ�ͨѶ¼\n");
  printf("       -----------------------------------\n");
  printf("            1.������ϵ����Ϣ\n");
  printf("            2.��ʾ��ϵ����Ϣ\n");
  printf("            3.ɾ����ϵ����Ϣ\n");
  printf("            4.������������ϵ����Ϣ\n");
  printf("            5.�����������ϵ����Ϣ\n");
  printf("            6.�˳�\n");
  printf("       -----------------------------------\n\n");
}
 
int LocateElem(SqList *L, ElemType e)
  {   int i=0;
    while ( i<L->length && strcmp(L->data[i].name,e.name)!=0)
       i++;
    if ( i>=L->length )  
        return 0;
    else 
    {  puts(L->data[i].name);
       puts(L->data[i].tel);
       
        return( i+1 );
  }
 
}
int LocateElemtel(SqList *L, ElemType e)
  {   int i=0;
    while ( i<L->length && strcmp(L->data[i].tel,e.tel)!=0)
       i++;
    if ( i>=L->length )  
        return 0;
    else 
    {  puts(L->data[i].name);
       puts(L->data[i].tel);
        printf("%s,%s\n",L->data[i].name,L->data[i].tel);
        return( i+1 );
  }
 
}
void main()
{
    SqList *L;
    int flag=1;
    int  j,i;
    ElemType e;
   
    InitList(L);
    DispList(L);
    while(flag==1)
    {   menu1();
      printf("��ѡ��");
      scanf("%d",&j);
      switch(j)
      {  
      case 1: printf("��������ϵ�������͵绰�ţ�");   
                scanf("%s %s",e.name,e.tel);
              printf("������������ݵ�λ�ã�"); 
              scanf("%d",&i);
			  while (i<1 || i>L->length+1)
    {
				  printf("��λ�ò��ɲ��룬����������λ�ã�\n");
				  scanf("%d",&i);
	}         
               fflush(stdin); 
                printf("\n");
               ListInsert(L,i,e);
                break;
      case 2:   DispList(L);
                break;
      case 3:  printf("������ɾ�����ݵ�λ�ã�"); 
               scanf("%d",&i); 
			   while (i<1 || i>L->length)     
			   {
				   printf("��λ����ϢΪ�գ�������ѡ��λ�ã�");
				   scanf("%d",&i);
			   }
               ListDelete(L,i,e);
               break;
       case 4:   printf("��������Ҫ���ҵ���ϵ��������"); 
                 scanf("%s",&e.name);
                 LocateElem(L,e);
                 break;
	   case 5: printf("��������Ҫ���ҵ���ϵ�˺���");
				   scanf("%s",&e.tel);
		   LocateElem(L,e);
		   break;
       case 6:  flag=0;
                printf("\n    �˳��ɹ���\n\n");
                break;
 
      }
    }
 
}