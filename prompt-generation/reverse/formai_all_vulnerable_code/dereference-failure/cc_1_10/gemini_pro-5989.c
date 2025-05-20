//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    int val;
    struct node *left, *right;
} node;

node *new_node(int val, node *left, node *right) {
    node *n = malloc(sizeof(node));
    assert(n != NULL);
    n->val = val;
    n->left = left;
    n->right = right;
    return n;
}

node *insert(node *root, int val) {
    if (root == NULL) {
        return new_node(val, NULL, NULL);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void print_inorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    printf("%d ", root->val);
    print_inorder(root->right);
}

void print_preorder(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_postorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->val);
}

int height(node *root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

int size(node *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}

int is_bst(node *root) {
    if (root == NULL) {
        return 1;
    }
    if (root->left != NULL && root->left->val > root->val) {
        return 0;
    }
    if (root->right != NULL && root->right->val < root->val) {
        return 0;
    }
    return is_bst(root->left) && is_bst(root->right);
}

int main() {
    node *root = insert(NULL, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("inorder traversal: ");
    print_inorder(root);
    printf("\n");

    printf("preorder traversal: ");
    print_preorder(root);
    printf("\n");

    printf("postorder traversal: ");
    print_postorder(root);
    printf("\n");

    printf("height: %d\n", height(root));
    printf("size: %d\n", size(root));
    printf("is bst: %d\n", is_bst(root));

    return 0;
}