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
    int size;
};

void insert(struct BST* tree, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (tree->root == NULL) {
        tree->root = newNode;
    } else {
        insert(tree, data);
    }

    tree->size++;
}

int search(struct BST* tree, int data) {
    struct Node* current = tree->root;

    while (current) {
        if (current->data == data) {
            return 1;
        } else if (current->data < data) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return 0;
}

int main() {
    struct BST* tree = (struct BST*)malloc(sizeof(struct BST));
    tree->root = NULL;
    tree->size = 0;

    insert(tree, 10);
    insert(tree, 20);
    insert(tree, 30);
    insert(tree, 40);
    insert(tree, 50);

    if (search(tree, 30) == 1) {
        printf("30 found\n");
    } else {
        printf("30 not found\n");
    }

    return 0;
}