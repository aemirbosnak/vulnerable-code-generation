//FormAI DATASET v1.0 Category: Binary search trees ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// A sample Binary Search Tree node
struct BSTnode
{
    int data;
    struct BSTnode *left;
    struct BSTnode *right;
};

// Function to create a new BST node
struct BSTnode *newNode(int key)
{
    struct BSTnode *new_node =  (struct BSTnode *)malloc(sizeof(struct BSTnode));
    new_node->data = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
};

// Function to insert a new node in BST
struct BSTnode *insert(struct BSTnode *node, int data)
{
    if (node == NULL) return newNode(data);
 
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);   
 
    return node;
}

// Function to print BST in inorder traversal
void inorderTraversal(struct BSTnode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function
int main()
{
    struct BSTnode *root = NULL;
    root = insert(root, 50);
    insert(root, 20);
    insert(root, 60);
    insert(root, 30);
    insert(root, 70);
    insert(root, 80);
 
    printf("Inorder traversal of BST is: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}