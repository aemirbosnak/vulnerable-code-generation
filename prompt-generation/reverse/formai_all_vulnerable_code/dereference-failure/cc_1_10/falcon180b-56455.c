//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node with the given data into the binary search tree
void insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }

    if (data < root->data) {
        insertNode(root->left, data);
    } else if (data > root->data) {
        insertNode(root->right, data);
    }
}

// Search for a node with the given data in the binary search tree
struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Print the binary search tree in pre-order traversal
void printTree(struct Node* root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    printf("Pre-order traversal:\n");
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert nodes into the binary search tree
    insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 2);
    insertNode(root, 7);
    insertNode(root, 12);
    insertNode(root, 17);

    // Print the binary search tree
    printf("Binary search tree:\n");
    printTree(root);

    return 0;
}