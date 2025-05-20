//FormAI DATASET v1.0 Category: Binary search trees ; Style: random
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node* insert(Node *root, int key)
{
    if(root == NULL)
    {
        root = (Node*)malloc(sizeof(Node));
        root->data = key;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if(key < root->data)
        root->left = insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);

    return root;
}

void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    printf("Welcome to Binary Search Trees\n");

    Node *root = NULL;

    int i, n;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);

    printf("\nEnter %d elements\n", n);
    for(i=0; i<n; i++)
    {
        int key;
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("\nThe inorder traversal of the binary search tree is: ");
    inorder(root);
    printf("\n");

    return 0;
}