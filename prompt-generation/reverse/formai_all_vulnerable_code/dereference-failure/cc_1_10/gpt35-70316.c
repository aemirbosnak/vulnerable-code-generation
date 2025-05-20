//FormAI DATASET v1.0 Category: Binary search trees ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        TreeNode* new_node = (TreeNode*) malloc(sizeof(TreeNode));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int search(TreeNode* root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return 1;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    TreeNode* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 9);
    printf("Inorder traversal: ");
    inorder(root);
    int to_find = 7;
    if (search(root, to_find)) {
        printf("\n%d is present in the tree.\n", to_find);
    } else {
        printf("\n%d is not present in the tree.\n", to_find);
    }
    return 0;
}