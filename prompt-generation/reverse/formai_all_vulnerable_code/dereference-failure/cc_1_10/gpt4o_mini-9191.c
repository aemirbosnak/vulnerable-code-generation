//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a Node in Binary Search Tree (BST)
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

// Function to insert a node in BST
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

// Function to perform in-order traversal of the tree
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to perform pre-order traversal of the tree
void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal of the tree
void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
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

// Function to visualize the binary tree
void visualize(Node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 10;
    visualize(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    visualize(root->left, space);
}

int main() {
    Node* root = NULL;
    
    // Insert random values into the BST 
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int numValues = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < numValues; i++) {
        root = insert(root, values[i]);
    }

    printf("In-Order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    int searchValue = 60;
    Node* foundNode = search(root, searchValue);
    if (foundNode) {
        printf("Value %d found in BST.\n", foundNode->data);
    } else {
        printf("Value %d not found in BST.\n", searchValue);
    }

    printf("Visualizing the tree structure:\n");
    visualize(root, 0);

    // Free allocated memory (simple cleanup)
    free(root);

    return 0;
}