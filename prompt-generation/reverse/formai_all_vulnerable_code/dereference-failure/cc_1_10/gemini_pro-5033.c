//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in a binary tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// A function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// A function to insert a new node into a binary tree
struct Node* insertNode(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// A function to print the binary tree in a happy style
void printTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("(%d) ", root->data);
    if (root->left != NULL) {
        printf(" <-- ");
        printTree(root->left);
    }
    if (root->right != NULL) {
        printf(" --> ");
        printTree(root->right);
    }
}

// A function to free the binary tree
void freeTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Create a binary tree
    struct Node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 2);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 20);

    // Print the binary tree in a happy style
    printTree(root);

    // Free the binary tree
    freeTree(root);

    return 0;
}