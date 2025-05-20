//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int num_vertices;
    int **adj_matrix;
};

// Function to create a new graph with the given number of vertices
struct Graph *create_graph(int num_vertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;

    // Allocate memory for the adjacency matrix
    graph->adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = (int *)malloc(num_vertices * sizeof(int));
    }

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void add_edge(struct Graph *graph, int source, int destination) {
    graph->adj_matrix[source][destination] = 1;
}

// Function to print the graph
void print_graph(struct Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
void free_graph(struct Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

// Main function
int main() {
    // Create a new graph with 5 vertices
    struct Graph *graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);

    // Print the graph
    print_graph(graph);

    // Free the memory allocated for the graph
    free_graph(graph);

    return 0;
}