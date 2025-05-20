//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insert(struct Node* node, int data);
struct Node* search(struct Node* root, int data);
void inorderTraversal(struct Node* root);
void freeTree(struct Node* root);

// Main function
int main() {
    struct Node* root = NULL;

    // Insert data into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Inorder traversal of the BST
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a number
    int searchNumber = 40;
    struct Node* searchResult = search(root, searchNumber);
    if (searchResult != NULL) {
        printf("Found %d in the BST.\n", searchNumber);
    } else {
        printf("%d not found in the BST.\n", searchNumber);
    }

    // Free memory
    freeTree(root);
    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insert(struct Node* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return createNode(data);
    }

    // Otherwise, recurse down the tree
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    // Return the unchanged node pointer
    return node;
}

// Function to search for a given value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    // Recur down the tree
    if (data < root->data) {
        return search(root->left, data);
    }
    
    return search(root->right, data);
}

// Function for inorder traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to free the memory allocated for the tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}