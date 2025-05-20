//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *name;
    struct node *parent;
    struct node *children;
    struct node *next;
} node_t;

node_t *create_node(char *name) {
    node_t *node = malloc(sizeof(node_t));
    node->name = strdup(name);
    node->parent = NULL;
    node->children = NULL;
    node->next = NULL;
    return node;
}

void add_child(node_t *parent, node_t *child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        node_t *current = parent->children;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = child;
    }
    child->parent = parent;
}

void print_tree(node_t *root, int depth) {
    for (int i = 0; i < depth; i++) {
        printf(" ");
    }
    printf("%s\n", root->name);
    if (root->children != NULL) {
        print_tree(root->children, depth + 1);
    }
}

int main() {
    node_t *root = create_node("/");
    node_t *bin = create_node("bin");
    node_t *home = create_node("home");
    node_t *usr = create_node("usr");
    node_t *var = create_node("var");
    node_t *etc = create_node("etc");
    node_t *opt = create_node("opt");
    node_t *srv = create_node("srv");
    add_child(root, bin);
    add_child(root, home);
    add_child(root, usr);
    add_child(root, var);
    add_child(root, etc);
    add_child(root, opt);
    add_child(root, srv);
    print_tree(root, 0);
    return 0;
}