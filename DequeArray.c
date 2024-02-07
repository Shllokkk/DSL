#include<stdio.h>
#include<stdlib.h>

#define N 5

int fr=-1,re=-1;
int* ptr;

// function prototypes
void isFull();
void enQueueRear();
void enQueueFront();
void deQueueRear();
void deQueueFront();
void rear();
void front();
void display();

void main()
{
    ptr= (int*) malloc(N*sizeof(int));
    int choice;
    int loopexit;
    
    LABEL:
    while(1)
    {
        printf("\n\n---Array Implementation Of Queue---");
        printf("\n1. Check whether Queue is full\n2. Insert element in the rear of the Queue\n3. Insert element in the front of the Queue\n4. Delete element from the rear of the Queue\n5. Delete element from the front of the queue\n6. Peek into rear of the Queue\n7. Peek into the front of the Queue\n8. Display elements of the Queue\n9. EXIT");
        printf("\n\nSelect option: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
            isFull();
            break;

            case 2:
            enQueueRear();
            break;

            case 3:
            enQueueFront();
            break;

            case 4:
            deQueueRear();
            break;

            case 5:
            deQueueFront();
            break;

            case 6:
            rear();
            break;

            case 7:
            front();
            break;

            case 8:
            display();
            break;

            case 9:
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
    if(fr==-1)
        printf("\nThe Queue is empty.");

    else if(fr==(re+1)%N)
        printf("\nThe Queue is full.");

    else 
        printf("\nThe Queue is not full.");
}

void enQueueRear()
{
    if(fr==(re+1)%N)
    {
        printf("\nThe Queue is full.");
    }
    else
    {
        if(fr==-1)
        {
            fr++;
        }
        re=(re+1)%N;
        printf("\nEnter the element to be inserted: ");
        scanf("%d",&ptr[re]);
    }
}

void enQueueFront()
{
    if(fr==(re+1)%N)
    {
        printf("\nThe Queue is full.");
    }
    else
    {
        if(fr==0)
            fr=(N-1);
        else
        {
            fr--;       
        }
        printf("\nEnter element to be inserted: ");
        scanf("%d", &ptr[fr]);
    }
}

void deQueueRear()
{
    if(re==fr)
    {
        printf("\nThe queue is empty.");
        fr=re=-1;
    }
    else
    {
        if(re==0)
        {
            printf("\nThe deleted element is: %d",ptr[re]);
            re=(N-1);
        }
        else
        {
            printf("\nThe deleted element is: %d",ptr[re]);
            re--;
        }
        
    }
}

void deQueueFront()
{
    if(fr==-1)
    {
        printf("\nThe Queue is empty.");
    }
    else if(fr==re)
    {
        printf("\nThe Queue is empty.");
        fr=re=-1;
    }
    else
    {
        printf("\nThe deleted element is: %d",ptr[fr]);
        fr=(fr+1)%N;
    }
}

void rear()
{
    if(re==-1)
        printf("\nQueue is empty!");
    else
        printf("\nThe element at the rear is: %d", ptr[re]);
}

void front()
{
    if(fr==-1)
        printf("\nQueue is empty!");
    else
        printf("\nThe element at the front is: %d", ptr[fr]);
}

void display()
{
    if(fr==-1)
    {
        printf("\nQueue is empty!");
    }
    else
    {
        printf("\nThe elements of Queue are: ");
        if(fr<=re)
        {
        for(int i=fr;i<=re;i++)
        {
            printf("%d ",ptr[i]);
        }
        }
        else
        {
            int fr1;
            fr1=fr;
            for(int i=fr1;i<N;i++)
            {
                printf("%d ",ptr[i]);
            }
            fr1=0;
            for(int i=fr1;i<=re;i++)
            {
                printf("%d ",ptr[i]);
            }
        
        }
    }
}


