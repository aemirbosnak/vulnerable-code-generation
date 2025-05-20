//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    char *value;
    struct node *left;
    struct node *right;
} node;

node *create_node(char *key, char *value) {
    node *new_node = malloc(sizeof(node));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(node **root, char *key, char *value) {
    if (*root == NULL) {
        *root = create_node(key, value);
    } else if (strcmp(key, (*root)->key) < 0) {
        insert(&(*root)->left, key, value);
    } else if (strcmp(key, (*root)->key) > 0) {
        insert(&(*root)->right, key, value);
    } else {
        (*root)->value = strdup(value);
    }
}

char *search(node *root, char *key) {
    if (root == NULL) {
        return NULL;
    } else if (strcmp(key, root->key) < 0) {
        return search(root->left, key);
    } else if (strcmp(key, root->key) > 0) {
        return search(root->right, key);
    } else {
        return root->value;
    }
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%s: %s\n", root->key, root->value);
    print_tree(root->right);
}

int main() {
    node *root = NULL;

    insert(&root, "a", "1");
    insert(&root, "b", "2");
    insert(&root, "c", "3");
    insert(&root, "d", "4");
    insert(&root, "e", "5");

    print_tree(root);

    printf("Searching for key \"c\": %s\n", search(root, "c"));

    return 0;
}