//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: scientific
// Computational Cosmic Cloud Crawler (C4) v1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LEN 1024
#define MAX_DEPTH 5

typedef struct node {
    char name[MAX_LEN];
    int age;
    struct node *parent;
    struct node *children[MAX_DEPTH];
} node_t;

node_t *create_node(char *name, int age) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->parent = NULL;
    new_node->children[0] = NULL;
    return new_node;
}

void print_node(node_t *node) {
    printf("%s (%d)\n", node->name, node->age);
    for (int i = 0; i < MAX_DEPTH; i++) {
        if (node->children[i] != NULL) {
            print_node(node->children[i]);
        }
    }
}

void traverse(node_t *root) {
    print_node(root);
    for (int i = 0; i < MAX_DEPTH; i++) {
        if (root->children[i] != NULL) {
            traverse(root->children[i]);
        }
    }
}

int main() {
    node_t *root = create_node("Galaxy", 1350000000);
    root->children[0] = create_node("Andromeda", 225000000);
    root->children[1] = create_node("Milky Way", 1000000000);
    traverse(root);
    return 0;
}