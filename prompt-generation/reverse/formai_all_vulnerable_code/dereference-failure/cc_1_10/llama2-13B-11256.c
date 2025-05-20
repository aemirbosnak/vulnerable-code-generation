//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdio.h>
#include <stdbool.h>

// Structure to represent a graph
typedef struct {
    int num_vertices;   // Number of vertices in the graph
    int **adjacency_matrix; // Adjacency matrix
} Graph;

// Function to create a new graph
Graph *create_graph(int num_vertices) {
    Graph *g = malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->adjacency_matrix = malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        g->adjacency_matrix[i] = malloc(num_vertices * sizeof(int));
    }
    return g;
}

// Function to add an edge to the graph
void add_edge(Graph *g, int v1, int v2) {
    g->adjacency_matrix[v1][v2] = 1;
}

// Function to print the graph
void print_graph(Graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d -> %d\n", i, j);
        }
    }
}

int main() {
    Graph *g = create_graph(5);

    // Add some edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    // Print the graph
    print_graph(g);

    // Free the graph memory
    free(g->adjacency_matrix[0]);
    free(g->adjacency_matrix);
    free(g);

    return 0;
}