//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Define a node in the binary tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Create a new node in the binary tree with the provided data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node into the binary tree
Node* insertNode(Node *node, int data) {
    if(node == NULL) {
        return createNode(data);
    }
    if(data <= node->data) {
        node->left = insertNode(node->left, data);
    } else {
        node->right = insertNode(node->right, data);
    }
    return node;
}

// Traverse the binary tree recursively in order to visualize it
void printTree(Node *node, int depth) {
    if(node == NULL) {
        return;
    }
    printTree(node->right, depth + 1);
    printf("%*s%d\n", depth * 4, "", node->data);
    printTree(node->left, depth + 1);
}

int main() {
    // Create an example binary tree
    Node *root = NULL;
    root = insertNode(root, 5);
    insertNode(root, 2);
    insertNode(root, 8);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 9);

    // Visualize the binary tree
    printTree(root, 0);

    return 0;
}