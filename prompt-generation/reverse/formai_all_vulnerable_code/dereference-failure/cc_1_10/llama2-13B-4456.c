//LLAMA2-13B DATASET v1.0 Category: Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define MAX_DEPTH 5

typedef struct node {
    char *value;
    struct node *left;
    struct node *right;
} node_t;

node_t *create_node(char *value) {
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(node_t **root, char *value) {
    if (*root == NULL) {
        *root = create_node(value);
    } else if (strcmp((*root)->value, value) < 0) {
        insert_node(&(*root)->left, value);
    } else {
        insert_node(&(*root)->right, value);
    }
}

void traverse(node_t *root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%s ", root->value);
        traverse(root->right);
    }
}

int main() {
    node_t *root = NULL;

    // Insert nodes
    insert_node(&root, "apple");
    insert_node(&root, "banana");
    insert_node(&root, "cherry");
    insert_node(&root, "date");
    insert_node(&root, "elderberry");

    // Traverse the tree
    traverse(root);

    return 0;
}