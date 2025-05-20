//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[20];
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to simulate message passing
void sendMessage(Node *node, char *message) {
    if (node == NULL) {
        return; // Base case: if the node is NULL, return
    }
    
    // Sending message to the current node
    printf("Sending message to %s: \"%s\"\n", node->name, message);
    
    // Recursively send to left and right children
    sendMessage(node->left, message);
    sendMessage(node->right, message);
}

// Function to free allocated memory for the tree
void freeTree(Node *node) {
    if (node == NULL) {
        return; // Base case
    }
    
    // Recursively free left and right subtrees
    freeTree(node->left);
    freeTree(node->right);
    free(node); // Free the current node
}

int main() {
    // Create nodes
    Node *root = createNode("Root");
    root->left = createNode("Left Child");
    root->right = createNode("Right Child");
    root->left->left = createNode("Left Left Child");
    root->left->right = createNode("Left Right Child");
    root->right->left = createNode("Right Left Child");
    root->right->right = createNode("Right Right Child");
    
    // Message to send
    char message[] = "Hello from the network!";
    
    // Start sending messages from the root node
    printf("Starting message passing from the root...\n");
    sendMessage(root, message);
    
    // Free allocated memory
    freeTree(root);
    
    return 0;
}