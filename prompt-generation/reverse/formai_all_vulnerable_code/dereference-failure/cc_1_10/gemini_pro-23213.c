//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Define the structure of a node in the binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

// Create a new node with the given data
node_t* create_node(int data) {
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into the binary tree
node_t* insert_node(node_t *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Search for a node with the given data in the binary tree
node_t* search_node(node_t *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Print the binary tree in preorder traversal
void preorder_traversal(node_t *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Print the binary tree in inorder traversal
void inorder_traversal(node_t *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Print the binary tree in postorder traversal
void postorder_traversal(node_t *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Free the memory allocated for the binary tree
void free_tree(node_t *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

// Main function
int main() {
    // Create a binary tree
    node_t *root = create_node(10);
    insert_node(root, 5);
    insert_node(root, 15);
    insert_node(root, 2);
    insert_node(root, 7);
    insert_node(root, 12);
    insert_node(root, 20);

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

    // Search for a node with the given data in the binary tree
    node_t *found_node = search_node(root, 7);
    if (found_node != NULL) {
        printf("Found node with data %d\n", found_node->data);
    } else {
        printf("Node with data 7 not found\n");
    }

    // Free the memory allocated for the binary tree
    free_tree(root);

    return 0;
}