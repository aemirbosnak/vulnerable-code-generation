//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct {
    int src;
    int dest;
    int weight;
} edge;

typedef struct {
    int num_nodes;
    int num_edges;
    edge edges[MAX_EDGES];
} graph;

graph *create_graph(int num_nodes) {
    graph *g = malloc(sizeof(graph));
    g->num_nodes = num_nodes;
    g->num_edges = 0;
    return g;
}

void add_edge(graph *g, int src, int dest, int weight) {
    g->edges[g->num_edges].src = src;
    g->edges[g->num_edges].dest = dest;
    g->edges[g->num_edges].weight = weight;
    g->num_edges++;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_edges; i++) {
        printf("%d -> %d (%d)\n", g->edges[i].src, g->edges[i].dest, g->edges[i].weight);
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

    printf("Graph:\n");
    print_graph(g);

    return 0;
}