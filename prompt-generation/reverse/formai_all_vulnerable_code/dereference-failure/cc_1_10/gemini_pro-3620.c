//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the graph structure
typedef struct graph {
    int num_vertices;
    int num_edges;
    int** adjacency_matrix;
} graph_t;

// Create a new graph
graph_t* create_graph(int num_vertices) {
    graph_t* graph = (graph_t*)malloc(sizeof(graph_t));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->adjacency_matrix = (int**)malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_matrix[i] = (int*)calloc(num_vertices, sizeof(int));
    }
    return graph;
}

// Destroy a graph
void destroy_graph(graph_t* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adjacency_matrix[i]);
    }
    free(graph->adjacency_matrix);
    free(graph);
}

// Add an edge to a graph
void add_edge(graph_t* graph, int src, int dest) {
    graph->adjacency_matrix[src][dest] = 1;
    graph->num_edges++;
}

// Remove an edge from a graph
void remove_edge(graph_t* graph, int src, int dest) {
    graph->adjacency_matrix[src][dest] = 0;
    graph->num_edges--;
}

// Print a graph
void print_graph(graph_t* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a graph
    graph_t* graph = create_graph(5);

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

    // Destroy the graph
    destroy_graph(graph);

    return 0;
}