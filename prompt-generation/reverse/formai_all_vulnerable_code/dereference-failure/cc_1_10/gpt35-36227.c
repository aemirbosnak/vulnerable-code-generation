//FormAI DATASET v1.0 Category: Data structures visualization ; Style: brave
#include <stdio.h>
#include <stdlib.h>

/* Struct to represent a node in a binary search tree */
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

/* Function to create a new node with the given value */
Node *createNode(int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Function to insert a value into the binary search tree */
Node *insert(Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    } else if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

/* Function to print the binary search tree recursively */
void printTree(Node *root, int spaces) {
    if (root != NULL) {
        printTree(root->right, spaces + 4);
        for (int i = 0; i < spaces; i++) {
            printf(" ");
        }
        printf("%d\n", root->value);
        printTree(root->left, spaces + 4);
    }
}

int main() {
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 6);
    root = insert(root, 20);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 15);
    root = insert(root, 25);
    printf("Binary Search Tree Visualization:\n");
    printTree(root, 0);
    return 0;
}