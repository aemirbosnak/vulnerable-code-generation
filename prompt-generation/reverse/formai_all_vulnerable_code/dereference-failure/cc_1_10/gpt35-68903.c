//FormAI DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void printTree(struct TreeNode* root, int space) {
    int i;
    if (root == NULL)
        return;

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    
    printf("%d\n", root->val);

    printTree(root->left, space);
}

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insertNode(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insertNode(root->left, val);
    else if (val > root->val)
        root->right = insertNode(root->right, val);

    return root;
}

int main() {
    struct TreeNode* root = NULL;
    root = insertNode(root, 20);
    insertNode(root, 15);
    insertNode(root, 25);
    insertNode(root, 10);
    insertNode(root, 18);

    printTree(root, 0);

    return 0;
}