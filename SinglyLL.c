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
void insertAt();
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
        printf("\n\nSelect choice: ");
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
            insertAt();
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

void insertAt()
{
    int test,count=0;

    printf("\nEnter element after which you want to insert new data: ");
    scanf("%d",&test);

    struct node* ptr=head;
    while(ptr->data!=test)
    {
        ptr=ptr->next;
        if(ptr->data==test)
        count++;
    }
    if(count==0)
    printf("\nNo such element in the LL");

    int x;
    printf("\nEnter data to be inserted: ");
    scanf("%d",&x);
    struct node* newnode;
    newnode=createNode();
    newnode->data=x;
    newnode->next=ptr->next;
    ptr->next=newnode;
}

void insertEnd()
{
    int x;
    printf("\nEnter data to be inserted: ");
    scanf("%d",&x);
    struct node* newnode;
    newnode=createNode();
    newnode->data=x;
    newnode->next=NULL;

    struct node* ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;    
    }
    ptr->next=newnode;
}

void deleteBeg()
{
    struct node* ptr=head;
    printf("\nElement deleted: %d",ptr->data);
    head=ptr->next;
}

void deleteAt()
{
    int x;
    printf("\nEnter element to be deleted: ");
    scanf("%d",&x);

    struct node* ptr;
    struct node* Temp;

    while(ptr->data==x)
    {
        Temp=ptr;
        ptr=ptr->next;
    }
    Temp->next=ptr->next;
}

void deleteEnd()
{
    struct node* ptr;
    struct node* temp;
    while(ptr->next!=NULL)
    {
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=NULL;
}

void display()
{
    if(head==NULL)
    printf("\nThe LL is empty");

    struct node* ptr=head;
    printf("\nThe elements of LL are: ");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

void count()
{
    if(head==NULL)
    printf("\nThe LL is empty");

    else
    {
    struct node* ptr=head;
    int count=0;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        count++;
    }
    printf("\nNumber of elements in LL: %d",count);
    }
}