//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    char *value;
    struct node *left;
    struct node *right;
} node_t;

node_t *create_node(int key, char *value) {
    node_t *node = malloc(sizeof(node_t));
    node->key = key;
    node->value = strdup(value);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(node_t **root, int key, char *value) {
    if (*root == NULL) {
        *root = create_node(key, value);
    } else if (key < (*root)->key) {
        insert_node(&(*root)->left, key, value);
    } else if (key > (*root)->key) {
        insert_node(&(*root)->right, key, value);
    } else {
        free(value);  // Duplicate key, discard the new value
    }
}

node_t *search_node(node_t *root, int key) {
    if (root == NULL) {
        return NULL;
    } else if (key == root->key) {
        return root;
    } else if (key < root->key) {
        return search_node(root->left, key);
    } else {
        return search_node(root->right, key);
    }
}

void print_node(node_t *node) {
    if (node == NULL) {
        return;
    }
    printf("%d: %s\n", node->key, node->value);
}

void print_tree(node_t *root) {
    if (root == NULL) {
        return;
    }
    print_node(root);
    print_tree(root->left);
    print_tree(root->right);
}

void free_node(node_t *node) {
    if (node == NULL) {
        return;
    }
    free(node->value);
    free(node);
}

void free_tree(node_t *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free_node(root);
}

int main() {
    node_t *root = NULL;

    insert_node(&root, 10, "John");
    insert_node(&root, 5, "Bob");
    insert_node(&root, 15, "Alice");
    insert_node(&root, 7, "Charlie");
    insert_node(&root, 12, "Dave");

    print_tree(root);

    node_t *node = search_node(root, 12);
    if (node != NULL) {
        printf("Found node: %d: %s\n", node->key, node->value);
    } else {
        printf("Node not found\n");
    }

    free_tree(root);

    return 0;
}