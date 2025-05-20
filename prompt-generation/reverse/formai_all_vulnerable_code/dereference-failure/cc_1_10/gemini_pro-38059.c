//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node_t **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

void inorder_traversal(node_t *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void preorder_traversal(node_t *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(node_t *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    node_t *root = NULL;
    int data[] = {50, 30, 80, 20, 40, 70, 90, 10, 25, 35, 60, 75, 85, 95};
    for (int i = 0; i < 14; i++) {
        insert_node(&root, data[i]);
    }
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\nPreorder traversal: ");
    preorder_traversal(root);
    printf("\nPostorder traversal: ");
    postorder_traversal(root);
    printf("\n");
    return 0;
}