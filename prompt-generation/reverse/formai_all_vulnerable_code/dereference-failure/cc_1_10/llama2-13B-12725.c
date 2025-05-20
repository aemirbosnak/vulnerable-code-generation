//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node of the search tree
typedef struct node {
    int data; // the data stored in the node
    struct node* left; // the left child node
    struct node* right; // the right child node
} node;

// Define a function to create a new node with the given data
node* newNode(int data) {
    node* node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define a function to search the tree
node* search(node* root, int target) {
    // Base case: if the root is NULL, return NULL
    if (root == NULL) {
        return NULL;
    }

    // Compare the target with the data in the root node
    if (root->data == target) {
        // If the target is found, return the root node
        return root;
    }

    // Recursively search the left and right child nodes
    node* leftNode = search(root->left, target);
    node* rightNode = search(root->right, target);

    // If the target is found in the left child node, return the left child node
    if (leftNode != NULL) {
        return leftNode;
    }

    // If the target is found in the right child node, return the right child node
    if (rightNode != NULL) {
        return rightNode;
    }

    // If the target is not found in the tree, return NULL
    return NULL;
}

int main() {
    // Create a new node with the data 10
    node* root = newNode(10);

    // Create a new node with the data 5 and add it to the left child node
    node* five = newNode(5);
    root->left = five;

    // Create a new node with the data 15 and add it to the right child node
    node* fifteen = newNode(15);
    root->right = fifteen;

    // Search the tree for the data 12
    node* result = search(root, 12);

    // Print the result of the search
    if (result != NULL) {
        printf("The data %d is found in the tree\n", result->data);
    } else {
        printf("The data %d is not found in the tree\n", 12);
    }

    return 0;
}