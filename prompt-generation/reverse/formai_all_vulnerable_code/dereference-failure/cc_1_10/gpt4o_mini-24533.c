//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
struct TreeNode* insert(struct TreeNode* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return node;
}

// Function to perform in-order traversal of the binary tree
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform pre-order traversal of the binary tree
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform post-order traversal of the binary tree
void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to visualize the binary tree (by levels)
void visualizeTree(struct TreeNode* root, int level) {
    if (root == NULL) return;

    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        visualizeTree(root->left, level - 1);
        visualizeTree(root->right, level - 1);
    }
}

// Function to find the height of the tree
int treeHeight(struct TreeNode* node) {
    if (node == NULL)
        return 0;

    int leftHeight = treeHeight(node->left);
    int rightHeight = treeHeight(node->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Driver code
int main() {
    struct TreeNode* root = NULL;
    int n, i, data;

    // Seed for random number generation
    srand(time(NULL));
    n = 10; // Number of nodes to create

    // Insert random values into the binary tree
    for (i = 0; i < n; i++) {
        data = rand() % 100; // Random number between 0 and 99
        root = insert(root, data);
        printf("Inserted %d into the binary tree.\n", data);
    }

    // Visualize the binary tree level by level
    printf("\nVisualizing the binary tree:\n");
    int height = treeHeight(root);
    for (i = 1; i <= height; i++) {
        printf("Level %d: ", i);
        visualizeTree(root, i);
        printf("\n");
    }

    // Display traversals
    printf("\nIn-order traversal: ");
    inorderTraversal(root);
    printf("\nPre-order traversal: ");
    preorderTraversal(root);
    printf("\nPost-order traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}