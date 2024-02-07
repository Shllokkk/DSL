#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

struct node *createNode();
struct node *findMinimum(struct node *);
void insert(int);
void delete(int);
int search(int);
void inOrder(struct node *);
void preOrder(struct node *);
void postOrder(struct node *);

void main() {
  int choice,loopexit=1,data;

    while(loopexit)
    {
        printf("\n1. Insert a node in BST");
        printf("\n2. Delete a node from BST");
        printf("\n3. Search a node in BST");
        printf("\n4. Inorder traversal");
        printf("\n5. Preorder traversal");
        printf("\n6. Postorder traversal");
        printf("\n7. Exit");
        printf("\n\nSelect choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter data to be inserted in BST: ");
                scanf("%d",&data);
                insert(data);
                break;

            case 2:
                printf("\nEnter data to be deleted from BST: ");
                scanf("%d",&data);
                delete(data);
                break;

            case 3:
                printf("\nEnter data to be searched in BST: ");
                scanf("%d",&data);
                if(search(data))
                    printf("\nElement present in the tree!");
                else
                    printf("\nElement not present in the tree!");
                break;

            case 4:
                printf("\nInorder traversal: ");
                inOrder(root);
                break;

            case 5:
                printf("\nPreorder traversal: ");
                preOrder(root);
                break;

            case 6:
                printf("\nPostorder traversal: ");
                postOrder(root);
                break;
            
            case 7:
                loopexit=0;
                break;

            default:
            printf("\nInvalid Choicd!");
                break;
        }
    }
}

struct node *createNode()
{
    return (struct node*) malloc(sizeof(struct node));  
}

struct node *findMinimum(struct node *root)
{
    if(root==NULL)
        return NULL;
    else
    {
        while(root->left!=NULL)
            root=root->left;
        return root;
    }
}

void insert(int x)
{
    if(search(x))
        printf("\nElement already present in the tree!");

    else
    {
        struct node *newNode;
        newNode=createNode();
        newNode->data=x;
        newNode->left=NULL;
        newNode->right=NULL;

        if(root==NULL)
            root=newNode;

        else
        {
            struct node *temp=root;
            struct node *prevNode;
            while(temp!=NULL)
            {
                prevNode=temp;
                if(x<temp->data)
                    temp=temp->left;
                else if(x>temp->data)
                    temp=temp->right;
            }
            if(x<prevNode->data)
                prevNode->left=newNode;
            else    
                prevNode->right=newNode;
        }
        printf("\nElement inserted!");
    }
}

void delete(int x)
{   
    struct node *temp=root;

    while(temp!=NULL)
    {
        if(x<temp->data)
            temp=temp->left;
        else if(x>temp->data)
            temp=temp->right;
        else
            break;
    }

    if(temp==NULL)
        printf("\nElement not present in the tree!");
    else if(temp->left==NULL && temp->right==NULL)
    {
        free(temp);
        printf("\nElement deleted!");
    }
    else if(temp->left==NULL || temp->right==NULL)
    {
        if(temp->left==NULL)
            temp=temp->right;
        else
            temp=temp->left;
        printf("\nElement deleted!");
    }
    else
    {
        struct node *inOrderSucc=findMinimum(temp->right);
        temp->data=inOrderSucc->data;
        delete(inOrderSucc->data);
        printf("\nElement deleted!");
    }
}

int search(int x)
{
    if(root==NULL)
        return 0;

    struct node *temp=root;

    while(temp!=NULL)
    {
        if(x<temp->data)
            temp=temp->left;
        else if(x>temp->data)
            temp=temp->right;
        else 
            break;
    }
    if(temp==NULL)
        return 0;
    else
        return 1;
}

void inOrder(struct node *root)
{
    struct node *temp=root;
    if(temp!=NULL)
    {
        inOrder(temp->left);
        printf("%d ",temp->data);
        inOrder(temp->right);
    }
}

void preOrder(struct node *root)
{
    struct node *temp=root;
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

void postOrder(struct node* root)
{
    struct node *temp=root;
    if(temp!=NULL)
    {
        postOrder(temp->left);
        postOrder(temp->right);
        printf("%d ",temp->data);
    }
}