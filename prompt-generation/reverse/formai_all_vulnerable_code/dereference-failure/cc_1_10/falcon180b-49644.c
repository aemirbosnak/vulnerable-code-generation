//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define node structure for binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert data into the tree
Node* insert(Node* node, int data) {
    if (node == NULL) {
        node = newNode(data);
    } else if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

// Function to print the tree in order traversal
void printTree(Node* node) {
    if (node == NULL) {
        return;
    }

    printTree(node->left);
    printf("%d ", node->data);
    printTree(node->right);
}

// Main function to test the implementation
int main() {
    Node* root = NULL;

    // Insert data into the tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 17);

    // Print the tree in order traversal
    printf("Order traversal of the tree is: ");
    printTree(root);

    return 0;
}