//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;

node *insert(node *root, int value) {
    if (root == NULL) {
        node *new_node = malloc(sizeof(node));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    } else if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

node *find(node *root, int value) {
    if (root == NULL) {
        return NULL;
    } else if (value == root->value) {
        return root;
    } else if (value < root->value) {
        return find(root->left, value);
    } else {
        return find(root->right, value);
    }
}

int main() {
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    node *found = find(root, 15);
    if (found == NULL) {
        printf("Value not found\n");
    } else {
        printf("Value found: %d\n", found->value);
    }

    return 0;
}