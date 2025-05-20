//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node
void insertNode(struct node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }

    if (data < root->data)
        insertNode(root->left, data);
    else
        insertNode(root->right, data);
}

// Function to search a node
int searchNode(struct node* root, int data) {
    if (root == NULL)
        return -1;

    if (data == root->data)
        return 1;

    if (data < root->data)
        return searchNode(root->left, data);
    else
        return searchNode(root->right, data);
}

// Function to inorder traversal of the tree
void inorder(struct node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to print the binary search tree
void printBinarySearchTree(struct node* root) {
    if (root == NULL)
        return;

    printf("Binary Search Tree\n");
    printf("Inorder Traversal\n");
    inorder(root);
    printf("\n");
}

int main() {
    struct node* root = NULL;

    // Insert nodes in the binary search tree
    insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    insertNode(root, 90);

    // Search a node
    int searchData = 60;
    if (searchNode(root, searchData) == 1)
        printf("Node found\n");
    else
        printf("Node not found\n");

    // Print the binary search tree
    printf("\nBinary Search Tree\n");
    printf("Inorder Traversal\n");
    printBinarySearchTree(root);

    return 0;
}