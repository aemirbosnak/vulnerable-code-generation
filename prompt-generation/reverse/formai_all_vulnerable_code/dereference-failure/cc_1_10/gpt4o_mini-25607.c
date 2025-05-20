//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in a binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform in-order traversal and visualize the tree structure
void inOrder(Node* root, int depth) {
    if (root == NULL) return;

    inOrder(root->right, depth + 1);
    for (int i = 0; i < depth; i++)
        printf("\t");
    printf("%d\n", root->data);
    inOrder(root->left, depth + 1);
}

// Function to insert a node in the binary tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to free the allocated memory for the tree
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function
int main() {
    Node* root = NULL;
    int num;

    printf("Enter integers to insert into the binary search tree (enter -1 to stop):\n");

    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        root = insert(root, num);
    }

    printf("\nIn-Order Traversal of the Binary Search Tree:\n");
    inOrder(root, 0);

    freeTree(root);
    return 0;
}