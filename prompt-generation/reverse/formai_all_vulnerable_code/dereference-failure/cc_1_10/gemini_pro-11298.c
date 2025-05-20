//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct {
    int num_nodes;
    int num_edges;
    int **adj_matrix;
} Graph;

Graph* create_graph(int num_nodes, int num_edges) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
    graph->adj_matrix = (int**)malloc(sizeof(int*) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->adj_matrix[i] = (int*)malloc(sizeof(int) * num_nodes);
        for (int j = 0; j < num_nodes; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

void destroy_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

void add_edge(Graph *graph, int node1, int node2) {
    graph->adj_matrix[node1][node2] = 1;
    graph->adj_matrix[node2][node1] = 1;
}

void remove_edge(Graph *graph, int node1, int node2) {
    graph->adj_matrix[node1][node2] = 0;
    graph->adj_matrix[node2][node1] = 0;
}

int is_connected(Graph *graph, int node1, int node2) {
    return graph->adj_matrix[node1][node2] == 1;
}

int main() {
    // Create a graph with 10 nodes and 20 edges
    Graph *graph = create_graph(10, 20);

    // Add some edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);
    add_edge(graph, 3, 5);
    add_edge(graph, 4, 5);
    add_edge(graph, 4, 6);
    add_edge(graph, 5, 6);
    add_edge(graph, 5, 7);
    add_edge(graph, 6, 7);
    add_edge(graph, 6, 8);
    add_edge(graph, 7, 8);
    add_edge(graph, 7, 9);
    add_edge(graph, 8, 9);
    add_edge(graph, 8, 0);
    add_edge(graph, 9, 0);

    // Print the adjacency matrix of the graph
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }

    // Check if two nodes are connected
    int node1 = 0;
    int node2 = 5;
    if (is_connected(graph, node1, node2)) {
        printf("Nodes %d and %d are connected.\n", node1, node2);
    } else {
        printf("Nodes %d and %d are not connected.\n", node1, node2);
    }

    // Destroy the graph
    destroy_graph(graph);

    return 0;
}