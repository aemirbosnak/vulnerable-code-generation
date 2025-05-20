//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary tree
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node with the given data
Node* newNode(int data) {
    Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to traverse the binary tree in a recursive manner
void traverse(Node* root) {
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

int main() {
    // Create a new node with data 1
    Node* root = newNode(1);

    // Create a new node with data 2 and link it to the left of the root
    Node* node2 = newNode(2);
    root->left = node2;

    // Create a new node with data 3 and link it to the right of the root
    Node* node3 = newNode(3);
    root->right = node3;

    // Traverse the binary tree in a recursive manner
    traverse(root);

    return 0;
}