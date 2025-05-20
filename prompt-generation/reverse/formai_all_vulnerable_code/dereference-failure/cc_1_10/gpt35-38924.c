//FormAI DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree BinarySearchTree;

// Definition of a binary search tree node
struct BinarySearchTree {
    int value;
    BinarySearchTree *left;
    BinarySearchTree *right;
};

// Function to insert a new node into the binary search tree
void insert(BinarySearchTree **root, int value) {
    if (*root == NULL) { // If the tree is empty, create a new node
        *root = (BinarySearchTree *) malloc(sizeof(BinarySearchTree));
        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if (value < (*root)->value) { // If the value is smaller, insert it into the left subtree
        insert(&((*root)->left), value);
    } else if (value > (*root)->value) { // If the value is larger, insert it into the right subtree
        insert(&((*root)->right), value);
    } // If the value already exists, do nothing
}

// Function to print the binary search tree in ASCII art
void print(BinarySearchTree *root, int depth) {
    if (root != NULL) { // Only print non-empty trees
        // Recursively print the right subtree before the root and the left subtree after the root
        print(root->right, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("   ");
        }
        printf("%d\n", root->value);
        print(root->left, depth + 1);
    }
}

int main() {
    BinarySearchTree *root = NULL;

    // Insert some values into the binary search tree
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 7);
    insert(&root, 20);
    insert(&root, 15);
    insert(&root, 12);

    // Print the binary search tree in ASCII art
    print(root, 0);

    return 0;
}