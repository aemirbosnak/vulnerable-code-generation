//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 1000

typedef struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
} Node;

void visualize_tree(Node* node)
{
    if (node)
    {
        printf("%c ", node->data);

        visualize_tree(node->left);
        visualize_tree(node->right);
    }
}

int main()
{
    Node* root = NULL;
    root = malloc(sizeof(Node));
    root->data = 'A';

    Node* node1 = malloc(sizeof(Node));
    node1->data = 'B';
    root->left = node1;

    Node* node2 = malloc(sizeof(Node));
    node2->data = 'C';
    root->right = node2;

    Node* node3 = malloc(sizeof(Node));
    node3->data = 'D';
    node1->left = node3;

    Node* node4 = malloc(sizeof(Node));
    node4->data = 'E';
    node2->right = node4;

    visualize_tree(root);

    return 0;
}