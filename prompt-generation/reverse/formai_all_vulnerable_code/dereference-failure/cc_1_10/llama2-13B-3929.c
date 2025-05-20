//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to traverse the tree in-order
void inOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // Recursively traverse the left subtree
    inOrderTraversal(root->left);

    // Print the current node's data
    printf("%d ", root->data);

    // Recursively traverse the right subtree
    inOrderTraversal(root->right);
}

int main() {
    // Create a new node with data 1
    struct Node* root = newNode(1);

    // Create a new node with data 2 and add it as the left child of root
    struct Node* node2 = newNode(2);
    root->left = node2;

    // Create a new node with data 3 and add it as the right child of root
    struct Node* node3 = newNode(3);
    root->right = node3;

    // Traverse the tree in-order
    inOrderTraversal(root);

    return 0;
}