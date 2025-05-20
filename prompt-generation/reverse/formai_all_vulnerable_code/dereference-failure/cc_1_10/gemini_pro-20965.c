//GEMINI-pro DATASET v1.0 Category: Educational ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *key;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(char *key) {
    Node *node = malloc(sizeof(Node));
    node->key = strdup(key);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(Node **root, Node *node) {
    if (*root == NULL) {
        *root = node;
    } else if (strcmp(node->key, (*root)->key) < 0) {
        insert_node(&(*root)->left, node);
    } else {
        insert_node(&(*root)->right, node);
    }
}

Node *search_node(Node *root, char *key) {
    if (root == NULL) {
        return NULL;
    } else if (strcmp(root->key, key) == 0) {
        return root;
    } else if (strcmp(root->key, key) < 0) {
        return search_node(root->left, key);
    } else {
        return search_node(root->right, key);
    }
}

void print_tree(Node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%s\n", root->key);
    print_tree(root->right);
}

int main() {
    Node *root = NULL;
    insert_node(&root, create_node("Hello"));
    insert_node(&root, create_node("World"));
    insert_node(&root, create_node("Foo"));
    insert_node(&root, create_node("Bar"));
    insert_node(&root, create_node("Baz"));
    print_tree(root);
    return 0;
}