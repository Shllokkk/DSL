#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head=NULL;

struct node* createNode();
void state();
void insertBeg();
//void insertAt();
void insertEnd();
void deleteBeg();
void deleteAt();
void deleteEnd();
void display();
void count();

void main()
{
    int choice,loopexit;

    LABEL:
    while(1)
    {
        printf("1. Check the state of LL");
        printf("\n2. Insert at beginning of LL");
        printf("\n3. Insert after specific node of LL");
        printf("\n4. Insert at end of LL");
        printf("\n5. Delete from beginning of LL");
        printf("\n6. Delete a specific node of LL");
        printf("\n7. Delete from end of LL");
        printf("\n8. Display all elements of LL");
        printf("\n9. Count elemens in LL");
        scanf("%d",&choice);

        switch(choice)
        {
            case(1):
            state();
            break;

            case(2):
            insertBeg();
            break;

            case(3):
            //insertAt();
            break;

            case(4):
            insertEnd();
            break;

            case(5):
            deleteBeg();
            break;

            case(6):
            deleteAt();
            break;

            case(7):
            deleteEnd();
            break;

            case(8):
            display();
            break;

            case(9):
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
    if(head==NULL)
    printf("\nThe LL is empty.");

    else
    printf("\nThe LL is not empty.");
}

void insertBeg()
{
    int x;
    printf("\nEnter data to be inserted: ");
    scanf("%d",&x);
    struct node* newnode;
    newnode=createNode();
    newnode->data=x;
    newnode->next=head;
    head=newnode;
    printf("\nNode insertion successful!");
}

void insertEnd()
{
    
}