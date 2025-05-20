//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node {
    int data;
    struct bst_node *left;
    struct bst_node *right;
} bst_node;

bst_node *bst_insert(bst_node *root, int data) {
    if (root == NULL) {
        root = malloc(sizeof(bst_node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    } else if (data < root->data) {
        root->left = bst_insert(root->left, data);
    } else if (data > root->data) {
        root->right = bst_insert(root->right, data);
    }

    return root;
}

bst_node *bst_search(bst_node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        return bst_search(root->left, data);
    } else if (data > root->data) {
        return bst_search(root->right, data);
    }

    return root;
}

void bst_preorder(bst_node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    bst_preorder(root->left);
    bst_preorder(root->right);
}

void bst_inorder(bst_node *root) {
    if (root == NULL) {
        return;
    }

    bst_inorder(root->left);
    printf("%d ", root->data);
    bst_inorder(root->right);
}

void bst_postorder(bst_node *root) {
    if (root == NULL) {
        return;
    }

    bst_postorder(root->left);
    bst_postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    bst_node *root = NULL;

    root = bst_insert(root, 10);
    root = bst_insert(root, 5);
    root = bst_insert(root, 15);
    root = bst_insert(root, 3);
    root = bst_insert(root, 7);
    root = bst_insert(root, 12);
    root = bst_insert(root, 20);

    bst_node *found = bst_search(root, 7);
    if (found != NULL) {
        printf("Found %d in the BST\n", found->data);
    } else {
        printf("Could not find 7 in the BST\n");
    }

    printf("Preorder traversal: ");
    bst_preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    bst_inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    bst_postorder(root);
    printf("\n");

    return 0;
}