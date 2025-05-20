//FormAI DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct for the binary search tree node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node to the BST
Node *insertNode(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (root->data > data) {
        root->left = insertNode(root->left, data);
    } else if (root->data < data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for a node in the BST
bool searchNode(Node *root, int data) {
    if (root == NULL) {
        return false;
    } else if (root->data == data) {
        return true;
    } else if (root->data > data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Function to print the BST using in-order traversal
void printBST(Node *root) {
    if (root != NULL) {
        printBST(root->left);
        printf("%d ", root->data);
        printBST(root->right);
    }
}

int main() {
    Node *root = NULL;

    // Aysnchronous insertion of nodes
    root = insertNode(root, 50);
    #pragma omp task shared(root)
    {
        insertNode(root, 30);
    }
    #pragma omp task shared(root)
    {
        insertNode(root, 20);
    }
    #pragma omp task shared(root)
    {
        insertNode(root, 40);
    }
    #pragma omp task shared(root)
    {
        insertNode(root, 70);
    }
    #pragma omp task shared(root)
    {
        insertNode(root, 60);
    }
    #pragma omp task shared(root)
    {
        insertNode(root, 80);
    }
    #pragma omp taskwait

    // Printing the BST in-order after the insertion
    printBST(root);

    // Asynchronous searching for a node in the BST
    int searchData = 60;
    bool searchResult = false;
    #pragma omp parallel shared(root, searchData) reduction(||:searchResult)
    {
        searchResult = searchResult || searchNode(root, searchData);
    }
    if (searchResult) {
        printf("\n%d is found in the BST", searchData);
    } else {
        printf("\n%d is not found in the BST", searchData);
    }

    return 0;
}