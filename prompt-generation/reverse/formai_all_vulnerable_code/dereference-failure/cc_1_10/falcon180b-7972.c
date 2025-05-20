//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_WEIGHT 100

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Edge edges[MAX_EDGES];
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_nodes = 0;
    graph->num_edges = 0;
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    if (graph->num_edges >= MAX_EDGES) {
        printf("Error: Maximum number of edges reached.\n");
        return;
    }
    Edge edge = {src, dest, weight};
    graph->edges[graph->num_edges++] = edge;
}

void printGraph(Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->num_edges; i++) {
        printf("%d -> %d (%d)\n", graph->edges[i].src, graph->edges[i].dest, graph->edges[i].weight);
    }
}

int main() {
    Graph* graph = createGraph();
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 5);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 20);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 2, 4, 10);
    addEdge(graph, 3, 4, 5);
    printGraph(graph);
    return 0;
}