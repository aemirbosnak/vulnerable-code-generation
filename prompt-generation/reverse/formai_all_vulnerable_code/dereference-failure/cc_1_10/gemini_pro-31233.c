//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include <stdlib.h>
#include <stdio.h>

// A graph is a data structure that consists of a finite set of vertices and a set of edges
// that connect these vertices.
typedef struct graph {
    int num_vertices;  // The number of vertices in the graph
    int** adj_matrix;  // The adjacency matrix representing the graph
} graph;

// Creates a new graph with the given number of vertices.
graph* create_graph(int num_vertices) {
    graph* g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->adj_matrix = malloc(sizeof(int*) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        g->adj_matrix[i] = malloc(sizeof(int) * num_vertices);
        for (int j = 0; j < num_vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
    return g;
}

// Adds an edge between two vertices in the graph.
void add_edge(graph* g, int vertex1, int vertex2) {
    g->adj_matrix[vertex1][vertex2] = 1;
    g->adj_matrix[vertex2][vertex1] = 1;
}

// Removes an edge between two vertices in the graph.
void remove_edge(graph* g, int vertex1, int vertex2) {
    g->adj_matrix[vertex1][vertex2] = 0;
    g->adj_matrix[vertex2][vertex1] = 0;
}

// Prints the adjacency matrix of the graph.
void print_adj_matrix(graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Frees the memory allocated for the graph.
void free_graph(graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        free(g->adj_matrix[i]);
    }
    free(g->adj_matrix);
    free(g);
}

// A driver function to test the graph representation.
int main() {
    // Creates a graph with 5 vertices.
    graph* g = create_graph(5);

    // Adds edges to the graph.
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    // Prints the adjacency matrix of the graph.
    print_adj_matrix(g);

    // Frees the memory allocated for the graph.
    free_graph(g);

    return 0;
}