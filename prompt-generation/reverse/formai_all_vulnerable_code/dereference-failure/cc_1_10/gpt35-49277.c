//FormAI DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
// Welcome to the Cyberpunk Binary Search Tree!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define our struct for the nodes in the tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the tree
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

// Function to print the tree in order
void inOrderTraversal(struct Node* node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
}

// Function to find the minimum node in the tree
struct Node* findMinimum(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMinimum(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    printf("Welcome to the Cyberpunk Binary Search Tree!\n");
    struct Node* root = NULL;

    // Insert nodes into the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the tree in order
    printf("\nIn Order Traversal:\n");
    inOrderTraversal(root);

    // Delete a node from the tree
    printf("\n\nDeleting 40 from the tree...\n");
    root = deleteNode(root, 40);

    // Print the tree in order again
    printf("\nIn Order Traversal:\n");
    inOrderTraversal(root);

    return 0;
}