//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_ Nodes 1000

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* Insert(struct Node* node, int data)
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
        node->left = Insert(node->left, data);
    }
    else
    {
        node->right = Insert(node->right, data);
    }

    return node;
}

void Inorder(struct Node* node)
{
    if (node)
    {
        Inorder(node->left);
        printf("%d ", node->data);
        Inorder(node->right);
    }
}

int main()
{
    struct Node* root = NULL;
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 30);
    root = Insert(root, 40);
    root = Insert(root, 50);

    Inorder(root);

    return 0;
}