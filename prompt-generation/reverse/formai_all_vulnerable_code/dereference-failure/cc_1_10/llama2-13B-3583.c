//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdlib.h>
#include <stdio.h>

#define MAX_NODES 1000
#define MAX_KEY 100

struct node {
    int key;
    struct node *left, *right;
};

struct binary_search_tree {
    struct node *root;
};

void init_tree(struct binary_search_tree *tree) {
    tree->root = NULL;
}

int insert_node(struct binary_search_tree *tree, int key) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        int current_key = tree->root->key;
        if (current_key > key) {
            tree->root->left = new_node;
        } else if (current_key < key) {
            tree->root->right = new_node;
        } else {
            // key already exists, do nothing
            free(new_node);
            return 1;
        }
    }

    return 0;
}

int search_node(struct binary_search_tree *tree, int key) {
    if (tree->root == NULL) {
        return -1;
    }

    int current_key = tree->root->key;
    if (current_key > key) {
        return search_node(tree, key);
    } else if (current_key < key) {
        return search_node(tree, key);
    } else {
        return 0;
    }
}

void traverse_tree(struct binary_search_tree *tree) {
    if (tree->root == NULL) {
        return;
    }

    traverse_tree(tree->root->left);
    printf("%d ", tree->root->key);
    traverse_tree(tree->root->right);
}

int main() {
    struct binary_search_tree tree;
    init_tree(&tree);

    insert_node(&tree, 5);
    insert_node(&tree, 2);
    insert_node(&tree, 8);
    insert_node(&tree, 3);
    insert_node(&tree, 6);
    insert_node(&tree, 1);

    traverse_tree(&tree);

    return 0;
}