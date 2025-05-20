//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct node {
    char *data;
    struct node *left;
    struct node *right;
} node;

node *create_node(char *data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = strdup(data);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node **root, char *data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else {
        if (strcmp(data, (*root)->data) < 0) {
            insert_node(&(*root)->left, data);
        } else {
            insert_node(&(*root)->right, data);
        }
    }
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%s\n", root->data);
    print_tree(root->right);
}

void free_tree(node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root->data);
    free(root);
}

int main() {
    node *root = NULL;
    insert_node(&root, "apple");
    insert_node(&root, "banana");
    insert_node(&root, "cherry");
    insert_node(&root, "dog");
    insert_node(&root, "elephant");
    insert_node(&root, "fish");
    insert_node(&root, "grape");
    insert_node(&root, "horse");
    insert_node(&root, "ice cream");
    insert_node(&root, "juice");
    print_tree(root);
    free_tree(root);
    return 0;
}