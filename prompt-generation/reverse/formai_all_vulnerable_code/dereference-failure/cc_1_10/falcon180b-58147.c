//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int node1;
    int node2;
    int weight;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Edge edges[MAX_EDGES];
} Graph;

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_nodes = 0;
    graph->num_edges = 0;
    return graph;
}

void add_node(Graph* graph) {
    graph->num_nodes++;
}

void add_edge(Graph* graph, int node1, int node2, int weight) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->node1 = node1;
    edge->node2 = node2;
    edge->weight = weight;
    graph->edges[graph->num_edges++] = *edge;
    free(edge);
}

void print_graph(Graph* graph) {
    printf("Number of nodes: %d\n", graph->num_nodes);
    printf("Number of edges: %d\n", graph->num_edges);
    for (int i = 0; i < graph->num_edges; i++) {
        printf("Edge %d: (%d, %d) weight: %d\n", i, graph->edges[i].node1, graph->edges[i].node2, graph->edges[i].weight);
    }
}

int main() {
    Graph* graph = create_graph();
    add_node(graph);
    add_node(graph);
    add_edge(graph, 0, 1, 5);
    add_edge(graph, 1, 0, 2);
    print_graph(graph);
    return 0;
}