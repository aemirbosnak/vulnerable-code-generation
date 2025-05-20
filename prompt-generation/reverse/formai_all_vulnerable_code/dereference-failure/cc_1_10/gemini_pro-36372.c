//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// create a list of edges
struct edge {
    int from;
    int to;
    int weight;
};

struct graph {
    int num_vertices;
    int num_edges;
    struct edge *edges;
};

// create a new graph
struct graph *create_graph(int num_vertices, int num_edges) {
    struct graph *graph = malloc(sizeof(struct graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->edges = malloc(num_edges * sizeof(struct edge));
    return graph;
}

// add an edge to the graph
void add_edge(struct graph *graph, int from, int to, int weight) {
    assert(from >= 0 && from < graph->num_vertices);
    assert(to >= 0 && to < graph->num_vertices);
    graph->edges[graph->num_edges].from = from;
    graph->edges[graph->num_edges].to = to;
    graph->edges[graph->num_edges].weight = weight;
    graph->num_edges++;
}

// print the graph
void print_graph(struct graph *graph) {
    for (int i = 0; i < graph->num_edges; i++) {
        printf("Edge %d: %d -> %d (%d)\n", i, graph->edges[i].from, graph->edges[i].to, graph->edges[i].weight);
    }
}

// free the graph
void free_graph(struct graph *graph) {
    free(graph->edges);
    free(graph);
}

// test the graph representation
int main() {
    struct graph *graph = create_graph(5, 6);
    add_edge(graph, 0, 1, 1);
    add_edge(graph, 0, 2, 2);
    add_edge(graph, 1, 2, 3);
    add_edge(graph, 1, 3, 4);
    add_edge(graph, 2, 3, 5);
    add_edge(graph, 3, 4, 6);
    print_graph(graph);
    free_graph(graph);
    return 0;
}