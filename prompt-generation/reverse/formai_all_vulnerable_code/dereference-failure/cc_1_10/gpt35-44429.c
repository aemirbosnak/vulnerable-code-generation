//FormAI DATASET v1.0 Category: Data structures visualization ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

TreeNode* create_node(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_into_tree(TreeNode** root, int value) {
    if (*root == NULL) {
        *root = create_node(value);
    }
    else if (value < (*root)->value) {
        insert_into_tree(&((*root)->left), value);
    }
    else if (value > (*root)->value) {
        insert_into_tree(&((*root)->right), value);
    }
}

void print_tree(TreeNode* root, int level) {
    if (root != NULL) {
        print_tree(root->right, level + 1);
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("%d\n", root->value);
        print_tree(root->left, level + 1);
    }
}

int main() {
    TreeNode* root = NULL;

    insert_into_tree(&root, 5);
    insert_into_tree(&root, 1);
    insert_into_tree(&root, 6);
    insert_into_tree(&root, 3);
    insert_into_tree(&root, 9);
    insert_into_tree(&root, 2);
    insert_into_tree(&root, 4);

    printf("Binary Search Tree:\n");
    print_tree(root, 0);

    return 0;
}