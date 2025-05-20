//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: surprised
// This program will visualize a binary tree data structure in a unique and surprising way!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the node structure for our binary tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to print the binary tree in a surprising way!
void printTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10;

    printTree(root->right, space);

    for (int i = 10; i < space; i++) {
        printf(" ");
    }

    printf("%d\n", root->data);

    printTree(root->left, space);
}

// Main function to test our binary tree visualization
int main() {
    srand(time(NULL));

    Node* root = NULL;

    // Insert some random data into the tree
    for (int i = 0; i < 10; i++) {
        int data = rand() % 100;
        root = insertNode(root, data);
    }

    // Print the surprising visualization of our binary tree!
    printf("Surprising Binary Tree Visualization:\n");
    printTree(root, 0);

    return 0;
}