//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    int value;
    struct node *left;
    struct node *right;
} node;

node *create_node(char *key, int value) {
    node *new_node = malloc(sizeof(node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(node **root, char *key, int value) {
    if (*root == NULL) {
        *root = create_node(key, value);
    } else if (strcmp(key, (*root)->key) < 0) {
        insert(&(*root)->left, key, value);
    } else if (strcmp(key, (*root)->key) > 0) {
        insert(&(*root)->right, key, value);
    } else {
        (*root)->value = value;
    }
}

node *search(node *root, char *key) {
    if (root == NULL) {
        return NULL;
    } else if (strcmp(key, root->key) < 0) {
        return search(root->left, key);
    } else if (strcmp(key, root->key) > 0) {
        return search(root->right, key);
    } else {
        return root;
    }
}

void print_tree(node *root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%s: %d\n", root->key, root->value);
        print_tree(root->right);
    }
}

void free_tree(node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root->key);
        free(root);
    }
}

int main() {
    node *root = NULL;
    insert(&root, "Ada", 1);
    insert(&root, "Lovelace", 2);
    insert(&root, "programming", 3);
    insert(&root, "science", 4);
    insert(&root, "computer", 5);
    insert(&root, "mathematics", 6);
    print_tree(root);
    node *result = search(root, "Lovelace");
    if (result != NULL) {
        printf("Found: %s: %d\n", result->key, result->value);
    } else {
        printf("Not found\n");
    }
    free_tree(root);
    return 0;
}