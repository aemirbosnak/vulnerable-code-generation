//FormAI DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LEN 50

// Binary Search Tree Node Definition
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node_t;

// Function to create a new node
node_t *newNode(int value) {
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->value = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node into the tree
void insertNode(node_t **root, int value) {
    if (*root == NULL) {
        *root = newNode(value);
        return;
    }
    if (value < (*root)->value) {
        insertNode(&(*root)->left, value);
    } else {
        insertNode(&(*root)->right, value);
    }
}

// Function to find minimum value node in the tree
node_t *minValueNode(node_t *node) {
    node_t *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the tree
node_t *deleteNode(node_t *root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            node_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node_t *temp = root->left;
            free(root);
            return temp;
        }
        node_t *temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

// Function to print the nodes in the tree in-order 
void printInOrder(node_t *root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->value);
    printInOrder(root->right);
}

int main() {
    node_t *root = NULL;

    // Insert some nodes
    insertNode(&root, 4);
    insertNode(&root, 2);
    insertNode(&root, 7);
    insertNode(&root, 1);
    insertNode(&root, 3);

    // Print out the nodes in the tree
    printf("In-Order: ");
    printInOrder(root);
    printf("\n");

    // Delete a node and print out the nodes in the tree again
    root = deleteNode(root, 4);
    printf("In-Order: ");
    printInOrder(root);
    printf("\n");

    return 0;
}