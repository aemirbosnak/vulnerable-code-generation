//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: sophisticated
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

void insert_node(node_t **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }
    if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else if (data > (*root)->data) {
        insert_node(&(*root)->right, data);
    }
}

node_t *search_node(node_t *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else if (data > root->data) {
        return search_node(root->right, data);
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

int main() {
    node_t *root = NULL;
    int i;
    int data[] = {10, 5, 15, 3, 7, 12, 17, 1, 4, 8};
    for (i = 0; i < 10; i++) {
        insert_node(&root, data[i]);
    }
    print_inorder(root);
    printf("\n");
    node_t *node = search_node(root, 8);
    if (node != NULL) {
        printf("Found node with data: %d\n", node->data);
    } else {
        printf("Node not found\n");
    }
    return 0;
}