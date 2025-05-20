//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a binary tree node structure
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to inorder traversal of a binary tree
void inorder(Node* node)
{
    if (node)
    {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

// Function to preorder traversal of a binary tree
void preorder(Node* node)
{
    if (node)
    {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// Function to postorder traversal of a binary tree
void postorder(Node* node)
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
    // Create a binary tree
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = 10;
    root->left = (Node*)malloc(sizeof(Node));
    root->left->data = 5;
    root->right = (Node*)malloc(sizeof(Node));
    root->right->data = 15;

    // Inorder traversal
    printf("Inorder traversal:");
    inorder(root);
    printf("\n");

    // Preorder traversal
    printf("Preorder traversal:");
    preorder(root);
    printf("\n");

    // Postorder traversal
    printf("Postorder traversal:");
    postorder(root);
    printf("\n");

    return 0;
}