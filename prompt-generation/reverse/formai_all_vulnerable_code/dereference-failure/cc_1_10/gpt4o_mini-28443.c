//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Node structure for the Binary Search Tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new value in the Binary Search Tree
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

// Function to search for a value in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to perform In-Order Traversal (Left, Root, Right)
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to perform Pre-Order Traversal (Root, Left, Right)
void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform Post-Order Traversal (Left, Right, Root)
void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function to run the Binary Search Tree operations
int main() {
    Node* root = NULL;

    // Exciting data to insert into the Binary Search Tree!
    int dataArr[] = {15, 10, 20, 8, 12, 17, 25};
    printf("Inserting values into the Binary Search Tree...\n");
    for (int i = 0; i < sizeof(dataArr) / sizeof(dataArr[0]); i++) {
        root = insert(root, dataArr[i]);
        printf("Inserted: %d\n", dataArr[i]);
    }

    printf("\nIn-Order Traversal: ");
    inOrderTraversal(root); // Should print: 8 10 12 15 17 20 25
    printf("\n\nPre-Order Traversal: ");
    preOrderTraversal(root); // Should print: 15 10 8 12 20 17 25
    printf("\n\nPost-Order Traversal: ");
    postOrderTraversal(root); // Should print: 8 12 10 17 25 20 15

    // Searching for some values
    int searchValues[] = {10, 13, 25, 30};
    printf("\n\nSearching for values:\n");
    for (int j = 0; j < sizeof(searchValues) / sizeof(searchValues[0]); j++) {
        Node* result = search(root, searchValues[j]);
        if (result != NULL) {
            printf("Found: %d\n", searchValues[j]);
        } else {
            printf("Not found: %d\n", searchValues[j]);
        }
    }

    // Cleanup (Free allocated memory)
    // Note: Memory cleanup function can be implemented but for the sake of simplicity, we won't implement it here.

    return 0;
}