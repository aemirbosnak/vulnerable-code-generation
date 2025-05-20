//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a node into a binary search tree
struct Node* insertNode(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Search for a node in a binary search tree
struct Node* searchNode(struct Node *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data == root->data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    } else if (data > root->data) {
        return searchNode(root->right, data);
    }
    return NULL;
}

// Print the nodes of a binary search tree in order
void printTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// Free the memory allocated for a binary search tree
void freeTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Create a binary search tree
    struct Node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 17);

    // Search for a node in the binary search tree
    struct Node *foundNode = searchNode(root, 12);
    if (foundNode != NULL) {
        printf("Node found: %d\n", foundNode->data);
    } else {
        printf("Node not found\n");
    }

    // Print the nodes of the binary search tree in order
    printf("In order: ");
    printTree(root);
    printf("\n");

    // Free the memory allocated for the binary search tree
    freeTree(root);

    return 0;
}