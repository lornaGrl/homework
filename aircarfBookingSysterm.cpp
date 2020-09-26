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
	int ID;			 //航班ID
	char time[20];   //起降时间
	char data[10];   //日期
	char start[10];  //起点
	char end[10];	//终点
	int ticketCount; //票数
	int price;		 //票价
} data[100];
struct people
{
	int bill;	  //乘客订单
	char name[10]; //姓名
	char card[18]; //身份证号
	int ticket;	//票数
	int airID;	 //航班号
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
int readData() //读取文件
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
int writeData() //写入文件
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
