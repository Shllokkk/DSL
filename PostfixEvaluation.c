#include<stdio.h>
#include<stdlib.h>
#define MAX 30

int* array;
int top=-1;
int result=0;

int state();
void push(int);
int pop();
void evaluate(char*);

void main()
{
    array=(int*) malloc(MAX*sizeof(int));                    // initializing array with malloc
    char expression[30];

    printf("\nEnter Postfix expression to be evaluated: ");
    scanf("%s",expression);

    evaluate(expression);
}

int state()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(int operand)
{
    top++;
    array[top]=operand;
}

int pop()
{
    int x;
    if(state())
        printf("\nStackUnderflow!");
    else
    {
        x=array[top];
        top--;
        return x;
    }
}

void evaluate(char* character)
{
    int i=0;
    int operand1;
    int operand2;

    while(character[i]!='\0')
    {
        if(character[i]>='0'&&character[i]<='9')
        {
            push(character[i]-'0');
        }
        else if(character[i]=='/'||character[i]=='*'||character[i]=='+'||character[i]=='-')
        {
            char symbol=character[i];
            operand2=pop();
            operand1=pop();                         
            
            switch(symbol)
            {
                case '/':
                    result=operand1/operand2;
                    break;
                case '*':
                    result=operand1*operand2;
                    break;
                case '+':
                    result=operand1+operand2;
                    break;
                case '-':
                    result=operand1-operand2;
                    break;
            }
            push(result);
        }
        i++;
    }
    printf("\nAnswer: %d",result);
}