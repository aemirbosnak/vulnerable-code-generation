//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    int source;
    int destination;
} Edge;

typedef struct {
    int nodes;
    int edges;
    int *adj_list;
} Graph;

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = 0;
    graph->edges = 0;
    graph->adj_list = (int*)calloc(MAX_NODES, sizeof(int));
    return graph;
}

void add_edge(Graph* graph, int source, int destination) {
    if (graph->edges == MAX_EDGES) {
        printf("Maximum number of edges reached.\n");
        return;
    }
    if (source >= graph->nodes || destination >= graph->nodes) {
        printf("Invalid node index.\n");
        return;
    }
    if (graph->adj_list[source] == -1) {
        graph->adj_list[source] = 1;
    }
    graph->adj_list[destination] = graph->adj_list[source] + 1;
    graph->edges++;
}

void print_graph(Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->nodes; i++) {
        if (graph->adj_list[i]!= -1) {
            printf("Node %d -> Node %d: %d\n", i, graph->adj_list[i], i);
        }
    }
}

int main() {
    Graph* graph = create_graph();
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    print_graph(graph);
    return 0;
}