//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    int value;
    struct node *left;
    struct node *right;
} node;

node *new_node(char *key, int value) {
    node *n = malloc(sizeof(node));
    n->key = strdup(key);
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insert(node **root, char *key, int value) {
    if (*root == NULL) {
        *root = new_node(key, value);
        return;
    }

    if (strcmp(key, (*root)->key) < 0) {
        insert(&((*root)->left), key, value);
    } else {
        insert(&((*root)->right), key, value);
    }
}

int search(node *root, char *key) {
    if (root == NULL) {
        return -1;
    }

    if (strcmp(key, root->key) == 0) {
        return root->value;
    } else if (strcmp(key, root->key) < 0) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void destroy_tree(node *root) {
    if (root == NULL) {
        return;
    }

    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root->key);
    free(root);
}

int main() {
    node *root = NULL;

    insert(&root, "Hello", 1);
    insert(&root, "World", 2);
    insert(&root, "Foo", 3);
    insert(&root, "Bar", 4);

    printf("Hello: %d\n", search(root, "Hello"));
    printf("World: %d\n", search(root, "World"));
    printf("Foo: %d\n", search(root, "Foo"));
    printf("Bar: %d\n", search(root, "Bar"));

    destroy_tree(root);

    return 0;
}