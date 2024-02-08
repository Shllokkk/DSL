#include<stdio.h>
#define MAXVERTICES 100

int graph[MAXVERTICES][MAXVERTICES];
int visited[MAXVERTICES];
int numnodes;

void dfs(int startVertex)
{
    visited[startVertex]=1;
    printf("\n%d",startVertex);

    for(int i=0;i<numnodes;i++)
    {
        if(graph[startVertex][i] && !visited[i])
            dfs(i);
    }
}

void main()
{
    int startVertex;

    printf("\nEnter number of nodes for an undirected graph: ");
    scanf("%d",&numnodes);

    printf("\nEnter adjacency matrix ");

    for(int i=0;i<numnodes;i++)
    {
            for(int j=0;j<numnodes;j++)
            {
                printf("Graph[%d][%d]: ",i,j);
                scanf("%d",&graph[i][j]);
            }
    }
    printf("\nEnter the start vertex: ");
    scanf("%d",&startVertex);
    dfs(startVertex);
}