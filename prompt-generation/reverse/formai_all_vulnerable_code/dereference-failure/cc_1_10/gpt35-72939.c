//FormAI DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define a new data type for a binary tree node
typedef struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

// Function to create a new Binary Tree Node
BinaryTreeNode* createNode(int data) {
    BinaryTreeNode* newNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new Binary Tree Node
BinaryTreeNode* insertNode(BinaryTreeNode* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}

// Helper Function to print nodes of a binary tree in an Inorder traversal
void printInorder(BinaryTreeNode* node) {
    if (node != NULL) {
        printInorder(node->left);
        printf("%d ", node->data);
        printInorder(node->right);
    }
}

// Function for creating and visualizing a Binary Tree
void createAndVisualizeTree() {
    BinaryTreeNode* rootNode = NULL;

    // Insert nodes into the Binary Tree
    rootNode = insertNode(rootNode, 50);
    insertNode(rootNode, 30);
    insertNode(rootNode, 20);
    insertNode(rootNode, 40);
    insertNode(rootNode, 70);
    insertNode(rootNode, 60);
    insertNode(rootNode, 80);

    printf("Inorder Traversal of the Binary Tree:\n");
    printInorder(rootNode);
    printf("\n");

    printf("Visualization of the Binary Tree:\n\n");
    printf("               %d              \n", rootNode->data);
    printf("            /      \\          \n");
    printf("         %d            %d     \n", rootNode->left->data, rootNode->right->data);
    printf("       /   \\         /   \\   \n");
    printf("    %d     %d       %d     %d  \n", rootNode->left->left->data, rootNode->left->right->data, rootNode->right->left->data, rootNode->right->right->data);
}

int main() {
    createAndVisualizeTree();
    return 0;
}