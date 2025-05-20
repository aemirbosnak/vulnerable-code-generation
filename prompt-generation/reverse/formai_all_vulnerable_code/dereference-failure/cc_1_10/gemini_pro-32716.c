//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *left;
    struct node_t *right;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error allocating memory for new node.\n");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node_t *insert_node(node_t *root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

void inorder_traversal(node_t *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

node_t *search_node(node_t *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data == root->data) {
        return root;
    }
    if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

int main() {
    node_t *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    int search_value = 15;
    node_t *found_node = search_node(root, search_value);
    if (found_node != NULL) {
        printf("Found node with value %d\n", found_node->data);
    } else {
        printf("Node with value %d not found\n", search_value);
    }

    return 0;
}