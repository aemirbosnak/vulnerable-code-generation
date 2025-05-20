//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 1000

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* insert(struct Node* node, int data)
{
    if (node == NULL)
    {
        node = (struct Node*)malloc(sizeof(struct Node));
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

int search(struct Node* node, int data)
{
    if (node == NULL)
    {
        return 0;
    }
    else if (node->data == data)
    {
        return 1;
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
    struct Node* root = NULL;
    insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);

    if (search(root, 25) == 1)
    {
        printf("Node found.\n");
    }
    else
    {
        printf("Node not found.\n");
    }

    return 0;
}