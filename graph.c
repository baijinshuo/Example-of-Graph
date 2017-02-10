/* Note:Your choice is C IDE */
#include "stdio.h"
#include "stdlib.h"
#define N 30
typedef char datatype;
typedef struct node{
	int p;
	struct node *next;
}enode;
typedef struct vnode{
	datatype infor;
	enode *firstedge;
}vnode;
typedef struct{
	vnode array[N];
	int v,e;
}graph;

void creatgraph(graph *g)
{	int i,j,m,n;
	enode *s;
	printf("please input the number of edge and node:\n");
	scanf("%d%d",&g->e,&g->v);getchar();
	printf("please input %d ver",g->v);
	for(i=0;i<g->v;i++)
	{scanf("%c",&g->array[i].infor);
	getchar();
	g->array[i].firstedge=NULL;}
	printf("please input %d edges:",g->e);
	for(j=0;j<g->e;j++)
	{scanf("%d%d",&m,&n);getchar();
	s=(enode *)malloc(sizeof(enode));
		s->p=m;
	s->next=g->array[n].firstedge;
	g->array[n].firstedge=s;
	s=(enode *)malloc(sizeof(enode));
		s->p=n;
		s->next=g->array[m].firstedge;
		g->array[m].firstedge=s;
		}
}
void printgraph(graph g)
{	enode *q;
	int k;
	for(k=0;k<g.v;k++)
	{printf("%c ",g.array[k].infor);
	q=g.array[k].firstedge;
	while(q)
	{printf("%d**",q->p);
	q=q->next;}
	printf("/n");}
}
int visit[N];
void dfs(graph g,int i)
{	enode *q;
	printf("viset v:%c\n",g.array[i].infor);
	visit[i]=1;
	q=g.array[i].firstedge;
	while(q)
	{	if(!visit[q->p])
		dfs(g,q->p);
		q=q->next;}
}
void traverse(graph g)
{int i=0;
	for(i;i<g.v;i++)
	visit[i]=0;
	for(i;i<g.v;i++)
	{if(!visit[i])
		dfs(g,i);}
}	
	
int main()
{	
	graph g;
	creatgraph(&g);
	printf("graph:\n");
	printgraph(g);
	traverse(g);
    getchar();
    putchar(getchar());    
}

