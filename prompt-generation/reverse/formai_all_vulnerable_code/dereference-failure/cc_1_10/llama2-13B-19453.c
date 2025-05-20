//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Definition of Graph structure
typedef struct {
    int num_vertices;    // Number of vertices in the graph
    int *edges;        // Array of edges (vertex1, vertex2)
} Graph;

// Function to create a new graph
Graph* new_graph(int num_vertices) {
    Graph* g = malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->edges = malloc(num_vertices * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(Graph* g, int vertex1, int vertex2) {
    g->edges[vertex1 * g->num_vertices + vertex2] = 1;
}

// Function to print the graph
void print_graph(Graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->edges[i * g->num_vertices + j]) {
                printf("(%d, %d)", i, j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph* g = new_graph(5);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    // Print the graph
    print_graph(g);

    // Free the graph memory
    free(g->edges);
    free(g);

    return 0;
}