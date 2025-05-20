//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

node_t* insert(node_t *root, int data) {
    if (root == NULL) {
        root = malloc(sizeof(node_t));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int search(node_t *root, int data) {
    if (root == NULL) {
        return 0;
    } else if (data == root->data) {
        return 1;
    } else if (data <= root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void inorder(node_t *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node_t *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node_t *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    node_t *root = NULL;
    int data[] = {10, 5, 15, 2, 7, 12, 20};
    int i;
    for (i = 0; i < 7; i++) {
        root = insert(root, data[i]);
    }
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    int search_data = 15;
    if (search(root, search_data)) {
        printf("%d found in the tree.\n", search_data);
    } else {
        printf("%d not found in the tree.\n", search_data);
    }
    return 0;
}