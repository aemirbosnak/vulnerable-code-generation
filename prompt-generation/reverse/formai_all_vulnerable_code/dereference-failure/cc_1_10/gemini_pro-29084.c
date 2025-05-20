//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the binary tree
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

// Function to find the minimum value in the binary tree
int find_min(struct node *root) {
    if (root->left == NULL) {
        return root->data;
    } else {
        return find_min(root->left);
    }
}

// Function to find the maximum value in the binary tree
int find_max(struct node *root) {
    if (root->right == NULL) {
        return root->data;
    } else {
        return find_max(root->right);
    }
}

// Function to find the height of the binary tree
int find_height(struct node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

// Function to check if the binary tree is balanced
int is_balanced(struct node *root) {
    if (root == NULL) {
        return 1;
    } else {
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        return (abs(left_height - right_height) <= 1) && is_balanced(root->left) && is_balanced(root->right);
    }
}

// Function to print the binary tree in preorder traversal
void preorder_traversal(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Function to print the binary tree in inorder traversal
void inorder_traversal(struct node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Function to print the binary tree in postorder traversal
void postorder_traversal(struct node *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to free the memory allocated for the binary tree
void free_tree(struct node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

// Main function
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

    // Print the binary tree in preorder traversal
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    // Print the binary tree in inorder traversal
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    // Print the binary tree in postorder traversal
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    // Find the minimum value in the binary tree
    printf("Minimum value: %d\n", find_min(root));

    // Find the maximum value in the binary tree
    printf("Maximum value: %d\n", find_max(root));

    // Find the height of the binary tree
    printf("Height of the binary tree: %d\n", find_height(root));

    // Check if the binary tree is balanced
    if (is_balanced(root)) {
        printf("The binary tree is balanced.\n");
    } else {
        printf("The binary tree is not balanced.\n");
    }

    // Free the memory allocated for the binary tree
    free_tree(root);

    return 0;
}