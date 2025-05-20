//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node_t **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else {
        if (data <= (*root)->data) {
            insert_node(&(*root)->left, data);
        } else {
            insert_node(&(*root)->right, data);
        }
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
    int data[] = {10, 5, 15, 3, 7, 12, 17, 1, 4, 6, 8, 9, 11, 13, 14, 16, 18};
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        insert_node(&root, data[i]);
    }
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");
    return 0;
}