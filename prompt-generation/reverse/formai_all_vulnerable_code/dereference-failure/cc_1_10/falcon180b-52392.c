//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node with the given data
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the binary search tree
struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

// Function to search for a node in the binary search tree
struct node *search_node(struct node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Function to print the binary search tree in order
void print_tree(struct node *root) {
    if (root!= NULL) {
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}

int main() {
    // Create the root node of the binary search tree
    struct node *root = NULL;

    // Insert nodes into the binary search tree
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    // Print the binary search tree in order
    printf("Binary Search Tree:\n");
    print_tree(root);

    return 0;
}