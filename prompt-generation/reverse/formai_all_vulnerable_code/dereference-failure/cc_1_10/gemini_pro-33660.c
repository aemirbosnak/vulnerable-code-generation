//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: scalable
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

node_t *insert(node_t *root, int data) {
    if (root == NULL) {
        root = malloc(sizeof(node_t));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

node_t *search(node_t *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    }
    return NULL;
}

void print_inorder(node_t *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

void print_preorder(node_t *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_postorder(node_t *root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    node_t *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    printf("Inorder: ");
    print_inorder(root);
    printf("\n");

    printf("Preorder: ");
    print_preorder(root);
    printf("\n");

    printf("Postorder: ");
    print_postorder(root);
    printf("\n");

    node_t *found = search(root, 12);
    if (found != NULL) {
        printf("Found node with data %d\n", found->data);
    } else {
        printf("Could not find node with data 12\n");
    }

    return 0;
}