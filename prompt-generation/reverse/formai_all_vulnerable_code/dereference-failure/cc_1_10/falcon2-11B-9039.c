//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree node
struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

// Binary Search Tree
struct Node *root;

// Insert a value into the BST
void insert(int value) {
    struct Node *current = root;
    struct Node *parent;

    // Find the correct position to insert the new value
    while (current!= NULL) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Create a new node and insert it into the tree
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if (parent == NULL) {
        root = new_node;
    } else if (value < parent->value) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}

// Find the maximum value in the BST
int find_max() {
    struct Node *current = root;

    while (current!= NULL) {
        if (current->right!= NULL) {
            current = current->right;
        } else {
            return current->value;
        }
    }

    return -1; // Shouldn't reach here
}

int main() {
    insert(5);
    insert(10);
    insert(15);
    insert(7);
    insert(12);
    insert(20);

    printf("Maximum value in the tree is %d\n", find_max());

    return 0;
}