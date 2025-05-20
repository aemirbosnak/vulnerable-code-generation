//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node into the binary search tree
void insertNode(struct Node** root, int data) {
    struct Node* node = newNode(data);

    if (*root == NULL) {
        *root = node;
    } else if (data < (*root)->data) {
        insertNode(&(*root)->left, data);
    } else {
        insertNode(&(*root)->right, data);
    }
}

// Function to search for a node in the binary search tree
struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    } else if (data > root->data) {
        return searchNode(root->right, data);
    } else {
        return root;
    }
}

// Function to print the binary search tree
void printTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

int main() {
    struct Node* root = NULL;

    insertNode(&root, 5);
    insertNode(&root, 2);
    insertNode(&root, 8);
    insertNode(&root, 3);
    insertNode(&root, 1);
    insertNode(&root, 6);

    printf("Binary Search Tree:\n");
    printTree(root);

    struct Node* node = searchNode(root, 4);
    if (node != NULL) {
        printf("Found %d at depth %d\n", node->data, depth(node));
    } else {
        printf("Not found\n");
    }

    return 0;
}

// Function to calculate the depth of a node
int depth(struct Node* node) {
    if (node == NULL) {
        return 0;
    }

    return 1 + depth(node->left) + depth(node->right);
}