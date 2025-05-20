//FormAI DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure for binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to insert node into binary search tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to perform inorder traversal of binary search tree
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}

int main() {
    // Initialize binary search tree
    Node* root = NULL;

    // Insert randomly generated values
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int value = rand() % 100;
        root = insert(root, value);
    }

    // Perform inorder traversal and print values
    printf("Inorder Traversal of Binary Search Tree:");
    inorder(root);

    return 0;
}