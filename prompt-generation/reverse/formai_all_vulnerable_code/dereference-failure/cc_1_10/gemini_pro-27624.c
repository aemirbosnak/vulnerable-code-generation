//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: lively
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

void insert_node(node **root, char *key, int value) {
    if (*root == NULL) {
        *root = create_node(key, value);
        return;
    }

    if (strcmp(key, (*root)->key) < 0) {
        insert_node(&(*root)->left, key, value);
    } else {
        insert_node(&(*root)->right, key, value);
    }
}

int search_node(node *root, char *key) {
    if (root == NULL) {
        return -1;
    }

    if (strcmp(key, root->key) == 0) {
        return root->value;
    }

    if (strcmp(key, root->key) < 0) {
        return search_node(root->left, key);
    } else {
        return search_node(root->right, key);
    }
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%s: %d\n", root->key, root->value);
    print_tree(root->right);
}

void free_tree(node *root) {
    if (root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root->key);
    free(root);
}

int main() {
    node *root = NULL;

    insert_node(&root, "Alice", 1);
    insert_node(&root, "Bob", 2);
    insert_node(&root, "Carol", 3);
    insert_node(&root, "Dave", 4);
    insert_node(&root, "Eve", 5);

    print_tree(root);

    printf("Searching for Alice: %d\n", search_node(root, "Alice"));
    printf("Searching for Bob: %d\n", search_node(root, "Bob"));
    printf("Searching for Carol: %d\n", search_node(root, "Carol"));
    printf("Searching for Dave: %d\n", search_node(root, "Dave"));
    printf("Searching for Eve: %d\n", search_node(root, "Eve"));
    printf("Searching for Frank: %d\n", search_node(root, "Frank"));

    free_tree(root);

    return 0;
}