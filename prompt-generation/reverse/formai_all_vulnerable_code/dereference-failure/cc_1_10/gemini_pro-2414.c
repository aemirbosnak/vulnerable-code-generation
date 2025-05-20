//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *name;
    struct node *next;
} node;

typedef struct graph {
    int num_nodes;
    node *nodes;
} graph;

graph *create_graph() {
    graph *g = malloc(sizeof(graph));
    g->num_nodes = 0;
    g->nodes = NULL;
    return g;
}

void add_node(graph *g, char *name) {
    node *n = malloc(sizeof(node));
    n->name = strdup(name);
    n->next = NULL;
    node *curr = g->nodes;
    if (!curr) {
        g->nodes = n;
    }
    else {
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = n;
    }
    g->num_nodes++;
}

void print_graph(graph *g) {
    node *curr = g->nodes;
    while (curr) {
        printf("%s ", curr->name);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    graph *g = create_graph();
    add_node(g, "Alan Turing");
    add_node(g, "Ada Lovelace");
    add_node(g, "Charles Babbage");
    print_graph(g);
    free(g);
    return 0;
}