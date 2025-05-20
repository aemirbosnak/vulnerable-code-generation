//FormAI DATASET v1.0 Category: Binary search trees ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Definition of a Binary Search Tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new Binary Search Tree node
struct node* createNode(int value)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into a Binary Search Tree
struct node* insertNode(struct node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

// Function to perform inorder traversal of a Binary Search Tree
void inorderTraversal(struct node* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to find the node with the given minimum value in a Binary Search Tree
struct node* findMinimumNode(struct node* root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

// Function to delete a node with the given value from a Binary Search Tree
struct node* deleteNode(struct node* root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        // Case 1: Node has no children
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // Case 2: Node has one child
        else if (root->left == NULL)
        {
            struct node* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct node* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Node has two children
        else
        {
            struct node* temp = findMinimumNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

int main()
{
    struct node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Inorder traversal of the Binary Search Tree: ");
    inorderTraversal(root);

    printf("\nDeleting node with value 30 from Binary Search Tree...\n");
    root = deleteNode(root, 30);

    printf("\nInorder traversal of the Binary Search Tree after deletion: ");
    inorderTraversal(root);

    return 0;
}