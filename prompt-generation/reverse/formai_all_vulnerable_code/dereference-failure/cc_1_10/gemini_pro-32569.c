//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
// Welcome to NeoTokyo's Binary Search Trees.
// You, decker, are tasked with traversing our neon-soaked data structures.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Our neon-drenched node.
typedef struct cyberpunkNode {
    int data;
    struct cyberpunkNode *left, *right;
} cyberpunkNode;

// Insert data into our glitchy binary tree, decker.
cyberpunkNode* insert(cyberpunkNode* root, int data) {
    if (root == NULL) {
        cyberpunkNode* node = malloc(sizeof(cyberpunkNode));
        node->data = data;
        node->left = node->right = NULL;
        return node;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search for data in our cybernetic wonderland, decker.
bool search(cyberpunkNode* root, int data) {
    if (root == NULL) {
        return false;
    }
    if (data == root->data) {
        return true;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Print our glitch-infused tree in all its cybernetic glory.
void printTree(cyberpunkNode* root) {
    if (root) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

// Free our futuristic tree, decker.
void freeTree(cyberpunkNode* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Neon cyber-main.
int main() {
    // Build our binary tree, decker.
    cyberpunkNode* root = NULL;
    int data[] = {20, 10, 30, 5, 15, 25, 35};
    for (int i = 0; i < 7; i++) {
        root = insert(root, data[i]);
    }

    // Search for '25' in our cyberpunk-infused tree.
    if (search(root, 25)) {
        printf("25 found in our digital abyss.\n");
    } else {
        printf("25 not found in our neon wonderland.\n");
    }

    // Print the tree, decker.
    printf("Cyberpunk Binary Tree: ");
    printTree(root);
    printf("\n");

    // Leave no trace in the matrix, decker.
    freeTree(root);
    return 0;
}