//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Node structure for binary search tree
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary search tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a node in the binary search tree
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to print the binary search tree inorder
void printInorder(struct node* root) {
    if (root!= NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

int main() {
    // Create root node
    struct node* root = NULL;

    // Insert nodes into the binary search tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 90);

    // Search for a node in the binary search tree
    struct node* searchedNode = search(root, 50);

    // Print the binary search tree inorder
    printf("Binary Search Tree Inorder Traversal: ");
    printInorder(root);

    if (searchedNode!= NULL) {
        printf("Node %d found at index %d.\n", searchedNode->data, root->data);
    } else {
        printf("Node %d not found in the binary search tree.\n", searchedNode->data);
    }

    return 0;
}