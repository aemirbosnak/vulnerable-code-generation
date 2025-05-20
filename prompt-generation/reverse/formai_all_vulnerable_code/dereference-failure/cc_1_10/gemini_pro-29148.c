//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
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

node_t *search_node(node_t *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

void print_inorder(node_t *root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}

int main() {
    node_t *root = NULL;
    int data[] = {10, 5, 15, 2, 7, 12, 20};
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        insert_node(&root, data[i]);
    }
    print_inorder(root);
    printf("\n");
    printf("Searching for 15: %s\n", search_node(root, 15) ? "found" : "not found");
    printf("Searching for 30: %s\n", search_node(root, 30) ? "found" : "not found");
    return 0;
}