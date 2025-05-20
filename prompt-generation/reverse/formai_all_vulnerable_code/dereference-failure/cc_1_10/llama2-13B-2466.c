//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_DEPTH 10
#define MAX_STR_LEN 50

// Structure to represent a node in the recursive tree
typedef struct node {
    int data;
    struct node *left, *right;
} Node;

// Function to create a new node with the given data
Node* new_node(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to traverse the recursive tree
void traverse(Node* root) {
    if (root == NULL) {
        return;
    }

    // Print the data of the current node
    printf("%d ", root->data);

    // Traverse the left subtree
    traverse(root->left);

    // Traverse the right subtree
    traverse(root->right);
}

// Main function to test the recursive tree
int main() {
    // Create a new node with data 1
    Node* root = new_node(1);

    // Create a new node with data 2 and make it the left child of root
    Node* node2 = new_node(2);
    root->left = node2;

    // Create a new node with data 3 and make it the right child of root
    Node* node3 = new_node(3);
    root->right = node3;

    // Traverse the recursive tree
    traverse(root);

    return 0;
}