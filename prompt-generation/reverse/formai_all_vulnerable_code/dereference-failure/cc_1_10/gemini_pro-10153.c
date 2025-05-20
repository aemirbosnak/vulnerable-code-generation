//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Graph utility function
typedef struct Graph Graph;
struct Graph {
    size_t num_vertices;
    size_t num_edges;
    // sparse or dense matrix, your choice
    int **adj_matrix;
};

// Helper function to create a new graph
Graph *graph_create(size_t num_vertices, size_t num_edges) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->adj_matrix = malloc(sizeof(int *) * num_vertices);
    for (size_t i = 0; i < num_vertices; ++i) {
        graph->adj_matrix[i] = malloc(sizeof(int) * num_vertices);
    }
    return graph;
}

// Helper function to deallocate graph
void graph_destroy(Graph *graph) {
    for (size_t i = 0; i < graph->num_vertices; ++i) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

// Helper function to add an edge to the graph
void graph_add_edge(Graph *graph, size_t src, size_t dst) {
    graph->adj_matrix[src][dst] = 1;
    graph->adj_matrix[dst][src] = 1;
}

// Awesome sauce dfs function 
void dfs(Graph *graph, size_t vertex, int *visited) {
    visited[vertex] = 1;
    printf("Visited vertex %lu\n", vertex);
    for (size_t i = 0; i < graph->num_vertices; ++i) {
        if (graph->adj_matrix[vertex][i] && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

// Function to print the graph
void graph_print(Graph const *graph) {
    for (size_t i = 0; i < graph->num_vertices; ++i) {
        for (size_t j = 0; j < graph->num_vertices; ++j) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Driver function
int main() {
    // Create a graph with 5 vertices and 6 edges
    Graph *graph = graph_create(5, 6);

    // Add edges to the graph
    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 0, 2);
    graph_add_edge(graph, 1, 2);
    graph_add_edge(graph, 1, 3);
    graph_add_edge(graph, 2, 4);
    graph_add_edge(graph, 3, 4);

    // Print the graph
    printf("Adjacency Matrix:\n");
    graph_print(graph);

    // Perform a depth-first search on the graph
    int visited[graph->num_vertices];
    for (size_t i = 0; i < graph->num_vertices; ++i) {
        visited[i] = 0;
    }
    dfs(graph, 0, visited);

    // Deallocate the graph
    graph_destroy(graph);

    return 0;
}