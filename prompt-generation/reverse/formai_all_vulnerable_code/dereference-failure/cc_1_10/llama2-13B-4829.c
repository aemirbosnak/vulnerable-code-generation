//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Definition of a node
typedef struct node {
    int data;
    struct node *left, *right;
} Node;

// Function to create a new node with the given data
Node* newNode(int data) {
    Node* node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into a binary tree
Node* insertNode(Node** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
        return *root;
    }

    if (data < (*root)->data) {
        insertNode(&(*root)->left, data);
    } else {
        insertNode(&(*root)->right, data);
    }

    return *root;
}

// Function to traverse the binary tree
void traverse(Node* root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Insert nodes into the binary tree
    root = insertNode(&root, 1);
    root = insertNode(&root, 2);
    root = insertNode(&root, 3);
    root = insertNode(&root, 4);
    root = insertNode(&root, 5);

    // Traverse the binary tree
    traverse(root);

    return 0;
}