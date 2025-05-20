//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of nodes in the tree
#define MAX_NODES 100

// Define the structure of a node
typedef struct {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Create a new node with the given data
Node *createNode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a node into the tree
void insertNode(Node *root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }

    if (data < root->data) {
        insertNode(root->left, data);
    } else {
        insertNode(root->right, data);
    }
}

// Traverse the tree in-order
void inOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Traverse the tree pre-order
void preOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Traverse the tree post-order
void postOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    Node *root = NULL;

    // Insert nodes into the tree
    insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Traverse the tree in-order
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Traverse the tree pre-order
    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    // Traverse the tree post-order
    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}