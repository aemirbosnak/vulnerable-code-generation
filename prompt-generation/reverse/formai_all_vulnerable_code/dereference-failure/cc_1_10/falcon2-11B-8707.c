//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num_nodes;
    int num_edges;
    int* nodes;
    int* edges;
} Graph;

void create_graph(Graph* graph, int num_nodes, int num_edges) {
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
    graph->nodes = (int*) malloc(num_nodes * sizeof(int));
    graph->edges = (int*) malloc(num_edges * sizeof(int));
}

void add_edge(Graph* graph, int node1, int node2) {
    graph->edges[graph->num_edges] = node2;
    graph->nodes[node1] = node2;
    graph->nodes[node2] = node1;
    graph->num_edges++;
}

void print_graph(Graph* graph) {
    printf("Number of nodes: %d\n", graph->num_nodes);
    printf("Number of edges: %d\n", graph->num_edges);
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < graph->num_edges; j++) {
            if (graph->edges[j] == i) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    int num_nodes = 5;
    int num_edges = 10;
    Graph graph = {0, 0, NULL, NULL};
    create_graph(&graph, num_nodes, num_edges);
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_edges; j++) {
            add_edge(&graph, i, j);
        }
    }
    print_graph(&graph);
    free(graph.nodes);
    free(graph.edges);
    return 0;
}