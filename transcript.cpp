#include <stdio.h>
#include <stdlib.h>
struct   student
{
	int stuid;
	char name[20];
	int mark;
}data[10000];
int stucount=0;
void idQuickSort(int left,int right);
void markQuickSort(int left,int right);
void listOfPlanes();
void menu();
void input();


void idQuickSort(int left,int right)
{
	int i, j;
	student t, temp;
	if (left > right)
		return;
	temp = data[left]; 
	i = left;
	j = right;
	while (i != j)
	{
		while (data[j].stuid >= temp.stuid && i < j)
			j--;
		while (data[i].stuid<= temp.stuid && i < j)
			i++;
		if (i < j)
		{
			t = data[i];
			data[i] = data[j];
			data[j] = t;
		}
	}
	data[left] = data[i];
	data[i] = temp;
	idQuickSort(left, i - 1);
	idQuickSort(i + 1, right);
}
void markQuickSort(int left,int right)
{
		int i, j;
	student t, temp;
	if (left > right)
		return;
	temp = data[left]; 
	i = left;
	j = right;
	while (i != j)
	{
		while (data[j].mark <= temp.mark && i < j)
			j--;
		while (data[i].mark>= temp.mark && i < j)
			i++;
		if (i < j)
		{
			t = data[i];
			data[i] = data[j];
			data[j] = t;
		}
	}
	data[left] = data[i];
	data[i] = temp;
	markQuickSort(left, i - 1);
	markQuickSort(i + 1, right);
}

void listOfPlanes()
{
	printf("学号     姓名   分数\n");
int i;
for(i=0;i<stucount;i++)
printf(" %d %s %d\n", data[i].stuid,data[i].name,data[i].mark);
menu();
}

void menu()
{
	int n;
	printf("+------鲜橙学生成绩系统------+\n");
	printf("|     1.输入       |\n");
	printf("|     2.学号排序   |\n");
	printf("|     3.成绩排序   |\n");
	printf("|     4.退出       |\n");
	printf("+----------------------------------+\n");
	rewind(stdin);
	printf("请输入操作指令:");
	scanf("%d", &n);
	switch(n)
	{
	case 1:
		input();
		break;
	case 2:
		idQuickSort(0,stucount-1);
		listOfPlanes();
		break;
	case 3:
		markQuickSort(0,stucount-1);
		listOfPlanes();
	case 4:	
		break;
	default:
		printf("输入错误，请重新输入\n");
		menu();
		break;
	}

}
void input()
{
	int n;
	printf("请输入学生学号，姓名，分数：");
	scanf("%d %s %d",&data[stucount].stuid,data[stucount].name,&data[stucount].mark);
	stucount ++;
    rewind(stdin);
	printf("已输入%d个学生数据，继续输入请按1，结束输入请按0.",stucount);
    scanf("%d", &n);
	if(n) 
		input();
	else
		menu();
}
 int main()
 {
	 menu();
	 return 0;
 }