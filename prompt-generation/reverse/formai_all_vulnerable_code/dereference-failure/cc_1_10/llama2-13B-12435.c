//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define GRAPH_MAX_NODES 1024
#define GRAPH_MAX_EDGES 1024

typedef struct {
    char *label;
    int weight;
    struct node *next;
} edge_t;

typedef struct {
    char *label;
    int weight;
    edge_t *edges;
} graph_t;

graph_t *create_graph(void) {
    graph_t *g = calloc(1, sizeof(graph_t));
    g->label = "My Secret Graph";
    g->weight = 10;
    g->edges = calloc(GRAPH_MAX_EDGES, sizeof(edge_t));
    return g;
}

void add_edge(graph_t *g, char *label, int weight) {
    edge_t *e = calloc(1, sizeof(edge_t));
    e->label = label;
    e->weight = weight;
    e->next = g->edges;
    g->edges = e;
}

void traverse(graph_t *g) {
    for (edge_t *e = g->edges; e != NULL; e = e->next) {
        printf("%s -> %s (%d)\n", g->label, e->label, e->weight);
    }
}

int main(void) {
    graph_t *g = create_graph();

    add_edge(g, "Alice", 5);
    add_edge(g, "Bob", 10);
    add_edge(g, "Charlie", 15);
    add_edge(g, "David", 20);

    traverse(g);

    return 0;
}