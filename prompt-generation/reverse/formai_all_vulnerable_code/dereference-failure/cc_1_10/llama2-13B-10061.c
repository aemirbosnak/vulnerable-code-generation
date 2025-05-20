//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: mathematical
// Graph representation using adjacency matrix

#include <stdio.h>
#include <stdlib.h>

// Graph structure
typedef struct {
    int num_vertices;  // Number of vertices in the graph
    int *adjacency_matrix;  // Adjacency matrix representing the graph
} graph_t;

// Function to create an empty graph
graph_t *new_graph(int num_vertices) {
    graph_t *g = (graph_t *) malloc(sizeof(graph_t));
    g->num_vertices = num_vertices;
    g->adjacency_matrix = (int *) malloc(num_vertices * num_vertices * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(graph_t *g, int v1, int v2) {
    g->adjacency_matrix[v1 * g->num_vertices + v2] = 1;
}

// Function to check if there is an edge between two vertices
int has_edge(graph_t *g, int v1, int v2) {
    return g->adjacency_matrix[v1 * g->num_vertices + v2];
}

// Function to print the graph
void print_graph(graph_t *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->adjacency_matrix[i * g->num_vertices + j] == 1) {
                printf("%d -> %d", i, j);
            }
        }
        printf("\n");
    }
}

int main() {
    graph_t *g = new_graph(5);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    // Check if there is an edge between two vertices
    if (has_edge(g, 0, 3)) {
        printf("There is an edge between 0 and 3.\n");
    } else {
        printf("There is no edge between 0 and 3.\n");
    }

    // Print the graph
    print_graph(g);

    return 0;
}