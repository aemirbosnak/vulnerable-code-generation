//FormAI DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the array as a constant
#define SIZE 10

// Define a structure to represent a node in a binary tree
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node in the binary tree
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary tree
Node* insert(Node* node, int value) {
    // If the node is NULL, create a new node with the given value
    if (node == NULL) {
        return createNode(value);
    }
    // If the value is less than the current node value, insert it into the left subtree
    if (value < node->value) {
        node->left = insert(node->left, value);
    }
    // If the value is greater than or equal to the current node value, insert it into the right subtree
    else {
        node->right = insert(node->right, value);
    }
    return node;
}

// Function to print the binary tree in inorder traversal
void inorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    printf("%d ", node->value);
    inorderTraversal(node->right);
}

int main() {
    Node* root = NULL;
    int arr[SIZE];
    srand(time(NULL));
    printf("Inserting the following values into the binary tree:\n");
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
        root = insert(root, arr[i]);
    }
    printf("\n\n");
    printf("Inorder traversal of the binary tree:\n");
    inorderTraversal(root);
    printf("\n");
    return 0;
}