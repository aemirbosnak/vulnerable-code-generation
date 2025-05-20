//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Tree {
    struct Node* root;
};

void insert(struct Tree* tree, int data) {
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

void inorder(struct Node* node) {
    if (node) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main() {
    struct Tree* tree = malloc(sizeof(struct Tree));
    tree->root = NULL;

    insert(tree, 5);
    insert(tree, 2);
    insert(tree, 8);
    insert(tree, 3);
    insert(tree, 10);
    insert(tree, 20);

    inorder(tree->root);
    printf("\n");

    return 0;
}