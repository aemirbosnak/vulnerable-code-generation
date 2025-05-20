//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num_nodes;
    int **edges;
} Graph;

Graph *create_graph(int num_nodes) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->edges = malloc(sizeof(int *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->edges[i] = malloc(sizeof(int) * num_nodes);
        for (int j = 0; j < num_nodes; j++) {
            graph->edges[i][j] = 0;
        }
    }
    return graph;
}

void destroy_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->edges[i]);
    }
    free(graph->edges);
    free(graph);
}

void add_edge(Graph *graph, int node1, int node2) {
    graph->edges[node1][node2] = 1;
    graph->edges[node2][node1] = 1;
}

int main() {
    int num_nodes = 5;
    Graph *graph = create_graph(num_nodes);

    // Add edges to the graph.
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);

    // Print the graph.
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", graph->edges[i][j]);
        }
        printf("\n");
    }

    // Destroy the graph.
    destroy_graph(graph);

    return 0;
}