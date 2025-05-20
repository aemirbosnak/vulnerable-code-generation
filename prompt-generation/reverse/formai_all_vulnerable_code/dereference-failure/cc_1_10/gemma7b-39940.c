//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct BST {
    struct Node* root;
};

void insert(struct BST* tree, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (tree->root == NULL) {
        tree->root = newNode;
    } else {
        struct Node* current = tree->root;
        struct Node* parent = NULL;
        while (current) {
            if (data < current->data) {
                parent = current;
                current = current->left;
            } else {
                parent = current;
                current = current->right;
            }
        }

        if (parent) {
            if (parent->left) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }
    }
}

int search(struct BST* tree, int data) {
    struct Node* current = tree->root;

    while (current) {
        if (data == current->data) {
            return 1;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return 0;
}

int main() {
    struct BST* tree = malloc(sizeof(struct BST));
    tree->root = NULL;

    insert(tree, 20);
    insert(tree, 10);
    insert(tree, 30);
    insert(tree, 25);
    insert(tree, 5);

    if (search(tree, 25)) {
        printf("25 is found!");
    }

    return 0;
}