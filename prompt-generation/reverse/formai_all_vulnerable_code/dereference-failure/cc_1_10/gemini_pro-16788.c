//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    void *value;
    struct node *left;
    struct node *right;
} node;

typedef struct btree {
    node *root;
} btree;

btree *btree_create() {
    btree *tree = malloc(sizeof(btree));
    tree->root = NULL;
    return tree;
}

void btree_insert(btree *tree, char *key, void *value) {
    node *new_node = malloc(sizeof(node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
        return;
    }

    node *curr = tree->root;
    while (curr != NULL) {
        int cmp = strcmp(key, curr->key);
        if (cmp == 0) {
            curr->value = value;
            return;
        } else if (cmp < 0) {
            if (curr->left == NULL) {
                curr->left = new_node;
                return;
            } else {
                curr = curr->left;
            }
        } else {
            if (curr->right == NULL) {
                curr->right = new_node;
                return;
            } else {
                curr = curr->right;
            }
        }
    }
}

void *btree_get(btree *tree, char *key) {
    node *curr = tree->root;
    while (curr != NULL) {
        int cmp = strcmp(key, curr->key);
        if (cmp == 0) {
            return curr->value;
        } else if (cmp < 0) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return NULL;
}

void btree_free(btree *tree) {
    if (tree->root != NULL) {
        free(tree->root->key);
        free(tree->root);
    }
    free(tree);
}

int main() {
    btree *tree = btree_create();

    btree_insert(tree, "John", "Doe");
    btree_insert(tree, "Jane", "Doe");
    btree_insert(tree, "Bill", "Smith");
    btree_insert(tree, "Alice", "Jones");

    printf("%s\n", (char *)btree_get(tree, "John"));
    printf("%s\n", (char *)btree_get(tree, "Jane"));
    printf("%s\n", (char *)btree_get(tree, "Bill"));
    printf("%s\n", (char *)btree_get(tree, "Alice"));

    btree_free(tree);

    return 0;
}