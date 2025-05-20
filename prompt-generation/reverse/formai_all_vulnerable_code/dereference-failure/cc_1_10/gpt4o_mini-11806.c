//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NODES 20

// Structure to represent a single node in a binary tree
typedef struct Node {
    char name[MAX_NAME_LEN];
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(const char *name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform an in-order traversal and print the tree
void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s ", root->name);
        inorderTraversal(root->right);
    }
}

// Function to insert a new node into the binary tree
Node* insertNode(Node* root, const char *name) {
    if (root == NULL) {
        return createNode(name);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insertNode(root->left, name);
    } else {
        root->right = insertNode(root->right, name);
    }
    return root;
}

// Function to search for a specific name in the tree
Node* searchNode(Node* root, const char *name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        return searchNode(root->left, name);
    }
    return searchNode(root->right, name);
}

// Function to visualize the tree structure
void printTree(Node *root, int depth) {
    if (root != NULL) {
        printTree(root->right, depth + 1); // right
        for (int i = 0; i < depth; i++) {
            printf("    ");
        }
        printf("%s\n", root->name);
        printTree(root->left, depth + 1); // left
    }
}

// Function to free the memory of the tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    char names[MAX_NODES][MAX_NAME_LEN] = {
        "Alice", "Bob", "Charlie", "Diana", "Ethan",
        "Fiona", "George", "Hannah", "Ian", "Jack"
    };

    // Insert names into the binary tree
    for (int i = 0; i < MAX_NODES; i++) {
        root = insertNode(root, names[i]);
    }

    printf("In-order Traversal of the Binary Tree:\n");
    inorderTraversal(root);
    printf("\n\n");

    printf("Tree Structure Visualization:\n");
    printTree(root, 0);

    // Search for a specific name
    const char *searchName = "Ethan";
    Node* foundNode = searchNode(root, searchName);
    if (foundNode) {
        printf("\nFound: %s\n", foundNode->name);
    } else {
        printf("\n%s not found in the tree.\n", searchName);
    }

    // Free the allocated memory
    freeTree(root);
    return 0;
}