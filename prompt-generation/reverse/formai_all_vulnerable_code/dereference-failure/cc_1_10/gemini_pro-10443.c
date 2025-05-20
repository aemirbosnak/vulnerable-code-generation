//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the graph structure
typedef struct Graph {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} Graph;

// Create a new graph with the given number of vertices
Graph *create_graph(int num_vertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->adj_matrix = malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

// Add an edge to the graph
void add_edge(Graph *graph, int source, int destination) {
    graph->adj_matrix[source][destination] = 1;
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

// Free the graph
void free_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

// Use the graph to represent a social network
int main() {
    // Create a graph with 5 vertices to represent 5 people
    Graph *graph = create_graph(5);

    // Add edges to the graph to represent friendships
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Print the graph
    print_graph(graph);

    // Check if two people are friends
    int person1 = 0;
    int person2 = 3;
    if (graph->adj_matrix[person1][person2] == 1) {
        printf("%d and %d are friends.\n", person1, person2);
    } else {
        printf("%d and %d are not friends.\n", person1, person2);
    }

    // Free the graph
    free_graph(graph);

    return 0;
}