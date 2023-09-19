#include <stdio.h>
#include <stdlib.h> 

#define MAX 5

int cntr=0;

struct node
{
    int data;
    struct node* next;
};
struct node* top=NULL;

struct node* createNode();
void state();
void push();
void pop();
void display();
void count();

void main()
{
    int choice;
    int loopexit;
    
    LABEL:
    while(1)
    {
        printf("\n\n---Array Implementation Of Stack---");
        printf("\n1. Check the State of Stack\n2. Push element into the Stack\n3. Pop element from the Stack\n4. Display elements of the Stack\n5. Count number of Elements in Stack.");
        printf("\n\nSelect option: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                state();
                break;

            case 2:
                push();
                break;

            case 3:
                pop();
                break;

            case 4:
                display();
                break;

            case 5:
                count();
                break;
            default:
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

struct node* createNode()
{
    return (struct node*) malloc (sizeof(struct node));
}

void state()
{
    if(top==NULL)
        printf("\nStack is empty.");
    else
        printf("\nStack is not empty.");
}

void push()
{
    struct node* ptr;
    ptr=createNode();

    if(ptr==NULL)
        printf("\nStackOverflow!");

    else
    {
        printf("\nEnter data to be pushed into the stack: ");
        scanf("%d",&ptr->data);
        ptr->next=top;
        top=ptr;
        cntr++;
    }
}

void pop()
{
    if(top==NULL)
        printf("\nStackUnderflow!");
    else
    {
        struct node* ptr=top;
        printf("\nElement deleted: %d",ptr->data);
        top=ptr->next;
        cntr--;
    }  
}

void display()
{
    if(top==NULL)
        printf("\nStack is empty.");

    else
    {   
        struct node* ptr=top;

        printf("\nElements in the Stack are: ");
        while(ptr!=NULL)
        {
            printf("%d-->",ptr->data);
            ptr=ptr->next;
             free(ptr);
        }
        printf("NULL\n");
    }
}

void count()
{
    if(cntr)
        printf("\nNumber of elements i Stack: %d",cntr);
    else
        printf("\nStack is empty.");
}