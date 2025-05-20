//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

node *search_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else if (data > root->data) {
        return search_node(root->right, data);
    } else {
        return root;
    }
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main() {
    node *root = NULL;
    int n, i, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert_node(root, data);
    }
    printf("The binary search tree is: ");
    print_tree(root);
    printf("\n");
    printf("Enter the data to search: ");
    scanf("%d", &data);
    node *result = search_node(root, data);
    if (result == NULL) {
        printf("The data is not found.\n");
    } else {
        printf("The data is found.\n");
    }
    return 0;
}