//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int num_vertices;
    int **adjacency_matrix;
};

// Function to create a graph
struct Graph* create_graph(int num_vertices) {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->num_vertices = num_vertices;
    g->adjacency_matrix = malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        g->adjacency_matrix[i] = malloc(num_vertices * sizeof(int));
    }
    return g;
}

// Function to add an edge to the graph
void add_edge(struct Graph* g, int v1, int v2) {
    g->adjacency_matrix[v1][v2] = 1;
}

// Function to print the graph
void print_graph(struct Graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph* g = create_graph(5);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    // Print the graph
    print_graph(g);

    return 0;
}