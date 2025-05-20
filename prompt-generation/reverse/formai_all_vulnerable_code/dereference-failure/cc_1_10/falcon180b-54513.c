//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 100

typedef struct {
    char *name;
    size_t size;
    struct node *parent;
    struct node *children[MAX_DEPTH];
    size_t num_children;
} node_t;

node_t *root = NULL;

void add_node(node_t *parent, const char *name, size_t size) {
    node_t *child = malloc(sizeof(node_t));
    child->name = strdup(name);
    child->size = size;
    child->parent = parent;
    parent->children[parent->num_children++] = child;
    root = child;
}

void print_tree(node_t *node, int depth) {
    if (node == NULL)
        return;

    for (int i = 0; i < depth; i++)
        printf("  ");

    printf("%s (%zu bytes)\n", node->name, node->size);

    for (int i = 0; i < node->num_children; i++) {
        print_tree(node->children[i], depth + 1);
    }
}

void free_tree(node_t *node) {
    for (int i = 0; i < node->num_children; i++) {
        free_tree(node->children[i]);
    }

    free(node->name);
    free(node);
}

int main() {
    add_node(NULL, "main", 0);

    printf("Memory usage tree:\n");
    print_tree(root, 0);

    free_tree(root);

    return 0;
}