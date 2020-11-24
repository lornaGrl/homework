#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 20
int visited[MAXNUM];
typedef char VertexData;
typedef struct 
{
	char vertex[MAXNUM];
	int arcs[MAXNUM][MAXNUM];
	int vexnum,arcnum;
}AdjMatrix;

int LocateVertex(AdjMatrix *G,VertexData v ) 
{
	int j=0,k;
	for(k=0;k<G->vexnum;k++)
	{
		if(G->vertex[k]==v)
		{
			j=k;
			break;
		}
	}
	return j;
}

void Create(AdjMatrix *G)
{
	int i,j,k;
	VertexData v1,v2;
	printf("请输入图的弧数和顶点数：");
	scanf("%d %d",&G->arcnum,&G->vexnum);getchar();
	for(i=0;i<G->vexnum;i++)
		for(j=0;j<G->vexnum;j++)
		{
			G->arcs[i][j]=0;
		}
		printf("请输入各个顶点：");
		for(i=0;i<G->vexnum;i++)
		{
			
			
			G->vertex[i]=getchar();
			
		}
		for(k=0;k<G->arcnum;k++)
		{
			rewind(stdin);
			printf("请输入一条弧的两个端点：");
			scanf("%c,%c",&v1,&v2);
			i=LocateVertex(G,v1);
			j=LocateVertex(G,v2);
			G->arcs[i][j]=1;
		}
}



void DepthFirstSearch(AdjMatrix G,int v0)
{
	int vj;
	printf("%c",G.vertex[v0]);
	visited[v0]=1;
	for(vj=0;vj<G.vexnum;vj++)
		if(!visited[vj]&&G.arcs[v0][vj]==1)
			DepthFirstSearch(G,vj);
}
void TraverseGraph(AdjMatrix G)
{
	int vi;
	for(vi=0;vi<G.vexnum;vi++)
	{
		
		visited[vi]=0;
	}
	for(vi=0;vi<G.vexnum;vi++)
	{
		if(!visited[vi])
		{
			DepthFirstSearch(G,vi);
		}
	}
}

int main()
{
	AdjMatrix G;
	Create(&G);
	printf("输出序列：");
	TraverseGraph(G);
	return 0;
}
