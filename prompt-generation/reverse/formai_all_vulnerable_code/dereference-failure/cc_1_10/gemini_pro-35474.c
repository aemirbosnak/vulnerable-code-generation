//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct {
    int source;
    int target;
    double weight;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Edge edges[MAX_EDGES];
} Graph;

Graph* create_graph(int num_nodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    assert(graph != NULL);

    graph->num_nodes = num_nodes;
    graph->num_edges = 0;

    return graph;
}

void add_edge(Graph* graph, int source, int target, double weight) {
    assert(graph != NULL);
    assert(source >= 0 && source < graph->num_nodes);
    assert(target >= 0 && target < graph->num_nodes);

    graph->edges[graph->num_edges].source = source;
    graph->edges[graph->num_edges].target = target;
    graph->edges[graph->num_edges].weight = weight;

    graph->num_edges++;
}

void print_graph(Graph* graph) {
    assert(graph != NULL);

    printf("Graph with %d nodes and %d edges:\n", graph->num_nodes, graph->num_edges);
    for (int i = 0; i < graph->num_edges; i++) {
        printf("Edge %d: %d -> %d (weight = %.2f)\n", i, graph->edges[i].source, graph->edges[i].target, graph->edges[i].weight);
    }
}

int main() {
    Graph* graph = create_graph(4);

    add_edge(graph, 0, 1, 1.0);
    add_edge(graph, 1, 2, 2.0);
    add_edge(graph, 2, 3, 3.0);
    add_edge(graph, 3, 0, 4.0);

    print_graph(graph);

    return 0;
}