#include<stdio.h>
#include<stdlib.h>

#define MAX 30

char* stack;
int top=-1;

int state();
void push(char);
char pop();
char peek();
int precedence(char);
void infixPostfix(char*);

void main()
{
    char expression[30];
    stack=(char*) malloc(MAX*sizeof(char));
    
    printf("Enter Infix expression: ");
    scanf("%s",expression);
    infixPostfix(expression);
}

int state()
{
    if(top==-1)
        return 0;
    else
        return 1;
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

char peek()
{
    return stack[top];
}

int precedence(char operator)
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
        if(ptr[i]>='a'&&ptr[i]<='z')
        {
            printf("%c",ptr[i]);
        }
        else if(ptr[i]=='(')
            push(ptr[i]);

        else if(ptr[i]==')')
        {
            while(peek()!='(')
                printf("%c",pop());
            pop();
        }

        else
        {
            if(state()||precedence(peek())<precedence(ptr[i]))
                push(ptr[i]);
            else if(precedence(peek())>=precedence(ptr[i]))
            {
                while(state()&&precedence(peek())>=precedence(ptr[i]))
                    printf("%c",pop());
                push(ptr[i]);
            }
        }
        i++;
    }
    while(state())
     printf("%c",pop());
}
