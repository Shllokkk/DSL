#include<stdio.h>
#include<stdlib.h>

int cntr=0;

struct node
{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;

// function prototypes
struct node* createNode();
void state();
void enQueue();
void deQueue();
void peekfront();
void peekrear();
void display();
void count();

void main()
{
    int choice;
    int loopexit;
    
    LABEL:
    while(1)
    {
        printf("\n\n---Array Implementation Of Queue---");
        printf("\n1. Check state of Queue\n2. Insert element into the Queue\n3. Delete element from the Queue\n4. Peek into rear of the Queue\n5. Peek into the front of the Queue\n6. Display elements of the Queue\n7. Count number of elements in queue.");
        printf("\n\nSelect option: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                state();
                break;

            case 2:
                enQueue();
                break;

            case 3:
                deQueue();
                break;

            case 4:
                peekrear();
                break;

            case 5:
                peekfront();
                break;

            case 6:
                display();
                break;

            case 7:
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
    if(front==NULL)
        printf("\nThe Queue is empty.");
    else
        printf("\nThe Queue is not empty.");
}

void enQueue()
{
    struct node* ptr;
    ptr=createNode();

    if(ptr==NULL)
        printf("\nQueueOverFlow!");

    printf("\nEnter data to be inserted: ");
    scanf("%d",&ptr->data);

    if(front==NULL)
    {
        ptr->next=front;
        front=ptr;
        rear=ptr;
        cntr++;
    }
    else
    {
        ptr->next=NULL;
        rear->next=ptr;
        rear=ptr;
        cntr++;
    }
    
}

void deQueue()
{
    if(front==NULL)
        printf("\nQueueUnderflow!");
    else
    {
        struct node* ptr=front;
        printf("\nElement deleted: %d",ptr->data);
        front=ptr->next;
        cntr--;
    }  
}

void peekrear()
{
    if(rear==NULL)
        printf("\nQueue is empty");
    else
        printf("\nElement at rear: %d",rear->data);
}

void peekfront()
{
    if(front==NULL)
        printf("\nQueue is empty");
    else
        printf("\nElement at front: %d",front->data);
}
void display()
{
    if(front==NULL)
        printf("\nQueue is empty.");

    else
    {
        struct node* ptr=front;

        printf("\nElements of Queue are: ");
        while(ptr!=NULL)
        {
            printf("%d-->",ptr->data);
            ptr=ptr->next;
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