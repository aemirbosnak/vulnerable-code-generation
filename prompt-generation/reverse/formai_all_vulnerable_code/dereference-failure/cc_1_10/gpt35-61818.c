//FormAI DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Definition of the binary search tree node
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* createNode(int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to insert a new node
Node* insertNode(Node* root, int newData) {
    if (root == NULL) {
        return createNode(newData);
    } else if (newData < root->data) {
        root->left = insertNode(root->left, newData);
    } else if (newData > root->data) {
        root->right = insertNode(root->right, newData);
    }
    return root;
}

// Recursive function to search for a node
Node* searchNode(Node* root, int targetData) {
    if (root == NULL || root->data == targetData) {
        return root;
    } else if (targetData < root->data) {
        return searchNode(root->left, targetData);
    } else {
        return searchNode(root->right, targetData);
    }
}

// Recursive function to traverse the tree in-order
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Insert some nodes into the tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Display the tree
    printf("The binary search tree is:\n");
    inOrderTraversal(root);

    // Search for a node
    int targetData = 40;
    Node* targetNode = searchNode(root, targetData);
    printf("\n\nSearching for %d...\n", targetData);
    if (targetNode != NULL) {
        printf("The node exists in the tree!");
    } else {
        printf("The node does not exist in the tree.");
    }

    // Free the memory used by the tree
    free(root);
    return 0;
}