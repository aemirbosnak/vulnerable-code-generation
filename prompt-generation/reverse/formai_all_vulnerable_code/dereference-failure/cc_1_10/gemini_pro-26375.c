//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int val;
    struct node *left, *right;
} node_t;

node_t *insert(node_t *root, int val) {
    if (root == NULL) {
        root = malloc(sizeof(node_t));
        root->val = val;
        root->left = root->right = NULL;
    } else if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

node_t *search(node_t *root, int val) {
    if (root == NULL) {
        return NULL;
    } else if (val < root->val) {
        return search(root->left, val);
    } else if (val > root->val) {
        return search(root->right, val);
    } else {
        return root;
    }
}

void print_tree(node_t *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->val);
    print_tree(root->right);
}

void free_tree(node_t *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    node_t *root = NULL;
    int arr[] = {10, 5, 15, 3, 7, 12, 17};
    int i;

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        root = insert(root, arr[i]);
    }

    print_tree(root);
    printf("\n");

    node_t *found = search(root, 7);
    if (found == NULL) {
        printf("7 not found in tree\n");
    } else {
        printf("7 found in tree\n");
    }

    free_tree(root);

    return 0;
}