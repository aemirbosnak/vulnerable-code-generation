//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

struct edge {
    int weight;
    int source;
    int destination;
};

struct graph {
    int num_vertices;
    int num_edges;
    struct edge edges[MAX_EDGES];
};

struct graph* create_graph(int num_vertices) {
    struct graph* graph = (struct graph*) malloc(sizeof(struct graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    return graph;
}

void add_edge(struct graph* graph, int source, int destination, int weight) {
    if (graph->num_edges >= MAX_EDGES) {
        printf("Cannot add more than %d edges to this graph.\n", MAX_EDGES);
        return;
    }
    graph->edges[graph->num_edges].source = source;
    graph->edges[graph->num_edges].destination = destination;
    graph->edges[graph->num_edges].weight = weight;
    graph->num_edges++;
}

void print_graph(struct graph* graph) {
    for (int i = 0; i < graph->num_edges; i++) {
        printf("Edge (%d, %d) has weight %d\n", graph->edges[i].source, graph->edges[i].destination, graph->edges[i].weight);
    }
}

int main() {
    struct graph* graph = create_graph(MAX_VERTICES);
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = i + 1; j < MAX_VERTICES; j++) {
            add_edge(graph, i, j, rand() % 10);
        }
    }
    print_graph(graph);
    return 0;
}