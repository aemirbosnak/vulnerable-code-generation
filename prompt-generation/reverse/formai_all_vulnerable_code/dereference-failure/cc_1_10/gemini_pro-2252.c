//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in a binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node with the given data
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node with the given data into the binary tree
node *insert_node(node *root, int data) {
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
int find_min(node *root) {
    if (root == NULL) {
        return -1;  // Error: empty tree
    } else if (root->left == NULL) {
        return root->data;
    } else {
        return find_min(root->left);
    }
}

// Function to find the maximum value in the binary tree
int find_max(node *root) {
    if (root == NULL) {
        return -1;  // Error: empty tree
    } else if (root->right == NULL) {
        return root->data;
    } else {
        return find_max(root->right);
    }
}

// Function to find the height of the binary tree
int find_height(node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

// Function to print the binary tree in preorder traversal
void print_preorder(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
}

// Function to print the binary tree in inorder traversal
void print_inorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

// Function to print the binary tree in postorder traversal
void print_postorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->data);
}

// Driver code
int main() {
    // Create a binary tree
    node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    // Find the minimum value in the binary tree
    int min_value = find_min(root);
    printf("Minimum value: %d\n", min_value);

    // Find the maximum value in the binary tree
    int max_value = find_max(root);
    printf("Maximum value: %d\n", max_value);

    // Find the height of the binary tree
    int height = find_height(root);
    printf("Height of the binary tree: %d\n", height);

    // Print the binary tree in preorder traversal
    printf("Preorder traversal: ");
    print_preorder(root);
    printf("\n");

    // Print the binary tree in inorder traversal
    printf("Inorder traversal: ");
    print_inorder(root);
    printf("\n");

    // Print the binary tree in postorder traversal
    printf("Postorder traversal: ");
    print_postorder(root);
    printf("\n");

    return 0;
}