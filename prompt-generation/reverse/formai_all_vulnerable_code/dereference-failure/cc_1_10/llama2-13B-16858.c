//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Definition of a node
typedef struct node {
    int data;
    struct node *left, *right;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to print the tree in an automated style
void printTree(Node* root) {
    if (root == NULL) {
        printf("()\n");
        return;
    }

    // Print the node's data and the left subtree
    printf("%d ", root->data);
    printTree(root->left);

    // Print a space and the right subtree
    printf(" ");
    printTree(root->right);

    // Print a new line at the end
    printf("\n");
}

int main() {
    // Create a new root node
    Node* root = newNode(1);

    // Create the left and right subtrees
    root->left = newNode(2);
    root->right = newNode(3);

    // Print the tree in an automated style
    printTree(root);

    return 0;
}