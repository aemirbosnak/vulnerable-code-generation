//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else if (data > (*root)->data) {
        insert_node(&(*root)->right, data);
    }
}

node *search_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else if (data > root->data) {
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

void free_tree(node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    node *root = NULL;
    int data[] = {10, 5, 15, 3, 7, 12, 17, 1, 4, 6, 8, 9, 11, 13, 14, 16, 18};
    for (int i = 0; i < 17; i++) {
        insert_node(&root, data[i]);
    }
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");
    node *found_node = search_node(root, 13);
    if (found_node != NULL) {
        printf("Node with data %d found\n", found_node->data);
    } else {
        printf("Node with data 13 not found\n");
    }
    free_tree(root);
    return 0;
}