//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

typedef struct {
    char *name;
    char *value;
} element_t;

typedef struct {
    int num_elements;
    element_t *elements;
} node_t;

void init_node(node_t *node) {
    node->num_elements = 0;
    node->elements = (element_t *)malloc(MAX_ELEMENTS * sizeof(element_t));
}

void add_element(node_t *node, char *name, char *value) {
    if (node->num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        return;
    }
    node->elements[node->num_elements].name = strdup(name);
    node->elements[node->num_elements].value = strdup(value);
    node->num_elements++;
}

void print_node(node_t *node) {
    printf("Node:\n");
    for (int i = 0; i < node->num_elements; i++) {
        printf("  Element %d:\n", i+1);
        printf("    Name: %s\n", node->elements[i].name);
        printf("    Value: %s\n", node->elements[i].value);
    }
}

void free_node(node_t *node) {
    for (int i = 0; i < node->num_elements; i++) {
        free(node->elements[i].name);
        free(node->elements[i].value);
    }
    free(node->elements);
}

int main() {
    node_t root;
    init_node(&root);

    add_element(&root, "name", "John");
    add_element(&root, "age", "25");
    add_element(&root, "city", "New York");

    printf("Root node:\n");
    print_node(&root);

    free_node(&root);
    return 0;
}