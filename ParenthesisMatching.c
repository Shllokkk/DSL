#include<stdio.h>
#include<stdlib.h>
#define MAX 30

char* ptr;
int top=-1;

void push(char a);
int pop();

void main()
{
    ptr=(char *) malloc(MAX*sizeof(char));
    char eqn[30];
    int i=0;
    int flag=1;

    printf("\nEnter Equation to be checked: ");
    gets(eqn);

    while(eqn[i]!='\0')
    {
        if(eqn[i]=='(')
        {
            push(eqn[i]);
        }
        else if(eqn[i]==')')
        {
            int check=pop();
            if(check)
            {
                flag=0;
                break;
            }
        }
        i++;
    }
    if(top>=0)
        flag=0;
    if(flag)
        printf("\nThe equation is balanced!");
    else
        printf("\nThe equation is unbalanced!");
    free(ptr);
}

void push(char a)
{
    top++;
    ptr[top]=a;
}

int pop()
{
    if(top==-1)
        return 1;
    else
    {
        top--;
        return 0;
    }
}
