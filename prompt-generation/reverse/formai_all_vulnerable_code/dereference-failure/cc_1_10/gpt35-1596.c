//FormAI DATASET v1.0 Category: Data structures visualization ; Style: calm
/* This program visualizes a binary search tree data structure. */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data)
{
    if (root == NULL)
        return createNode(data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void printTree(Node* root, int space)
{
    if (root == NULL)
        return;

    int i;
    for (i = 0; i < space; i++)
        printf(" ");

    printf("%d\n", root->data);

    printTree(root->left, space + 4);
    printTree(root->right, space + 4);
}

int main()
{
    Node* root = NULL;
    int arr[] = {4, 2, 1, 5, 6, 3, 7};

    int i;
    for (i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    printf("Binary Search Tree Visualization:\n\n");
    printTree(root, 0);

    return 0;
}