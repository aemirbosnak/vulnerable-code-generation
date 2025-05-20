//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a binary tree node
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

// Insert a node into a binary search tree
void insert(node* node, int data)
{
    if (node == NULL)
    {
        node = malloc(sizeof(node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    else if (data < node->data)
    {
        insert(node->left, data);
    }
    else
    {
        insert(node->right, data);
    }
}

// Search for a node in a binary search tree
node* search(node* node, int data)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (node->data == data)
    {
        return node;
    }
    else if (data < node->data)
    {
        return search(node->left, data);
    }
    else
    {
        return search(node->right, data);
    }
}

int main()
{
    node* root = NULL;
    insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);

    node* searchNode = search(root, 25);

    if (searchNode)
    {
        printf("Node found: %d\n", searchNode->data);
    }
    else
    {
        printf("Node not found\n");
    }

    return 0;
}