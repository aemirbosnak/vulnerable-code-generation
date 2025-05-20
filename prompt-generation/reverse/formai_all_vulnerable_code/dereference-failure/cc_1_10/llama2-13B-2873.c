//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Definition of a Node struct
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new Node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to traverse the binary tree
void traverse(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // Print the data of the current node
    printf("%d ", root->data);

    // Recursively traverse the left subtree
    traverse(root->left);

    // Print a newline and recursively traverse the right subtree
    printf("\n");
    traverse(root->right);
}

// Main function
int main() {
    // Create a new Node with data 10
    struct Node* root = newNode(10);

    // Create a new Node with data 20 and make it the left child of root
    struct Node* node20 = newNode(20);
    root->left = node20;

    // Create a new Node with data 30 and make it the right child of root
    struct Node* node30 = newNode(30);
    root->right = node30;

    // Traverse the binary tree
    traverse(root);

    return 0;
}