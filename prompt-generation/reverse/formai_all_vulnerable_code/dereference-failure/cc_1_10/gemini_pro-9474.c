//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    char *value;
    struct node *left;
    struct node *right;
} node;

typedef struct tree {
    struct node *root;
} tree;

tree *create_tree() {
    tree *t = (tree *)malloc(sizeof(tree));
    t->root = NULL;
    return t;
}

node *create_node(int key, char *value) {
    node *n = (node *)malloc(sizeof(node));
    n->key = key;
    n->value = strdup(value);
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insert(tree *t, int key, char *value) {
    node *n = create_node(key, value);
    if (t->root == NULL) {
        t->root = n;
    } else {
        node *current = t->root;
        while (1) {
            if (key < current->key) {
                if (current->left == NULL) {
                    current->left = n;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = n;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

node *search(tree *t, int key) {
    node *current = t->root;
    while (current != NULL) {
        if (key == current->key) {
            return current;
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

int main() {
    tree *t = create_tree();
    insert(t, 1, "first");
    insert(t, 2, "second");
    insert(t, 3, "third");
    node *n = search(t, 2);
    if (n != NULL) {
        printf("Found node with key %d and value %s\n", n->key, n->value);
    } else {
        printf("Node not found\n");
    }
    return 0;
}