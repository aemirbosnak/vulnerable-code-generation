//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    int value;
    struct node *left;
    struct node *right;
} node_t;

node_t *create_node(char *key, int value) {
    node_t *node = malloc(sizeof(node_t));
    node->key = strdup(key);
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(node_t **root, char *key, int value) {
    if (*root == NULL) {
        *root = create_node(key, value);
    } else if (strcmp(key, (*root)->key) < 0) {
        insert_node(&(*root)->left, key, value);
    } else if (strcmp(key, (*root)->key) > 0) {
        insert_node(&(*root)->right, key, value);
    } else {
        (*root)->value = value;
    }
}

node_t *find_node(node_t *root, char *key) {
    if (root == NULL) {
        return NULL;
    } else if (strcmp(key, root->key) == 0) {
        return root;
    } else if (strcmp(key, root->key) < 0) {
        return find_node(root->left, key);
    } else {
        return find_node(root->right, key);
    }
}

void print_node(node_t *root) {
    if (root == NULL) {
        return;
    }
    print_node(root->left);
    printf("%s: %d\n", root->key, root->value);
    print_node(root->right);
}

void free_node(node_t *root) {
    if (root == NULL) {
        return;
    }
    free_node(root->left);
    free_node(root->right);
    free(root->key);
    free(root);
}

int main() {
    node_t *root = NULL;
    insert_node(&root, "foo", 1);
    insert_node(&root, "bar", 2);
    insert_node(&root, "baz", 3);
    print_node(root);
    node_t *node = find_node(root, "bar");
    if (node != NULL) {
        printf("Found node with key '%s' and value %d\n", node->key, node->value);
    }
    free_node(root);
    return 0;
}