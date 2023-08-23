#include<stdio.h>
#include<stdlib.h>

#define N 5

int fr=-1;
int re=-1;
int * ptr;

// function prototypes
void isFull();
void enQueue();
void deQueue();
void front();
void rear();
void display();

void main()
{
    ptr=(int*) calloc(N,sizeof(int));

    int choice;
    int loopexit;
    
    LABEL:
    while(1)
    {
        printf("\n\n---Array Implementation Of Queue---");
        printf("\n1. Check whether Queue is full\n2. Insert element into the Queue\n3. Delete element from the Queue\n4. Peek into rear of the Queue\n5. Peek into the front of the Queue\n6. Display elements of the Queue\n7. EXIT");
        printf("\n\nSelect option: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
            isFull();
            break;

            case 2:
            enQueue();
            break;

            case 3:
            deQueue();
            break;

            case 4:
            rear();
            break;

            case 5:
            front();
            break;

            case 6:
            display();
            break;

            case 7:
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
    if(fr==-1||fr==re)
        printf("\nThe Queue is empty.");

    else if(fr>re)
        printf("/nThe Queue is empty(All elements deleted but cannot add more elements.)");
    else if(re==N-1)
        printf("\nThe Queue is full.");
    
    else
    printf("\nThe Queue is not full.");
}

void enQueue()
{
    static int x;
    if(re==N-1)
    {
        printf("\nQueue is full!");
    }
    else if(fr==-1)
    {
            fr++;
            re++;
            printf("\nEnter the element to be inserted: ");
            scanf("%d",&x);
            ptr[re]=x;
    }
    else
    {
        re++;
        printf("\nEnter the element to be inserted: ");
        scanf("%d",&x);
        ptr[re]=x;
    }
}

void deQueue()
{
    if(fr==-1||fr>re)
    {
        printf("\nQueue is empty!");
    }
    else 
    printf("\nThe deleted element is: %d", ptr[fr]);
    fr++;
}

void front()
{
    if(fr==-1)
    printf("\nQueue is empty!");
    else
    printf("\nThe element at the front is: %d", ptr[fr]);
}

void rear()
{
    if(re==-1)
    printf("\nQueue is empty!");
    else
    printf("\nThe element at the rear is: %d", ptr[re]);
}

void display()
{
    if(fr==-1)
    {
        printf("\nQueue is empty!");
    }
    else
    printf("\nThe elements of Queue are: ");
    for(int i=fr;i<=re;i++)
    {
        printf("%d", ptr[i]);
    }
}







