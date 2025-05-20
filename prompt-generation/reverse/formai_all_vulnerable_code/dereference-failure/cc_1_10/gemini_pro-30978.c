//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    int value;
    struct node *left;
    struct node *right;
} node_t;

node_t *insert(node_t *root, char *key, int value) {
    if (root == NULL) {
        root = malloc(sizeof(node_t));
        root->key = strdup(key);
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    } else if (strcmp(key, root->key) < 0) {
        root->left = insert(root->left, key, value);
    } else if (strcmp(key, root->key) > 0) {
        root->right = insert(root->right, key, value);
    } else {
        root->value = value;
    }

    return root;
}

node_t *search(node_t *root, char *key) {
    if (root == NULL) {
        return NULL;
    } else if (strcmp(key, root->key) < 0) {
        return search(root->left, key);
    } else if (strcmp(key, root->key) > 0) {
        return search(root->right, key);
    } else {
        return root;
    }
}

void destroy(node_t *root) {
    if (root == NULL) {
        return;
    }

    destroy(root->left);
    destroy(root->right);

    free(root->key);
    free(root);
}

int main() {
    node_t *root = NULL;

    root = insert(root, "apple", 1);
    root = insert(root, "banana", 2);
    root = insert(root, "cherry", 3);

    node_t *node = search(root, "banana");

    if (node != NULL) {
        printf("Found banana: %d\n", node->value);
    } else {
        printf("Banana not found\n");
    }

    destroy(root);

    return 0;
}