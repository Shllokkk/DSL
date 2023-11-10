#include<stdio.h>
#define MAX 10

int queue[MAX];

int front=0;
int rear=0;

int visited[6] = {0,0,0,0,0,0};

void push(int);
void pop();

void main()
{
    int N  = 6;

    int graph[6][6] = {{0,1,1,0,0,0},
                       {1,0,1,0,0,0},
                       {1,1,0,1,1,0},
                       {0,0,1,0,0,0},
                       {0,0,1,0,0,1},
                       {0,0,0,0,1,0}};
    
    push(1);
    visited[0] = 1;  
    while(front != rear)
    {
        int current = queue[front];
        printf("%d ", current);
        
        pop();
 
        for(int i=0;i<6;i++)
        { 
            if((graph[current-1][i] == 1) && (visited[i] == 0))
            {
                visited[i] = 1; 
                push(i+1);
            }
        }
    }
}

void push(int x)
{
    queue[rear] = x;
    rear++;
}

void pop()
{
    queue[front] = 0;
    front++;
}