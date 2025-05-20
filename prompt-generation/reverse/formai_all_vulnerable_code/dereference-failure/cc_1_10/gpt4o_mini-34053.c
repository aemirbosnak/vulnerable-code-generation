//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Uh oh! Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert data into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        printf("🎉 Surprise! Inserting %d in the BST!\n", data);
        return createNode(data);
    }
    if (data < root->data) {
        printf("👀 Going left from %d to insert %d...\n", root->data, data);
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        printf("➡️ Going right from %d to insert %d...\n", root->data, data);
        root->right = insert(root->right, data);
    } else {
        printf("😱 %d already exists in the BST. No duplicates allowed!\n", data);
    }
    return root;
}

// Search for a value in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL) {
        printf("🔍 Key %d not found! What a mystery!\n", key);
        return NULL;
    }
    if (root->data == key) {
        printf("✨ Found %d! Hooray!\n", key);
        return root;
    } else if (key < root->data) {
        printf("🔄 Searching left from %d for %d...\n", root->data, key);
        return search(root->left, key);
    } else {
        printf("🔄 Searching right from %d for %d...\n", root->data, key);
        return search(root->right, key);
    }
}

// In-order traversal of the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Free the memory of the BST
void freeTree(struct Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        printf("🧹 Cleaning up node with value %d...\n", root->data);
        free(root);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Let's do some searching
    printf("\nSearching for values:\n");
    search(root, 25);
    search(root, 40);
    search(root, 70);

    // Display the BST
    printf("\nIn-order traversal of the BST: ");
    inorder(root);
    printf("\n");

    // Free the allocated memory
    freeTree(root);
    
    printf("🎇 All nodes have been cleaned up. Until next time!\n");
    return 0;
}