//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new key into the tree
void insert(struct Node* node, int key) {
    if (node == NULL) {
        node = newNode(key);
    } else if (key < node->key) {
        insert(node->left, key);
    } else {
        insert(node->right, key);
    }
}

// Function to find a key in the tree
struct Node* find(struct Node* node, int key) {
    if (node == NULL || key < node->key) {
        return NULL;
    } else if (key == node->key) {
        return node;
    } else {
        return find(node->left, key);
    }
}

// Function to print the tree
void printTree(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printTree(node->left);
    printf("%d ", node->key);
    printTree(node->right);
}

int main() {
    // Create the root node
    struct Node* root = NULL;

    // Insert the following keys into the tree
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the tree
    printf("Tree: \n");
    printTree(root);

    return 0;
}