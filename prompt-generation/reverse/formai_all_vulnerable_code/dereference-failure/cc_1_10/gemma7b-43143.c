//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_Nodes 1024

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void insertNode(Node* node, int data)
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
        insertNode(node->left, data);
    }
    else
    {
        insertNode(node->right, data);
    }
}

void traverseTree(Node* node)
{
    if (node)
    {
        traverseTree(node->left);
        printf("%d ", node->data);
        traverseTree(node->right);
    }
}

void compressTree(Node* node)
{
    Node* previous = NULL;
    Node* current = node;
    int count = 0;

    while (current)
    {
        if (previous && current->data == previous->data)
        {
            count++;
        }
        else
        {
            insertNode(previous, count);
            previous = current;
            count = 1;
        }

        current = current->left;
    }

    insertNode(previous, count);
    traverseTree(node);
}

int main()
{
    Node* root = NULL;
    insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 2);
    insertNode(root, 7);

    compressTree(root);

    traverseTree(root);

    return 0;
}