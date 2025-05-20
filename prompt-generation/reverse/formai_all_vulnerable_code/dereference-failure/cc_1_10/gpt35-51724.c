//FormAI DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining the Graph Structure
typedef struct Graph {
    int vertices;
    int** adjacency_matrix;
} Graph;

// Create a Graph with a given number of vertices
Graph* create_graph(int vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertices = vertices;

    graph->adjacency_matrix = (int**) malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; ++i) {
        graph->adjacency_matrix[i] = (int*) malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; ++j) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }

    return graph;
}

// Add an edge to the Graph
void add_edge(Graph* graph, int source, int destination) {
    graph->adjacency_matrix[source][destination] = 1;
    graph->adjacency_matrix[destination][source] = 1;
}

// Print the Graph in an Adjacency Matrix format
void print_graph(Graph* graph) {
    printf("The Graph in the form of Adjacency Matrix is:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        for (int j = 0; j < graph->vertices; ++j) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Creating a Graph with 5 vertices
    Graph* graph = create_graph(5);

    // Adding edges to the Graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Printing the Graph
    print_graph(graph);

    // Freeing the memory allocated to the Graph
    for (int i = 0; i < graph->vertices; ++i) {
        free(graph->adjacency_matrix[i]);
    }
    free(graph->adjacency_matrix);
    free(graph);

    return 0;
}