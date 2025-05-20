//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>

/* Define a custom struct for our search tree nodes */
typedef struct element_s element_t;
struct element_s {
    int key;
    element_t *left;
    element_t *right;
};

/**
 * Insert a new key into the search tree rooted at `node`.
 * Returns a pointer to the new root node.
 */
element_t* insert(element_t *node, int key) {
    /* If we've hit an empty spot, create the new node here */
    if (node == NULL) {
        node = malloc(sizeof(element_t));
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    /* Otherwise, recurse either left or right depending on the key */
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    /* Return the root node (which may have changed) */
    return node;
}

/**
 * Search the search tree rooted at `node` for the given `key`.
 * Returns 1 if `key` is found, otherwise 0.
 */
int search(element_t *node, int key) {
    /* If we hit a dead end, the key isn't in the tree */
    if (node == NULL) {
        return 0;
    }

    /* If we found the key, return success */
    if (node->key == key) {
        return 1;
    }

    /* Otherwise, recurse either left or right depending on the key */
    if (key < node->key) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

/* Main function */
int main() {
    /* Build a search tree */
    element_t *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 9);

    /* Search for some keys */
    printf("Does the tree contain 3? %d\n", search(root, 3));
    printf("Does the tree contain 2? %d\n", search(root, 2));
    printf("Does the tree contain 9? %d\n", search(root, 9));
    printf("Does the tree contain 5? %d\n", search(root, 5));
    printf("Does the tree contain 0? %d\n", search(root, 0));

    return 0;
}