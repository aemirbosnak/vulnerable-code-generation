//FormAI DATASET v1.0 Category: Binary search trees ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the Binary Search Tree Node
struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

// Create a new node with the given data
struct BstNode* createNode(int data) {
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node in the Binary Search Tree
struct BstNode* insertNode(struct BstNode* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Search for a node with the given data in the Binary Search Tree
struct BstNode* searchNode(struct BstNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (data <= root->data) {
        return searchNode(root->left, data);
    }
    else {
        return searchNode(root->right, data);
    }
}

// Find the minimum value in the Binary Search Tree
int findMin(struct BstNode* root) {
    if (root == NULL) {
        printf("Error: Tree is empty.\n");
        return -1;
    }
    else if (root->left == NULL) {
        return root->data;
    }
    else {
        return findMin(root->left);
    }
}

// Find the maximum value in the Binary Search Tree
int findMax(struct BstNode* root) {
    if (root == NULL) {
        printf("Error: Tree is empty.\n");
        return -1;
    }
    else if (root->right == NULL) {
        return root->data;
    }
    else {
        return findMax(root->right);
    }
}

// Traverse the Binary Search Tree in preorder
void preorderTraversal(struct BstNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Traverse the Binary Search Tree in inorder
void inorderTraversal(struct BstNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Traverse the Binary Search Tree in postorder
void postorderTraversal(struct BstNode* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    struct BstNode* root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 25);
    root = insertNode(root, 8);
    root = insertNode(root, 12);

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");
    
    int searchData = 25;
    if (searchNode(root, searchData) != NULL) {
        printf("%d is found in the Binary Search Tree.\n", searchData);
    }
    else {
        printf("%d is not found in the Binary Search Tree.\n", searchData);
    }
    
    printf("Minimum value in the Binary Search Tree: %d\n", findMin(root));
    printf("Maximum value in the Binary Search Tree: %d\n", findMax(root));

    return 0;
}