//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

void printTree(TreeNode* node, int level) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    if (node->left != NULL) {
        printf("/--");
        printTree(node->left, level + 1);
    }

    printf("%d\n", node->data);

    if (node->right != NULL) {
        printf("\\--");
        printTree(node->right, level + 1);
    }
}

int main() {
    TreeNode* root = malloc(sizeof(TreeNode));
    root->data = 1;
    root->left = NULL;
    root->right = malloc(sizeof(TreeNode));

    root->right->data = 2;
    root->right->left = NULL;
    root->right->right = malloc(sizeof(TreeNode));

    root->right->right->data = 3;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    printTree(root, 0);

    free(root);
    free(root->right);
    free(root->right->right);

    return 0;
}