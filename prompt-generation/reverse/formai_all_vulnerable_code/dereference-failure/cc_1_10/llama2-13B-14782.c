//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEPTH 50
#define MAX_LENGTH 100

struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct Tree* createTree(int data) {
    struct Tree* t = malloc(sizeof(struct Tree));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}

struct Tree* addToTree(struct Tree* root, int data) {
    if (root == NULL) {
        return createTree(data);
    }

    if (data < root->data) {
        root->left = addToTree(root->left, data);
    } else {
        root->right = addToTree(root->right, data);
    }

    return root;
}

struct Tree* traverse(struct Tree* root) {
    if (root == NULL) {
        return NULL;
    }

    printf("Entering node with value %d\n", root->data);

    traverse(root->left);
    traverse(root->right);

    return root;
}

int main() {
    struct Tree* root = NULL;

    root = addToTree(root, 5);
    root = addToTree(root, 2);
    root = addToTree(root, 8);
    root = addToTree(root, 3);
    root = addToTree(root, 6);
    root = addToTree(root, 1);

    traverse(root);

    return 0;
}