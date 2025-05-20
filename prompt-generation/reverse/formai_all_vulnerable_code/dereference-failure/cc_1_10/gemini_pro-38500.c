//GEMINI-pro DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _node {
    int data;
    struct _node *left;
    struct _node *right;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data <= root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

void inorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

void preorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

int main() {
    node *root = NULL;
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        root = insert_node(root, data);
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