//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node
node *createNode(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the tree
void insertNode(node **root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data < (*root)->data) {
        insertNode(&(*root)->left, data);
    } else if (data > (*root)->data) {
        insertNode(&(*root)->right, data);
    }
}

// Function to search for a node in the tree
node *searchNode(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else if (data > root->data) {
        return searchNode(root->right, data);
    }
}

// Function to print the tree in order
void printTreeInOrder(node *root) {
    if (root == NULL) {
        return;
    }
    printTreeInOrder(root->left);
    printf("%d ", root->data);
    printTreeInOrder(root->right);
}

// Function to print the tree in pre-order
void printTreePreOrder(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}

// Function to print the tree in post-order
void printTreePostOrder(node *root) {
    if (root == NULL) {
        return;
    }
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    // Create the root node
    node *root = NULL;

    // Insert some nodes into the tree
    insertNode(&root, 10);
    insertNode(&root, 5);
    insertNode(&root, 15);
    insertNode(&root, 2);
    insertNode(&root, 7);
    insertNode(&root, 12);
    insertNode(&root, 20);

    // Print the tree in order
    printf("In order: ");
    printTreeInOrder(root);
    printf("\n");

    // Print the tree in pre-order
    printf("Pre-order: ");
    printTreePreOrder(root);
    printf("\n");

    // Print the tree in post-order
    printf("Post-order: ");
    printTreePostOrder(root);
    printf("\n");

    // Search for a node in the tree
    node *foundNode = searchNode(root, 12);
    if (foundNode != NULL) {
        printf("Found node with data %d\n", foundNode->data);
    } else {
        printf("Node with data 12 not found\n");
    }

    return 0;
}