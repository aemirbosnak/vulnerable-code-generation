//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void printTree(TreeNode *root, int level) {
    TreeNode *current;
    int i;

    if (root == NULL) {
        return;
    }

    printTree(root->right, level + 1);

    for (i = 0; i < level * 2; i++) {
        printf(" ");
    }

    printf("%d\n", root->value);

    printTree(root->left, level + 1);
}

void createTree(TreeNode **root, int *values, int size) {
    int i;

    *root = malloc(sizeof(TreeNode));
    (*root)->value = values[0];
    (*root)->left = NULL;
    (*root)->right = NULL;

    if (size > 1) {
        TreeNode *left = malloc(sizeof(TreeNode));
        TreeNode *right = malloc(sizeof(TreeNode));

        createTree(&(*root)->left, values + 1, size - 1);
        createTree(&(*root)->right, values + (size / 2) + 1, size - (size / 2) - 1);
    }
}

int main() {
    int values[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(values) / sizeof(values[0]);
    TreeNode *root = NULL;

    createTree(&root, values, size);
    printTree(root, 0);

    return 0;
}