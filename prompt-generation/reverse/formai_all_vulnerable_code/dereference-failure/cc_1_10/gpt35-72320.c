//FormAI DATASET v1.0 Category: Binary search trees ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *getNewNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if(root == NULL)
    {
        root = getNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *search(Node *root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->data == data)
    {
        return root;
    }
    else if(data <= root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 30);

    int key = 25;
    if(search(root, key) != NULL)
    {
        printf("%d Found\n", key);
    }
    else
    {
        printf("%d Not Found\n", key);
    }

    key = 15;
    if(search(root, key) != NULL)
    {
        printf("%d Found\n", key);
    }
    else
    {
        printf("%d Not Found\n", key);
    }

    return 0;
}