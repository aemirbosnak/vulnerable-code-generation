//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the graph structure
typedef struct Graph {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} Graph;

// Create a new graph
Graph *create_graph(int num_vertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->adj_matrix = malloc(sizeof(int *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = malloc(sizeof(int) * num_vertices);
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

// Add an edge to the graph
void add_edge(Graph *graph, int src, int dest) {
    graph->adj_matrix[src][dest] = 1;
    graph->num_edges++;
}

// Print the graph
void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a graph with 5 vertices
    Graph *graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    // Print the graph
    print_graph(graph);

    return 0;
}