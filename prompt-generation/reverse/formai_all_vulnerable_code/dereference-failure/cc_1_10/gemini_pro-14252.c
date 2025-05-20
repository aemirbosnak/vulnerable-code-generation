//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node* create_node(int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert_node(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

node* search_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else if (data > root->data) {
        return search_node(root->right, data);
    }
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    node *root = NULL;
    int data[] = {10, 5, 15, 2, 7, 12, 20};
    int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; i++) {
        root = insert_node(root, data[i]);
    }
    print_tree(root);
    printf("\n");
    node *result = search_node(root, 12);
    if (result == NULL) {
        printf("Node not found\n");
    } else {
        printf("Node found: %d\n", result->data);
    }
    return 0;
}