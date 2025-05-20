//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

node *insert_node(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

void inorder_traversal(node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

bool search_node(node *root, int data) {
    if (root == NULL) {
        return false;
    } else if (data == root->data) {
        return true;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

int main() {
    int n, i, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    node *root = NULL;
    printf("Enter the data values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert_node(root, data);
    }
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");
    int search_value;
    printf("Enter the value to search: ");
    scanf("%d", &search_value);
    if (search_node(root, search_value)) {
        printf("The value %d is found in the tree.\n", search_value);
    } else {
        printf("The value %d is not found in the tree.\n", search_value);
    }
    return 0;
}