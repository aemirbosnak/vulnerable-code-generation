//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *name;
    long size;
    struct node *left;
    struct node *right;
} node;

node *create_node(char *name, long size) {
    node *new_node = malloc(sizeof(node));
    new_node->name = strdup(name);
    new_node->size = size;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node **root, node *new_node) {
    if (*root == NULL) {
        *root = new_node;
        return;
    }

    if (new_node->size > (*root)->size) {
        insert_node(&(*root)->right, new_node);
    } else {
        insert_node(&(*root)->left, new_node);
    }
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%s: %ld bytes\n", root->name, root->size);
    print_tree(root->right);
}

int main() {
    node *root = NULL;

    // Insert some sample data
    insert_node(&root, create_node("Documents", 10000000));
    insert_node(&root, create_node("Pictures", 5000000));
    insert_node(&root, create_node("Music", 2000000));
    insert_node(&root, create_node("Videos", 1000000));
    insert_node(&root, create_node("Downloads", 500000));
    insert_node(&root, create_node("Other", 200000));

    // Print the tree
    print_tree(root);

    return 0;
}