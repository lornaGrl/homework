#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#define M 10000;
using namespace std;
FILE *fp;
int planeCount = 0;
int use = 0;
int inf = 0;
struct plane
{
	int ID;			 //����ID
	char time[20];   //��ʱ��
	char data[10];   //����
	char start[10];  //���
	char end[10];	//�յ�
	int ticketCount; //Ʊ��
	int price;		 //Ʊ��
} data[100];
struct people
{
	int bill;	  //�˿Ͷ���
	char name[10]; //����
	char card[18]; //���֤��
	int ticket;	//Ʊ��
	int airID;	 //�����
} user[100];
void login();
void search();
void book();
void back();
void bill();
void drop();
void main_menu();
int deal();
void admire();
void input();
void listOfPlanes();
void update();
void order();
void search_end();
void search_id();
int readData();
void passager();
int userData();
int userWrite();
void quicksort();
int main()
{
	readData();
	userData();
	main_menu();
return 0;}
int readData() //��ȡ�ļ�
{
	int i = 0;
	if ((fp = fopen("plane.txt", "r+")) == NULL)
	{
		return 0;
	}
	while (~fscanf(fp, "%d %s %s %s %s %d %d", &data[i].ID, data[i].time, data[i].data, data[i].start, data[i].end, &data[i].ticketCount, &data[i].price))
	{
		i++;
		planeCount++;
	}
	fclose(fp);
	return 0;
}
int writeData() //д���ļ�
{
	int i;
	if ((fp = fopen("plane.txt", "w")) == NULL)
	{
		return 0;
	}
	for (i = 0; i < planeCount; i++)
	{

		fprintf(fp, "%d %s %s %s %s %d %d\n", data[i].ID, data[i].time, data[i].data, data[i].start, data[i].end, data[i].ticketCount, data[i].price);

	}

	fclose(fp);

	return 0;

}



int account;



int deal()

{
