//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Definition of a Node structure
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new Node
Node* newNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to traverse the binary tree
void traverse(Node* root) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    traverse(root->left);

    // Print the current node
    printf("%d ", root->data);

    // Traverse the right subtree
    traverse(root->right);
}

// Function to test the binary tree
int main() {
    // Create the binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Traverse the binary tree
    traverse(root);

    return 0;
}