//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for a binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node into a binary tree
node *insert_node(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to create a binary tree from an array
node *create_tree(int *arr, int size) {
    node *root = NULL;
    for (int i = 0; i < size; i++) {
        root = insert_node(root, arr[i]);
    }
    return root;
}

// Function to find the height of a binary tree
int height(node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_height = height(root->left);
        int right_height = height(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

// Function to print the binary tree in a visual format
void print_tree(node *root, int space) {
    if (root == NULL) {
        return;
    }
    space += 5;
    print_tree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    print_tree(root->left, space);
}

// Main function
int main() {
    // Create an array of integers
    int arr[] = {10, 5, 15, 2, 7, 12, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create a binary tree from the array
    node *root = create_tree(arr, size);

    // Print the binary tree in a visual format
    print_tree(root, 0);

    return 0;
}