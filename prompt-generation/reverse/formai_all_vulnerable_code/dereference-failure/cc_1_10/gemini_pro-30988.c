//GEMINI-pro DATASET v1.0 Category: Educational ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A custom data structure to represent a node in a binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

// A function to create a new node with the given data
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// A function to insert a new node into a binary tree
node_t *insert_node(node_t *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data <= root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// A function to search for a node with the given data in a binary tree
node_t *search_node(node_t *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data <= root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// A function to print the inorder traversal of a binary tree
void inorder_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

// A function to print the preorder traversal of a binary tree
void preorder_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// A function to print the postorder traversal of a binary tree
void postorder_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

// A function to find the height of a binary tree
int height(node_t *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_height = height(root->left);
        int right_height = height(root->right);
        if (left_height > right_height) {
            return left_height + 1;
        } else {
            return right_height + 1;
        }
    }
}

int main() {
    // Create a binary tree
    node_t *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 3);
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

    // Find the height of the binary tree
    int tree_height = height(root);
    printf("Height of the binary tree: %d\n", tree_height);

    // Search for a node with the given data in the binary tree
    node_t *found_node = search_node(root, 7);
    if (found_node != NULL) {
        printf("Node with data 7 found!\n");
    } else {
        printf("Node with data 7 not found!\n");
    }

    return 0;
}