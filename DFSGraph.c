#include <stdio.h>
#define MAX 10

int stack[MAX];

int top = -1;

int visited[6] = {0, 0, 0, 0, 0, 0};

void push(int x);
int pop();
int isStackEmpty();

void main()
{
    int N = 6;

    int graph[6][6] = {{0,1,1,0,0,0},
                       {1,0,1,0,0,0},
                       {1,1,0,1,1,0},
                       {0,0,1,0,0,0},
                       {0,0,1,0,0,1},
                       {0,0,0,0,1,0}};
    
    push(1);
    visited[0] = 1;

    while (!isStackEmpty())
    {
        int current = pop();
        printf("%d ", current);

        for (int i = 0; i < 6; i++)
        {
            if (graph[current - 1][i] == 1 && !visited[i])
            {
                push(i + 1);
                visited[i] = 1;
            }
        }
    }
}

void push(int x)
{
    if (top < MAX - 1)
        stack[++top] = x;
}

int pop()
{
    if (top >= 0)
        return stack[top--];

    return -1; 
}

int isStackEmpty()
{
    return top == -1;
}