//FormAI DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Node structure declaration
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a value in the binary search tree
Node* insert(Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    return node;
}

// Traverse the binary search tree in order
void traverseInOrder(Node* node) {
    if (node == NULL) return;
    traverseInOrder(node->left);
    printf("%d ", node->data);
    traverseInOrder(node->right);
}

// Search for a value in the binary search tree
Node* search(Node* node, int data) {
    if (node == NULL || node->data == data) return node;
    if (data < node->data) return search(node->left, data);
    return search(node->right, data);
}

// Main function
int main() {
    // Create an example binary search tree
    Node* root = newNode(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    // Traverse and print the binary search tree in order
    printf("In-order traversal of the binary search tree:\n");
    traverseInOrder(root);
    printf("\n");
    
    // Search for a value in the binary search tree
    int value = 40;
    Node* found = search(root, value);
    if (found != NULL) printf("%d found in the binary search tree.\n", value);
    else printf("%d not found in the binary search tree.\n", value);
    
    return 0;
}