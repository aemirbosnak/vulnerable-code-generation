//FormAI DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define structure for binary tree node
struct btnode {
    int data;
    struct btnode *left;
    struct btnode *right;
};

// Function to create a new node with given data
struct btnode* createNode(int data) {
    struct btnode *new_node = (struct btnode*)malloc(sizeof(struct btnode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node with given data into the tree
struct btnode* insert(struct btnode *node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to find the node with the smallest value
struct btnode* findMin(struct btnode *node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->left != NULL) {
        return findMin(node->left);
    }
    return node;
}

// Function to delete a node with given data from the tree
struct btnode* delete(struct btnode *node, int data) {
    if (node == NULL) {
        return NULL;
    }
    if (data < node->data) {
        node->left = delete(node->left, data);
    } else if (data > node->data) {
        node->right = delete(node->right, data);
    } else {
        if (node->left == NULL) {
            struct btnode *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct btnode *temp = node->left;
            free(node);
            return temp;
        }
        struct btnode *temp = findMin(node->right);
        node->data = temp->data;
        node->right = delete(node->right, temp->data);
    }
    return node;
}

// Function to perform inorder traversal of the tree
void inorder(struct btnode *node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%d\n", node->data);
    inorder(node->right);
}

// Main function to test the implementation
int main() {
    struct btnode *root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    printf("Inorder traversal:\n");
    inorder(root);
    root = delete(root, 30);
    printf("Inorder traversal after deleting 30:\n");
    inorder(root);
    return 0;
}