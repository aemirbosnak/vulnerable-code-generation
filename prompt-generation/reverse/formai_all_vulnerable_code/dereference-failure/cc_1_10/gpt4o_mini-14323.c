//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Definition of the structure for a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary tree
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

// Function to perform in-order traversal and visualize the tree
void inorderTraversal(Node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 10; // Increase distance between levels

    // Process right child first (higher values)
    inorderTraversal(root->right, space);

    // Print current node after space count
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Process left child
    inorderTraversal(root->left, space);
}

// Function to free memory used by the tree
void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;

    // Insert elements into the tree
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }

    // Visualizing the binary tree
    printf("In-order visualization of the binary tree:\n");
    inorderTraversal(root, 0);
    
    // Free the allocated memory
    freeTree(root);
    
    return 0;
}