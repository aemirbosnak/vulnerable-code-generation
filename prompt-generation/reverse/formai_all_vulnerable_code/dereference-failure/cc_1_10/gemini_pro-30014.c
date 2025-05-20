//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEPTH 10

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
    } else {
        insert_node(&(*root)->right, data);
    }
}

void print_tree(node *root, int depth) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left, depth + 1);

    for (int i = 0; i < depth; i++) {
        printf(" ");
    }

    printf("%d\n", root->data);

    print_tree(root->right, depth + 1);
}

int main() {
    node *root = NULL;

    insert_node(&root, 10);
    insert_node(&root, 5);
    insert_node(&root, 15);
    insert_node(&root, 2);
    insert_node(&root, 7);
    insert_node(&root, 12);
    insert_node(&root, 20);
    insert_node(&root, 1);
    insert_node(&root, 3);
    insert_node(&root, 6);
    insert_node(&root, 8);
    insert_node(&root, 11);
    insert_node(&root, 13);
    insert_node(&root, 16);
    insert_node(&root, 21);

    print_tree(root, 0);

    return 0;
}