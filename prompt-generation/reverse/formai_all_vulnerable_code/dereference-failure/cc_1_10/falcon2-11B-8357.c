//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: lively
#include <stdio.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

void inorder_traversal(BSTNode *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

void print_bst(BSTNode *root) {
    if (root == NULL) {
        return;
    }
    print_bst(root->left);
    printf("%d ", root->data);
    print_bst(root->right);
}

int main() {
    BSTNode *root = NULL;

    root = (BSTNode *)malloc(sizeof(BSTNode));
    root->data = 5;
    root->left = NULL;
    root->right = NULL;

    root = (BSTNode *)malloc(sizeof(BSTNode));
    root->data = 3;
    root->left = NULL;
    root->right = NULL;

    root = (BSTNode *)malloc(sizeof(BSTNode));
    root->data = 7;
    root->left = NULL;
    root->right = NULL;

    root = (BSTNode *)malloc(sizeof(BSTNode));
    root->data = 2;
    root->left = NULL;
    root->right = NULL;

    root = (BSTNode *)malloc(sizeof(BSTNode));
    root->data = 4;
    root->left = NULL;
    root->right = NULL;

    root = (BSTNode *)malloc(sizeof(BSTNode));
    root->data = 6;
    root->left = NULL;
    root->right = NULL;

    root = (BSTNode *)malloc(sizeof(BSTNode));
    root->data = 8;
    root->left = NULL;
    root->right = NULL;

    root->left = (BSTNode *)malloc(sizeof(BSTNode));
    root->left->data = 1;
    root->left->left = NULL;
    root->left->right = NULL;

    root->right = (BSTNode *)malloc(sizeof(BSTNode));
    root->right->data = 9;
    root->right->left = NULL;
    root->right->right = NULL;

    inorder_traversal(root);
    printf("\n");
    print_bst(root);

    return 0;
}