//FormAI DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct Graph {
    int num_nodes;
    int num_edges;
    Edge* edges[MAX_NODES];
} Graph;

Graph* create_graph(int num_nodes, int num_edges) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
    for (int i = 0; i < num_nodes; i++) {
        graph->edges[i] = NULL;
    }
    return graph;
}

void add_edge(Graph* graph, int src, int dest, int weight) {
    Edge* edge = malloc(sizeof(Edge));
    edge->src = src;
    edge->dest = dest;
    edge->weight = weight;
    graph->edges[src] = edge;
}

void print_graph(Graph* graph) {
    printf("Graph with %d nodes and %d edges:\n", graph->num_nodes, graph->num_edges);
    for (int i = 0; i < graph->num_nodes; i++) {
        if (graph->edges[i] == NULL) {
            continue;
        }
        printf("Edge from node %d to node %d with weight %d\n", graph->edges[i]->src, graph->edges[i]->dest, graph->edges[i]->weight);
    }
}

int main() {
    Graph* graph = create_graph(5, 4);
    add_edge(graph, 0, 1, 2);
    add_edge(graph, 1, 2, 3);
    add_edge(graph, 2, 3, 4);
    add_edge(graph, 3, 4, 5);
    print_graph(graph);
    return 0;
}