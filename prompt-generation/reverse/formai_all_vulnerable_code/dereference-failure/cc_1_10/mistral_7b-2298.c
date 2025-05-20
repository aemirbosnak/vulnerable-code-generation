//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_DEPTH 10

typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void print_tree(TreeNode *node, int depth) {
    char spacer[MAX_DEPTH];

    if (node == NULL) {
        printf("%s|\n", spacer);
        return;
    }

    if (depth > 0) {
        int len = strlen(spacer);
        memset(spacer + len, ' ', MAX_DEPTH - len);
        spacer[MAX_DEPTH - 1] = '\0';
        printf("%s%d|\n", spacer, node->value);
    }

    print_tree(node->left, depth + 1);
    print_tree(node->right, depth + 1);
}

TreeNode *create_node(int value) {
    TreeNode *new_node = malloc(sizeof(TreeNode));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

TreeNode *insert(TreeNode *root, int value) {
    if (root == NULL) {
        root = create_node(value);
        return root;
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

int main() {
    int numbers[] = {10, 5, 15, 3, 7, 12, 17, 8, 11, 14, 16, 13};
    int len = sizeof(numbers) / sizeof(numbers[0]);
    int i;
    TreeNode *root = NULL;

    for (i = 0; i < len; i++) {
        root = insert(root, numbers[i]);
    }

    print_tree(root, 0);

    return 0;
}