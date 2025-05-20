//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary search tree node
struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Function to create a new BST node
struct BSTNode* createNode(int data) {
    struct BSTNode *newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct BSTNode* insertNode(struct BSTNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for a node in the BST
struct BSTNode* searchNode(struct BSTNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    }
    return searchNode(root->right, data);
}

// Function to find the minimum node in the BST
struct BSTNode* findMin(struct BSTNode* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct BSTNode* deleteNode(struct BSTNode* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct BSTNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BSTNode *temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor
        struct BSTNode *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform inorder traversal of the BST
void inorderTraversal(struct BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Helper function to demonstrate BST operations
void demonstrateBST() {
    struct BSTNode *root = NULL;
    
    // Insert nodes
    int values[] = {15, 10, 20, 8, 12, 17, 25};
    for(int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        root = insertNode(root, values[i]);
    }
    
    printf("Inorder Traversal of BST:\n");
    inorderTraversal(root);
    printf("\n");

    // Search for nodes
    int searchValues[] = {12, 3, 25};
    for(int i = 0; i < sizeof(searchValues) / sizeof(searchValues[0]); i++) {
        struct BSTNode *found = searchNode(root, searchValues[i]);
        if (found) {
            printf("Node %d found in BST.\n", found->data);
        } else {
            printf("Node %d not found in BST.\n", searchValues[i]);
        }
    }

    // Deleting nodes
    printf("Deleting node 10 from BST...\n");
    root = deleteNode(root, 10);
    printf("Inorder Traversal after deletion:\n");
    inorderTraversal(root);
    printf("\n");
    
    printf("Deleting node 17 from BST...\n");
    root = deleteNode(root, 17);
    printf("Inorder Traversal after deletion:\n");
    inorderTraversal(root);
    printf("\n");

    // Freeing the dynamically allocated memory
    while (root != NULL) {
        root = deleteNode(root, root->data);
    }
}

// Main function
int main() {
    printf("Welcome to the Visionary Binary Search Tree Program!\n");
    demonstrateBST();
    printf("Thank you for exploring BST with us!\n");
    return 0;
}