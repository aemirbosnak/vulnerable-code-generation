//FormAI DATASET v1.0 Category: Binary search trees ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

// Defining a structure for a Binary Search Tree Node
struct bstNode
{
    int data;
    struct bstNode* left;
    struct bstNode* right;
};

// Function to create a new Binary Search Tree Node
struct bstNode* createNode(int data)
{
    struct bstNode* new_node = (struct bstNode*)malloc(sizeof(struct bstNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

// Function to insert a new Node in the Binary Search Tree
struct bstNode* insertNode(struct bstNode* root, int data)
{
    // If the Binary Search Tree is empty, create a new Node
    if(root == NULL)
        return (createNode(data));
    // If the data is smaller than the root Node, Traverse left 
    if(data < root->data)
        root->left = insertNode(root->left, data);
    // If the data is greater than the root Node, Traverse right
    else if(data > root->data)
        root->right = insertNode(root->right, data);
    // Return the unchanged Node pointer
    return root;
}

// Function to search for a Node in the Binary Search Tree
struct bstNode* searchNode(struct bstNode* root, int data)
{
    // If the Binary Search Tree is empty or the Node is found
    if(root == NULL || root->data == data)
        return root;
    // If the data is smaller than the root Node, Traverse left 
    if(data < root->data)
        return searchNode(root->left, data);
    // If the data is greater than the root Node, Traverse right
    return searchNode(root->right, data);
}

// Function to delete a Node from the Binary Search Tree
struct bstNode* deleteNode(struct bstNode* root, int data)
{
    // If the Binary Search Tree is empty, return the root
    if(root == NULL)
        return root;
    // Traverse left if the data is smaller than the root Node
    if(data < root->data)
        root->left = deleteNode(root->left, data);
    // Traverse right if the data is greater than the root Node
    else if(data > root->data)
        root->right = deleteNode(root->right, data);
    // If the Node with the given data is found, delete it
    else
    {
        // If the Node has only one or no child, return the child Node
        if(root->left == NULL)
        {
            struct bstNode* temp = root->right;
            free(root); 
            return temp;
        }
        else if(root->right == NULL)
        {
            struct bstNode* temp = root->left;
            free(root);
            return temp;
        }
        // If the Node has two children
        struct bstNode* temp = root->right;
        while(temp->left != NULL)
            temp = temp->left;
        // Copy the in-order successor's content to this Node
        root->data = temp->data;
        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }
    // Return the unchanged root pointer
    return root;
}

// Function to print the In-order Traversal of the Binary Search Tree
void inorderTraversal(struct bstNode* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct bstNode* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Before Deleting:\t");
    inorderTraversal(root);

    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    root = deleteNode(root, 50);

    printf("\nAfter Deleting:\t\t");
    inorderTraversal(root);

    return 0;   
}