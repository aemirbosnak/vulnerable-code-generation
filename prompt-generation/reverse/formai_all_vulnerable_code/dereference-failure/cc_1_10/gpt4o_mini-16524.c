//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform in-order traversal
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to get the height of the tree
int height(Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// Function to print the binary tree in a structured format
void printTree(Node* root, int space) {
    if (root == NULL) return;

    space += 10; // Increase distance between levels

    printTree(root->right, space); // Process right child first

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data); // Print current node

    printTree(root->left, space); // Process left child
}

int main() {
    Node* root = NULL;
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    
    // Insert elements into the binary tree
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        root = insert(root, values[i]);
    }

    // Print in-order traversal
    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Print the binary tree structure
    printf("Binary Tree Structure:\n");
    printTree(root, 0);

    // Tree height
    printf("Height of the tree: %d\n", height(root));

    return 0;
}