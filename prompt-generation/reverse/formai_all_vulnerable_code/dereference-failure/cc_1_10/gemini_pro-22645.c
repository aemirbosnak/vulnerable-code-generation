//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure of a node in a binary tree
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

// Function to insert a new node into a binary tree
struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to find the minimum value in a binary tree
int find_min(struct node *root) {
    if (root == NULL) {
        return -1;
    } else if (root->left == NULL) {
        return root->data;
    } else {
        return find_min(root->left);
    }
}

// Function to find the maximum value in a binary tree
int find_max(struct node *root) {
    if (root == NULL) {
        return -1;
    } else if (root->right == NULL) {
        return root->data;
    } else {
        return find_max(root->right);
    }
}

// Function to print the inorder traversal of a binary tree
void inorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Function to print the preorder traversal of a binary tree
void preorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Function to print the postorder traversal of a binary tree
void postorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to test the binary tree functions
int main() {
    // Create a binary tree
    struct node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    // Print the inorder traversal of the binary tree
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    // Print the preorder traversal of the binary tree
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    // Print the postorder traversal of the binary tree
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    // Find the minimum value in the binary tree
    int min = find_min(root);
    printf("Minimum value: %d\n", min);

    // Find the maximum value in the binary tree
    int max = find_max(root);
    printf("Maximum value: %d\n", max);

    return 0;
}