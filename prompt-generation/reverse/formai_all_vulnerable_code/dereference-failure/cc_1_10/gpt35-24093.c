//FormAI DATASET v1.0 Category: Binary search trees ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of the binary search tree node
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} Node;

// Create a new node with the given data
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node with the given data
Node* insertNode(Node* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Search for a data in the binary search tree
bool searchNode(Node* root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data < root->data)
    {
        return searchNode(root->left, data);
    }
    else if (data > root->data)
    {
        return searchNode(root->right, data);
    }
}

// Traversing the tree in-order
void inOrderTraverse(Node* root)
{
    if (root != NULL)
    {
        inOrderTraverse(root->left);
        printf("%d ", root->data);
        inOrderTraverse(root->right);
    }
}

// Main function
int main()
{
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("In-order Traversal of the Tree:\n");
    inOrderTraverse(root);

    int dataToSearch = 60;
    if (searchNode(root, dataToSearch))
    {
        printf("\n%d is found in the tree!\n", dataToSearch);
    }
    else
    {
        printf("\n%d is not found in the tree!\n", dataToSearch);
    }

    dataToSearch = 100;
    if (searchNode(root, dataToSearch))
    {
        printf("%d is found in the tree!\n", dataToSearch);
    }
    else
    {
        printf("%d is not found in the tree!\n", dataToSearch);
    }

    return 0;
}