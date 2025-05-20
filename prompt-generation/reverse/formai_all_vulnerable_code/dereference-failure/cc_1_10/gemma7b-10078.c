//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int main()
{
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    search(root, 30);
    search(root, 40);
    search(root, 60);

    return 0;
}

insert(Node* node, int data)
{
    if (node == NULL)
    {
        node = malloc(sizeof(Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    else if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }

    return node;
}

search(Node* node, int data)
{
    if (node != NULL)
    {
        if (node->data == data)
        {
            printf("Found data: %d\n", data);
        }
        else if (data < node->data)
        {
            search(node->left, data);
        }
        else
        {
            search(node->right, data);
        }
    }
    else
    {
        printf("Data not found: %d\n", data);
    }
}