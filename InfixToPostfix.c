#include<stdio.h>
#include<stdlib.h>

#define MAX 30

char* stack;
int top=-1;

int state();
void push(char);
char pop();
void infixPostfix(char*);
int precedence(char);

void main()
{
    char expression[30];
    stack=(int*) malloc(MAX*sizeof(int));
    
    printf("Enter Infix expression: ");
    scanf("%s",expression);
    infixPostfix(expression);
}

int state()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(char operator)
{
    top++;
    stack[top]=operator;
}

char pop()
{
    char operator=stack[top];
    top--;
    return operator;
}

int precendence(char operator)
{
    switch(operator)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
}

void infixPostfix(char* ptr)
{
    int i=0;

    while(ptr[i]!='\0')
    {
        if(ptr[i]>='a'||ptr[i]<='z')
        {
            printf("%c",ptr[i]);
        }
        else
        {
            int check;
            
        }
    }
}
