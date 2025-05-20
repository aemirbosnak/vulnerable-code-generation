//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num_nodes;
    int num_edges;
    int **adj_list;
} Graph;

Graph *create_graph(int num_nodes, int num_edges) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
    graph->adj_list = malloc(sizeof(int *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->adj_list[i] = malloc(sizeof(int) * num_edges);
        for (int j = 0; j < num_edges; j++) {
            graph->adj_list[i][j] = 0;
        }
    }
    return graph;
}

void destroy_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->adj_list[i]);
    }
    free(graph->adj_list);
    free(graph);
}

void add_edge(Graph *graph, int node1, int node2) {
    graph->adj_list[node1][node2] = 1;
}

void remove_edge(Graph *graph, int node1, int node2) {
    graph->adj_list[node1][node2] = 0;
}

int main() {
    Graph *graph = create_graph(5, 5);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 0);

    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_edges; j++) {
            printf("%d ", graph->adj_list[i][j]);
        }
        printf("\n");
    }

    destroy_graph(graph);

    return 0;
}