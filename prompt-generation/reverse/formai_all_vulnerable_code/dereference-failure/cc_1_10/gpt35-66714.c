//FormAI DATASET v1.0 Category: Binary search trees ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

TreeNode* search(TreeNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void inorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    TreeNode* root = NULL;
    root = insert(root, 7);
    insert(root, 3);
    insert(root, 9);
    insert(root, 2);
    insert(root, 5);
    insert(root, 8);
    insert(root, 10);
    printf("Inorder traversal of the BST:\n");
    inorder(root);
    printf("\n");
    printf("Preorder traversal of the BST:\n");
    preorder(root);
    printf("\n");
    printf("Postorder traversal of the BST:\n");
    postorder(root);
    printf("\n");
    TreeNode* result = search(root, 5);
    if (result != NULL) {
        printf("Element found: %d\n", result->data);
    } else {
        printf("Element not found.\n");
    }
    return 0;
}