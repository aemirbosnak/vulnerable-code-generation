//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node *left;
    struct _node *right;
} node;

typedef struct _tree {
    node *root;
} tree;

tree *create_tree() {
    tree *t = malloc(sizeof(tree));
    t->root = NULL;
    return t;
}

void insert(tree *t, int value) {
    node *n = malloc(sizeof(node));
    n->value = value;
    n->left = NULL;
    n->right = NULL;

    if (t->root == NULL) {
        t->root = n;
        return;
    }

    node *current = t->root;
    while (1) {
        if (value < current->value) {
            if (current->left == NULL) {
                current->left = n;
                return;
            } else {
                current = current->left;
            }
        } else {
            if (current->right == NULL) {
                current->right = n;
                return;
            } else {
                current = current->right;
            }
        }
    }
}

void inorder(node *n) {
    if (n == NULL) {
        return;
    }

    inorder(n->left);
    printf("%d ", n->value);
    inorder(n->right);
}

int main() {
    tree *t = create_tree();

    insert(t, 10);
    insert(t, 5);
    insert(t, 15);
    insert(t, 2);
    insert(t, 7);
    insert(t, 12);
    insert(t, 20);

    inorder(t->root);

    printf("\n");

    return 0;
}