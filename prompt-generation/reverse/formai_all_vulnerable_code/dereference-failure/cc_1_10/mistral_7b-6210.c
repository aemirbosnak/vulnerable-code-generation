//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void print_tree(TreeNode *node, int level) {
    static int width = 0;
    static int max_width = 0;

    if (node == NULL) {
        putchar('\n');
        return;
    }

    width = (width + 1) > max_width ? (width + 1) : max_width;

    print_tree(node->right, level + 1);

    for (int i = max_width - level; i > 0; --i)
        putchar(' ');

    printf("%*d: %d\n", width, level, node->key);

    print_tree(node->left, level + 1);
}

TreeNode *new_tree_node(int key) {
    TreeNode *node = malloc(sizeof(TreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode *insert(TreeNode *node, int key) {
    if (node == NULL) {
        node = new_tree_node(key);
    } else if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }
    return node;
}

int main() {
    TreeNode *root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 17);

    print_tree(root, 0);

    free(root);

    return 0;
}