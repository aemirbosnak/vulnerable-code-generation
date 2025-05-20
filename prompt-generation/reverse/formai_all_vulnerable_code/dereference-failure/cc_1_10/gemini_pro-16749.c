//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A node in a binary tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with the given data
struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function to insert a new node into the binary tree
struct Node *insertNode(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to find the minimum value in the binary tree
int findMin(struct Node *root) {
    if (root == NULL) {
        return INT_MAX;
    }

    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);

    return fmin(root->data, fmin(leftMin, rightMin));
}

// Function to find the maximum value in the binary tree
int findMax(struct Node *root) {
    if (root == NULL) {
        return INT_MIN;
    }

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    return fmax(root->data, fmax(leftMax, rightMax));
}

// Function to check if the binary tree is a binary search tree
int isBST(struct Node *root) {
    if (root == NULL) {
        return 1;
    }

    if (root->left != NULL && root->data < findMax(root->left)) {
        return 0;
    }

    if (root->right != NULL && root->data > findMin(root->right)) {
        return 0;
    }

    return isBST(root->left) && isBST(root->right);
}

// Function to print the binary tree in preorder traversal
void preorder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Function to print the binary tree in inorder traversal
void inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to print the binary tree in postorder traversal
void postorder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Driver code
int main() {
    // Create a binary tree
    struct Node *root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Print the binary tree in preorder traversal
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    // Print the binary tree in inorder traversal
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Print the binary tree in postorder traversal
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    // Find the minimum value in the binary tree
    int min = findMin(root);
    printf("Minimum value: %d\n", min);

    // Find the maximum value in the binary tree
    int max = findMax(root);
    printf("Maximum value: %d\n", max);

    // Check if the binary tree is a binary search tree
    int isBst = isBST(root);
    printf("Is binary search tree: %d\n", isBst);

    return 0;
}