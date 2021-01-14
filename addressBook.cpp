#include<stdio.h>
#include<stdlib.h>
#include <string.h>
FILE *fp;
struct info
{
	char name[20];
    char gender[8];
	char tel[12];
	char city[15];
	char eip[15];
}data[500];

int count=0;

void menu();

int readData();

int writeData();

void Add();

void List();

void Search();

void namesearch();

void telsearch();

void Delete();

void Alter();

void Quit();

void menu()
{
	int a;
	printf("-------telephone address book-------\n");
	printf("      |1.create new contact   |\n");
	printf("      |2.disply the list      |\n");
	printf("      |3.search               |\n");
	printf("      |4.delete               |\n");
	printf("      |5.alter                |\n");
	printf("      |6.quit                 |\n");
	printf("------------------------------------\n");
	printf("please input the command:");
	scanf("%d",&a);
	switch(a)
	{
	case 1:
			Add();     //新建
			break;
	case 2:
			List();    //显示通讯录
			break;
	case 3:
			Search();     //查找
			menu();
			break;
	case 4:
			Delete();    //删除
			break;
	case 5:
			Alter();      //修改
			break;
	case 6:
			Quit();       //退出
			break;
	default :
		printf("error!please input again!\n");
		menu();
		break;
	}

}



int readData() //读取文件
{
	int i=0;
	if ((fp = fopen("contacts.txt", "r+")) == NULL)
	{
		return 0;
	}

	while (~fscanf(fp, "%s %s %s %s %s",data[i].name,data[i].gender,data[i].tel,data[i].city,data[i].eip))
	{
		i++;
		count++;
	}
	fclose(fp);
	return 0;
}



int writeData()//写入文件
{
	int i;
	if ((fp = fopen("contacts.txt", "w")) == NULL)
	{
		return 0;
	}
	for(i=0;i<count;i++)
	{
		fprintf(fp, "%s %s %s %s %s \n",data[i].name,data[i].gender,data[i].tel,data[i].city,data[i].eip);
	}
	fclose(fp);
	return 0;
}



void Add()
{
	printf("Please enter the contact's name, gender,phone numbere, city and postcode:\n");

	scanf("%s %s %s %s %s",data[count].name,data[count].gender,data[count].tel,data[count].city,data[count].eip);

	count++;
	
	printf("%d contact(s) has been entered. Please press 1 to continue input or 0 to finish input:",count);

	int a;

	scanf("%d",&a);

	if(a)

	{
		Add();

	}
	else
	{
		writeData();
		menu();
	}
}



void List()
{
	int i;

	printf("name    gender  phone numbe     city    postcoder\n");

	for(i=0;i<count;i++)
	{
		printf("%s\t%s\t%s\t%s\t%s\t\n",data[i].name,data[i].gender,data[i].tel,data[i].city,data[i].eip);
	}
	menu();
}



void Search()
{
	int a;
	
	printf("   1.search by name    2.search by phone number\nyour choice:");
	scanf("%d",&a);
	
	switch(a)
	{
	case 1:
		namesearch();
		break;
	case 2:
        telsearch();
		break;
	}

}



void namesearch()
{
	char b[20];
	int i,c;
	c=0;
	printf("please enter the name of the contact which you want to search for:");
		scanf("%s",&b);
		for(i=0;i<count;i++)
		{
			if(strcmp(data[i].name,b)==0)
			{			
				printf("name    gender  phone numbe     city    postcoder\n");	
				printf("%s\t %s\t %s\t\t %s\t\t %s\t\n",data[i].name,data[i].gender,data[i].tel,data[i].city,data[i].eip);
				c++;
			}
		}
		if(c==0)
	
			printf("There is no information about this contact.\n");
}


void telsearch()
{
	char b[12];
	int i,c=0;
	printf("please enter the phone number of the contact which you want to search for:");
	scanf("%s",b);
	for(i=0;i<count;i++)
	{
		if(strcmp(data[i].tel,b)==0)
		{
			printf("name    gender  phone numbe     city    postcoder\n");	
			printf("%s\t %s\t %s\t\t %s\t %s\t\n",data[i].name,data[i].gender,data[i].tel,data[i].city,data[i].eip);
			c++;
		}
	}
		if(c==0)
		{
			printf("There is no information about this contact.");
		}

}



void Delete()
{
	int i,j,b=0;
	char a[20];
	printf("please enter the name of the contact which you want to delete:");
	scanf("%s",a);
	for(i=0;i<count;i++)
	{
		if(strcmp(data[i].name,a)==0)
	{
			b++;
			count--;
			break;
		}
	}
	if(b==0)
	{
		printf("There is no information about this contact.\n input 1 to operate again or input 0 to go back:");
		int c;
		scanf("%d",&c);
		if(c==1)
		{
			Delete();
		}
		else
		{
			menu();
		}
	}
    else
	{
		for(j=i;j<count;j++)
		{
			data[j]=data[j+1];
		}
		printf("Deletion succeeded!\n");
		writeData();
	    menu();
	}
	
}


void Alter()
{
	
	int i,b=0;
	char a[20];
	printf("please enter the name of the contact which you want to alter:");
    scanf("%s",a);
	for(i=0;i<count;i++)
	{
		if(strcmp(data[i].name,a)==0)
		{
			b++;
			break;
		}
	}
	if(b==0)
	{
		printf("There is no information about this contact.\n input 1 to operate again or input 0 to go back:");

		int c;

		scanf("%d",&c);

		if(c==1)
		{
			Alter();
		}
		else
		{
			menu();
		}
	}
	else
	{
		printf("Please enter the contact's name, gender,phone numbere, city and postcode:\n");
		scanf("%s %s %s %s %s",data[i].name,data[i].gender,data[i].tel,data[i].city,data[i].eip);
        writeData();
		printf("the contact is changed!\n");
		menu();
	}
}
void Quit()

{

	printf("|+---------------------------+|\n");

	printf("    | Thanks for your use  |\n");

	printf("|+---------------------------+|\n");

}

int main()
{
	readData();
	menu();
return 0;
}