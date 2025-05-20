//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_ Nodes 100

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int insert_node(Node* node, int data)
{
    if (node == NULL)
    {
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return 0;
    }

    if (data < node->data)
    {
        insert_node(node->left, data);
    }
    else
    {
        insert_node(node->right, data);
    }

    return 1;
}

int search_node(Node* node, int data)
{
    if (node == NULL)
    {
        return 0;
    }

    if (node->data == data)
    {
        return 1;
    }

    if (data < node->data)
    {
        return search_node(node->left, data);
    }
    else
    {
        return search_node(node->right, data);
    }
}

int main()
{
    Node* root = NULL;
    insert_node(root, 10);
    insert_node(root, 5);
    insert_node(root, 15);
    insert_node(root, 2);
    insert_node(root, 7);

    if (search_node(root, 5) == 1)
    {
        printf("Node found!\n");
    }

    return 0;
}