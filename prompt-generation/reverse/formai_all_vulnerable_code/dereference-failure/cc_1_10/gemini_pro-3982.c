//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 200

typedef struct {
    int source;
    int destination;
    int weight;
} edge;

typedef struct {
    int num_vertices;
    int num_edges;
    edge edges[MAX_EDGES];
} graph;

graph *create_graph(int num_vertices) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = 0;
    return g;
}

void add_edge(graph *g, int source, int destination, int weight) {
    edge e = {source, destination, weight};
    g->edges[g->num_edges++] = e;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_edges; i++) {
        edge e = g->edges[i];
        printf("Edge %d: %d -> %d (%d)\n", i, e.source, e.destination, e.weight);
    }
}

int main() {
    graph *g = create_graph(5);
    add_edge(g, 0, 1, 10);
    add_edge(g, 0, 2, 20);
    add_edge(g, 1, 2, 30);
    add_edge(g, 1, 3, 40);
    add_edge(g, 2, 3, 50);
    add_edge(g, 3, 4, 60);
    add_edge(g, 4, 0, 70);

    print_graph(g);

    return 0;
}