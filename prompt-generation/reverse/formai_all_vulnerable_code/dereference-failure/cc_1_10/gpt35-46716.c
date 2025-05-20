//FormAI DATASET v1.0 Category: Binary search trees ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node_t;

// Function to create a new node
node_t* create_node(int value) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the tree
node_t* insert(node_t* root, int value) {
    // If the root is null, create a new node with the given value and return it
    if (root == NULL) {
        return create_node(value);
    }
    // If the given value is less than the root node value, insert it into the left subtree
    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    // If the given value is greater than or equal to the root node value, insert it into the right subtree
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a given value in the tree
node_t* search(node_t* root, int value) {
    // If the root is null, the value is not in the tree
    if (root == NULL) {
        return NULL;
    }
    // If the given value is less than the root node value, search the left subtree
    if (value < root->value) {
        return search(root->left, value);
    }
    // If the given value is greater than the root node value, search the right subtree
    else if (value > root->value) {
        return search(root->right, value);
    }
    // If the given value is equal to the root node value, return the root node
    else {
        return root;
    }
}

// Function to print the values of the tree in inorder traversal
void print_inorder(node_t* root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->value);
        print_inorder(root->right);
    }
}

// Main function to test the BST implementation
int main() {
    node_t* root = NULL;
    printf("Inserting values:\n");
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("Inorder traversal of the tree:\n");
    print_inorder(root);
    printf("\nSearching for values:\n");
    node_t* search_node = search(root, 50);
    printf("Value found: %d\n", search_node->value);
    search_node = search(root, 90);
    if (search_node == NULL) {
        printf("Value not found\n");
    }
    return 0;
}