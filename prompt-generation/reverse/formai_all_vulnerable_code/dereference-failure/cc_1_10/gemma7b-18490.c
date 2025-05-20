//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a binary tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Prototype for inorder traversal
void inorder(struct node* node);

// Prototype for preorder traversal
void preorder(struct node* node);

// Prototype for postorder traversal
void postorder(struct node* node);

// Function to insert a node into a binary tree
struct node* insert(struct node* node, int data)
{
    if (node == NULL)
    {
        node = (struct node*)malloc(sizeof(struct node));
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

// Inorder traversal of a binary tree
void inorder(struct node* node)
{
    if (node)
    {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

// Preorder traversal of a binary tree
void preorder(struct node* node)
{
    if (node)
    {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// Postorder traversal of a binary tree
void postorder(struct node* node)
{
    if (node)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

int main()
{
    struct node* root = NULL;
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    printf("Inorder traversal:");
    inorder(root);
    printf("\n");

    printf("Preorder traversal:");
    preorder(root);
    printf("\n");

    printf("Postorder traversal:");
    postorder(root);
    printf("\n");

    return 0;
}