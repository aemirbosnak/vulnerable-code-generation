//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// A node in a binary tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Create a new node with the given data
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into the binary tree
void insert_node(node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data <= (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

// Print the binary tree in a visual format
void print_tree(node *root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("    ");
    }

    printf("%d\n", root->data);

    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
}

int main() {
    node *root = NULL;

    insert_node(&root, 50);
    insert_node(&root, 30);
    insert_node(&root, 70);
    insert_node(&root, 20);
    insert_node(&root, 40);
    insert_node(&root, 60);
    insert_node(&root, 80);

    print_tree(root, 0);

    return 0;
}