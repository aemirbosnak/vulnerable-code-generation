//FormAI DATASET v1.0 Category: Binary search trees ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// A node structure for binary search tree
struct node {
    int value;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* create_node(int value) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Recursive function to insert a value in binary search tree
struct node* insert(struct node* node, int value) {
    if (node == NULL) {
        return create_node(value);
    } else if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    }
    return node;
}

// Function to search for a value in binary search tree
int search(struct node* node, int value) {
    if (node == NULL) {
        return 0;
    } else if (node->value == value) {
        return 1;
    } else if (value < node->value) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

// Function to print binary search tree in preorder traversal
void preorder(struct node* node) {
    if (node != NULL) {
        printf("%d ", node->value);
        preorder(node->left);
        preorder(node->right);
    }
}

// Main function to test the binary search tree implementation
int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Binary search tree in preorder traversal: ");
    preorder(root);
    printf("\n");

    int value = 60;
    if (search(root, value)) {
        printf("%d is present in binary search tree.\n", value);
    } else {
        printf("%d is not present in binary search tree.\n", value);
    }

    return 0;
}