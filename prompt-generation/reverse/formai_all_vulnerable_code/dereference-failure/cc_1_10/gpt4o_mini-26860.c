//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Structure representing a Node in a Binary Tree
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a Node in Binary Tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    
    return root;
}

// Function to perform in-order traversal of the tree and visualize it
void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    
    inOrderTraversal(root->left);
    
    // Print node data with spacings for visualization
    printf("%d ", root->data);
    
    inOrderTraversal(root->right);
}

// Function to visualize the tree structure on the console
void displayTree(Node* root, int space) {
    // Increase distance between levels
    space += 10;

    // Process right child first
    if (root->right != NULL) {
        displayTree(root->right, space);
    }

    // Print current node after spaces
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Process left child
    if (root->left != NULL) {
        displayTree(root->left, space);
    }
}

// Height of the tree
int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// Calculate diameter of the tree
int diameter(Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    // Get the height of left and right sub trees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Get the diameter of left and right sub trees
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    
    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

// Helper function to find maximum of two values
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Driver code
int main() {
    Node* root = NULL;

    // Insert elements into the binary tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("In-Order Traversal of the Tree:\n");
    inOrderTraversal(root);
    printf("\n\nVisual Structure of the Tree:\n");
    displayTree(root, 0);
    
    printf("\nDiameter of the Binary Tree: %d\n", diameter(root));

    // Free memory
    // A function to free memory can be implemented here to avoid memory leaks.

    return 0;
}