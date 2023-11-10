#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *right_child;
  struct node *left_child;
};

struct node* newNode(int);
struct node* find_minimum(struct node *);
struct node* insert(struct node *, int);
struct node* delete(struct node *, int);
struct node* search(struct node *, int);
void inOrder(struct node *root);
void preOrder(struct node *root);
void postOrder(struct node *root);

void main() {
  int choice,loopexit,data;

  struct node* root=newNode(50);
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
                insert(root,data);
                break;

            case 2:
                printf("\nEnter data to be deleted from BST: ");
                scanf("%d",&data);
                delete(root,data);
                break;

            case 3:
                printf("\nEnter data to be searched in BST: ");
                scanf("%d",&data);
                search(root,data);
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
                loopexit=0;
                break;
        }
    }
}

struct node* newNode(int x) {
  struct node *temp;
  temp = (struct node* )malloc(sizeof(struct node));
  temp->data = x;
  temp->left_child = NULL;
  temp->right_child = NULL;
  return temp;
}

struct node* find_minimum(struct node * root) {
  if (root == NULL)
    return NULL;
  else if (root->left_child != NULL)
    return find_minimum(root->left_child);
  return root;
}

struct node* insert(struct node * root, int x) {
  if (root == NULL)
    return newNode(x);
  else if (x > root->data)
    root->right_child = insert(root->right_child, x);
  else
    root->left_child = insert(root->left_child, x);
  return root;
}

struct node* delete(struct node * root, int x) {
  if (root == NULL)
    return NULL;
  if (x > root->data)
    root->right_child = delete(root->right_child, x);
  else if (x < root->data)
    root->left_child = delete(root->left_child, x);
  else {
    if (root->left_child == NULL && root->right_child == NULL) {
      free(root);
      return NULL;
    } else if (root->left_child == NULL || root->right_child == NULL) {
      struct node *temp;
      if (root->left_child == NULL)
        temp = root->right_child;
      else
        temp = root->left_child;
      free(root);
      return temp;
    } else {
      struct node *temp = find_minimum(root->right_child);
      root->data = temp->data;
      root->right_child = delete(root->right_child, temp->data);
    }
  }
  return root;
}

struct node* search(struct node * root, int x) {
  if (root == NULL || root->data == x)
    return root;
  else if (x > root->data)
    return search(root->right_child, x);
  else
    return search(root->left_child, x);
}

void inOrder(struct node *root) {
  if (root != NULL) {
    inOrder(root->left_child);
    printf(" %d ", root->data);
    inOrder(root->right_child);
  }
}

void preOrder(struct node *root) {
  if (root != NULL) {
    printf(" %d ", root->data);
    preOrder(root->left_child);
    preOrder(root->right_child);
  }
}

void postOrder(struct node *root) {
  if (root != NULL) {
    postOrder(root->left_child);
    postOrder(root->right_child);
    printf(" %d ", root->data);
  }
}