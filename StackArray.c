#include <stdio.h>
#include <stdlib.h>

#define N 5

int top=-1;                           // pointer to top of the stack
int* ptr;
int x;


// function prototypes
void isFull();
void push();
void pop();
void peek();
void display();

void main()
{
    int choice;
    int loopexit;
    ptr= (int*) calloc(N,sizeof(int));
    
    LABEL:
    while(1)
    {
        printf("\n\n---Array Implementation Of Stack---");
        printf("\n1. Check whether Stack is full\n2. Push element into the Stack\n3. Pop element from the Stack\n4. Peek into the Stack\n5. Display elements of the Stack\n6. EXIT");
        printf("\n\nSelect option: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
            isFull();
            break;

            case 2:
            push();
            break;

            case 3:
            pop();
            break;

            case 4:
            peek();
            break;

            case 5:
            display();
            break;

            case 6:
            break;
        }

        printf("\nDo you want to exit(1/0): ");
        scanf("%d", &loopexit);

        if(loopexit==0)
        {
            goto LABEL;
        }
        break;
    }
    
}

void isFull()
{
    if (top==N-1)
    {
        printf("\nThe Stack is full.");
    }
    else
    printf("\nThe Stack is not full.");
}

void push()
{
    if(top==N-1)
    {
        printf("\nStackOverflow! Cannot add more elements");
    }
    else
    {   
        top++;
        printf("\nEnter element to be added: ");
        scanf("%d", &x);
        ptr[top]=x;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nStackUnderflow! Stack is empty");
    }
    else
    {
        printf("\nThe popped element is: %d", ptr[top]);
        top--;
    }
}

void peek()
{
    if(top==-1)
    {
         printf("\nStackUnderflow! Stack is empty.");
    }
    else
    {
        printf("\nThe topmost element is: %d", ptr[top]);
    }
}

void display()
{
    if(top==-1)
    {
        printf("\nStackUnderflow. Add elements first.");
    }
    else
    {
        printf("\nThe elements of the Stack are:  ");
        for(int i=0;i<=top;i++)
        {
            printf("\n%d",ptr[i]);
        }
    }
}