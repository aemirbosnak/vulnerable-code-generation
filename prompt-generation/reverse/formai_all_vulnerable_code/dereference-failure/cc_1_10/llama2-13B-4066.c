//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_SIZE 1024
#define TREE_NAME "RandomBST"

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
    struct node *parent;
} node_t;

node_t *root;

void init_tree(void) {
    root = NULL;
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int key = rand() % 100;
        node_t *node = (node_t *)malloc(sizeof(node_t));
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
        if (i == 0) {
            root = node;
        } else {
            if (key < root->key) {
                if (root->left == NULL) {
                    root->left = node;
                } else {
                    root->left->left = node;
                }
            } else {
                if (root->right == NULL) {
                    root->right = node;
                } else {
                    root->right->right = node;
                }
            }
        }
    }
}

void print_tree(node_t *node) {
    if (node == NULL) {
        printf("(null)\n");
        return;
    }
    printf("%d ", node->key);
    print_tree(node->left);
    print_tree(node->right);
    printf("\n");
}

int search_tree(node_t *node, int key) {
    if (node == NULL) {
        return -1;
    }
    if (key < node->key) {
        return search_tree(node->left, key);
    } else if (key > node->key) {
        return search_tree(node->right, key);
    } else {
        return 0;
    }
}

int main(void) {
    init_tree();
    print_tree(root);
    int key = 42;
    int found = search_tree(root, key);
    if (found == 0) {
        printf("Key %d not found in the tree\n", key);
    } else {
        printf("Key %d found in the tree\n", key);
    }
    return 0;
}