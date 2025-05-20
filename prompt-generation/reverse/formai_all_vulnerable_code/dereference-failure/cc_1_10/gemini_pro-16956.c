//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

node_t *create_node(int data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

node_t *insert_node(node_t *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

node_t *search_node(node_t *root, int data) {
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

void print_tree(node_t *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_tree(root->left);
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
    int data[] = {25, 15, 5, 30, 20, 40, 35, 45};
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        root = insert_node(root, data[i]);
    }
    printf("The binary search tree is: ");
    print_tree(root);
    printf("\n");
    int search_key = 35;
    node_t *found_node = search_node(root, search_key);
    if (found_node == NULL) {
        printf("The key %d was not found in the tree.\n", search_key);
    } else {
        printf("The key %d was found in the tree.\n", search_key);
    }
    free_tree(root);
    return 0;
}