//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Edge {
    int source;
    int destination;
    int weight;
} Edge;

typedef struct Graph {
    int num_vertices;
    int num_edges;
    Edge *edges;
} Graph;

Graph *create_graph(int num_vertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->edges = NULL;
    return graph;
}

void add_edge(Graph *graph, int source, int destination, int weight) {
    graph->num_edges++;
    graph->edges = realloc(graph->edges, graph->num_edges * sizeof(Edge));
    graph->edges[graph->num_edges - 1].source = source;
    graph->edges[graph->num_edges - 1].destination = destination;
    graph->edges[graph->num_edges - 1].weight = weight;
}

void print_graph(Graph *graph) {
    printf("Graph with %d vertices and %d edges:\n", graph->num_vertices, graph->num_edges);
    for (int i = 0; i < graph->num_edges; i++) {
        printf("Edge %d: %d -> %d (weight %d)\n", i, graph->edges[i].source, graph->edges[i].destination, graph->edges[i].weight);
    }
}

int main() {
    Graph *graph = create_graph(5);
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 2, 5);
    add_edge(graph, 1, 2, 3);
    add_edge(graph, 1, 3, 7);
    add_edge(graph, 2, 4, 2);
    add_edge(graph, 3, 4, 9);
    print_graph(graph);
    return 0;
}