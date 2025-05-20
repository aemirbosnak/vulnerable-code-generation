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
    } else {
        return search_node(root->right, data);
    }
}

void inorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

int main() {
    node *root = NULL;
    int data;
    while (scanf("%d", &data) == 1) {
        root = insert_node(root, data);
    }
    while (scanf("%d", &data) == 1) {
        node *found = search_node(root, data);
        if (found != NULL) {
            printf("Found %d\n", data);
        } else {
            printf("Not found %d\n", data);
        }
    }
    inorder_traversal(root);
    printf("\n");
    return 0;
}