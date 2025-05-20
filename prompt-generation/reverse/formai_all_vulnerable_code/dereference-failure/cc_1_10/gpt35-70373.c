//FormAI DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
}Node;

Node* newNode(int val)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(Node** root, int val)
{
    if (*root == NULL)
        *root = newNode(val);
 
    else if ((*root)->val > val)
        insert(&((*root)->left), val);
 
    else if ((*root)->val < val)
        insert(&((*root)->right), val);
}

void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int main()
{
    Node* root = NULL;
    printf("Welcome to the Binary Search Tree program!\n");
    printf("Inserting nodes...\n");
    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 7);
    insert(&root, 1);
    insert(&root, 3);
    insert(&root, 6);
    insert(&root, 8);
    printf("Inorder traversal of the Binary Search Tree: ");
    inorder(root);
    printf("\n");
    printf("Thanks for using the Binary Search Tree program!\n");
    return 0;
}