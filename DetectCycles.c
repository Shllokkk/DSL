#include<stdio.h>
#define MAXVERTICES 100

// int graph[MAXVERTICES][MAXVERTICES];
int graph[4][4] = { {0,1,0,1},
                    {1,0,1,0},
                    {0,1,0,1},
                    {1,0,1,0}};
int visited[MAXVERTICES];
int numnodes=4;

int dfs(int initialVertex, int parent)
{
    visited[initialVertex]=1;

    for(int i=0;i<numnodes;i++)
    {
        if(graph[initialVertex][i])
        {
            if(!visited[i])
            {
                if(dfs(i,initialVertex))
                    return 1;
            }
            else if(i!=parent)
                return 1;   
        }
    }
    return 0;
}

int detectCycle()
{
    for(int i=0;i<numnodes;i++)
    {
        if(!visited[i])
            if(dfs(i,-1))
                return 1;
    }
    return 0;
}

void main()
{
    int startVertex;

    // printf("\nEnter number of nodes for an undirected graph: ");
    // scanf("%d",&numnodes);

    //printf("\nEnter adjacency matrix ");

    // for(int i=0;i<numnodes;i++)
    // {
    //         for(int j=0;j<numnodes;j++)
    //         {
    //             printf("Graph[%d][%d]: ",i,j);
    //             scanf("%d",&graph[i][j]);
    //         }
    // }

    if(detectCycle())
        printf("\nCycle detected in graph");
    else    
        printf("\nNo cycle detected in graph");
}