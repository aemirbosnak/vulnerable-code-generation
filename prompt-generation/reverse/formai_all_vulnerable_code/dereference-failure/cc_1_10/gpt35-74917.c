//FormAI DATASET v1.0 Category: Binary search trees ; Style: unmistakable
// A unique example program of Binary Search Trees
#include <stdio.h>
#include <stdlib.h>

// Define the structure of each node in the BST
typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with a given value
Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node with a given value into the BST
Node* insert(Node* root, int value) {
    // If the root is null, create a new node and return it
    if (root == NULL) {
        return create_node(value);
    }

    // If the value is less than the root's value, recursively insert into the left subtree 
    if (value < root->value) {
        root->left = insert(root->left, value);
    }

    // If the value is greater than or equal to the root's value, recursively insert into the right subtree
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to print the inorder traversal of the BST
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

int main() {
    // Create an empty BST
    Node* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 9);
    root = insert(root, 2);

    // Print the inorder traversal of the BST
    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    return 0;
}