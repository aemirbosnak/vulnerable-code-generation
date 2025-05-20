//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 100

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* node, char data)
{
    if (node == NULL)
    {
        node = (Node*)malloc(sizeof(Node));
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

void traverse(Node* node)
{
    if (node)
    {
        printf("%c ", node->data);
        traverse(node->left);
        traverse(node->right);
    }
}

int main()
{
    Node* root = NULL;
    root = insert(root, 'a');
    insert(root, 'b');
    insert(root, 'c');
    insert(root, 'd');
    insert(root, 'e');

    traverse(root);

    return 0;
}