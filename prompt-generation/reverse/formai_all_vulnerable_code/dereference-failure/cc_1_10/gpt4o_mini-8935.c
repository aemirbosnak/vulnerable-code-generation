//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new value into the BST
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

// Function to visualize the BST
void visualize(Node* root, int space) {
    if (root == NULL) {
        return;
    }
    
    // Increase distance between levels
    space += 10;

    // Process right child first
    visualize(root->right, space);

    // Print current node after space count
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Process left child
    visualize(root->left, space);
}

// Utility function to clear the BST and free memory
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to drive the program
int main() {
    int numberOfValues, value;
    Node* root = NULL;

    printf("Welcome to the Binary Search Tree Visualization!\n");
    printf("How many values would you like to insert into the BST? ");
    scanf("%d", &numberOfValues);

    for (int i = 0; i < numberOfValues; i++) {
        printf("Please enter value #%d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
        printf("\nCurrent Binary Search Tree:\n");
        visualize(root, 0);
        printf("\n\n");
    }

    printf("Thank you for using the BST Visualizer! Goodbye!\n");
    freeTree(root);  // Free allocated memory
    return 0;
}