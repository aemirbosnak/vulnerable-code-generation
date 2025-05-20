//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: optimized
#include <stdio.h>

// Node structure
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node
void insertNode(struct Node* node, int key) {
    if (node == NULL) {
        node = createNode(key);
    } else if (key < node->key) {
        insertNode(node->left, key);
    } else {
        insertNode(node->right, key);
    }
}

// Inorder traversal
void inorderTraversal(struct Node* node) {
    if (node!= NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->key);
        inorderTraversal(node->right);
    }
}

// Print the tree
void printTree(struct Node* node) {
    if (node!= NULL) {
        printTree(node->left);
        printf("%d ", node->key);
        printTree(node->right);
    }
}

int main() {
    // Create the root node
    struct Node* root = NULL;

    // Insert 10 nodes
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 1);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 8);
    insertNode(root, 9);
    insertNode(root, 0);

    // Print the tree
    printTree(root);

    return 0;
}