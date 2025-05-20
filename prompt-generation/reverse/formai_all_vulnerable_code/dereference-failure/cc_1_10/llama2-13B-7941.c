//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_SIZE 1024
#define BST_ORDER 2

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} node_t;

node_t *bst_create(void);
node_t *bst_insert(node_t *root, int key);
node_t *bst_search(node_t *root, int key);
void bst_print(node_t *root);

node_t *bst_create(void) {
    node_t *root = malloc(sizeof(node_t));
    root->key = 0;
    root->left = NULL;
    root->right = NULL;
    return root;
}

node_t *bst_insert(node_t *root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = bst_insert(root->left, key);
    } else if (key > root->key) {
        root->right = bst_insert(root->right, key);
    }

    return root;
}

node_t *bst_search(node_t *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->key) {
        return bst_search(root->left, key);
    } else if (key > root->key) {
        return bst_search(root->right, key);
    }

    return root;
}

void bst_print(node_t *root) {
    if (root == NULL) {
        printf("empty tree\n");
        return;
    }

    printf("%d ", root->key);
    bst_print(root->left);
    bst_print(root->right);
    printf("\n");
}

int main(void) {
    node_t *root = bst_create();
    bst_insert(root, 5);
    bst_insert(root, 10);
    bst_insert(root, 20);
    bst_insert(root, 30);

    bst_print(root);

    return 0;
}