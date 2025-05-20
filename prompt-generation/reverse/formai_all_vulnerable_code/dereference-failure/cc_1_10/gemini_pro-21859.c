//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct node {
    int id;
    char *label;
    int degree;
    struct node *neighbors[MAX_EDGES];
} node;

typedef struct graph {
    int num_nodes;
    int num_edges;
    node *nodes[MAX_NODES];
} graph;

graph *create_graph() {
    graph *g = malloc(sizeof(graph));
    g->num_nodes = 0;
    g->num_edges = 0;
    return g;
}

void add_node(graph *g, int id, char *label) {
    if (g->num_nodes == MAX_NODES) {
        printf("Error: graph is full.\n");
        return;
    }

    node *n = malloc(sizeof(node));
    n->id = id;
    n->label = strdup(label);
    n->degree = 0;

    g->nodes[g->num_nodes++] = n;
}

void add_edge(graph *g, int from, int to) {
    if (from >= g->num_nodes || to >= g->num_nodes) {
        printf("Error: invalid node IDs.\n");
        return;
    }

    node *n1 = g->nodes[from];
    node *n2 = g->nodes[to];

    n1->neighbors[n1->degree++] = n2;
    n2->neighbors[n2->degree++] = n1;

    g->num_edges++;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        node *n = g->nodes[i];
        printf("Node %d (%s) has %d neighbors:\n", n->id, n->label, n->degree);
        for (int j = 0; j < n->degree; j++) {
            printf("  - %s\n", n->neighbors[j]->label);
        }
    }
}

void destroy_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        free(g->nodes[i]->label);
        free(g->nodes[i]);
    }

    free(g);
}

int main() {
    graph *g = create_graph();

    add_node(g, 0, "Alice");
    add_node(g, 1, "Bob");
    add_node(g, 2, "Carol");
    add_node(g, 3, "Dave");
    add_node(g, 4, "Eve");

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    print_graph(g);

    destroy_graph(g);

    return 0;
}