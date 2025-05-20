//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary tree
typedef struct node {
    int data;
    struct node *left, *right;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
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

    // Print a new line and recursively traverse the right subtree
    printf("\n");
    traverse(root->right);
}

int main() {
    // Create a binary tree with the following structure:
    //       1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    // Traverse the binary tree using the recursive function
    traverse(root);

    return 0;
}