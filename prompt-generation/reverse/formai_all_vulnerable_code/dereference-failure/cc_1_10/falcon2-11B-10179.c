//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// define a node struct
typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} node;

// define a binary search tree
node* create_node(int key)
{
    node* new_node = (node*)malloc(sizeof(node));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// define a function to insert a new node into the tree
void insert(node* root, int key)
{
    if (!root)
    {
        root = create_node(key);
        return;
    }
    if (key < root->key)
        insert(root->left, key);
    else if (key > root->key)
        insert(root->right, key);
}

// define a function to search for a key in the tree
int search(node* root, int key)
{
    if (!root)
        return 0;
    if (key < root->key)
        return search(root->left, key);
    if (key > root->key)
        return search(root->right, key);
    return 1;
}

// define a function to print the tree in pre-order traversal
void preorder(node* root)
{
    if (!root)
        return;
    preorder(root->left);
    printf("%d ", root->key);
    preorder(root->right);
}

int main()
{
    node* root = NULL;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 90);

    preorder(root);

    return 0;
}