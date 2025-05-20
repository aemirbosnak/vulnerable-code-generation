//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the graph structure
typedef struct {
    int num_vertices;
    int *edges;
} Graph;

// Define a function to create a new graph
Graph *new_graph(int num_vertices) {
    Graph *g = (Graph *) malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->edges = (int *) malloc(num_vertices * sizeof(int));
    return g;
}

// Define a function to add an edge to the graph
void add_edge(Graph *g, int v1, int v2) {
    g->edges[v1]++;
    g->edges[v2]++;
    g->edges[v1] = g->edges[v1] + g->edges[v2];
}

// Define a function to print the graph
void print_graph(Graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d: %d\n", i, g->edges[i]);
    }
}

int main() {
    // Create a new graph with 5 vertices
    Graph *g = new_graph(5);

    // Add some edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);

    // Print the graph
    print_graph(g);

    // Free the graph memory
    free(g->edges);
    free(g);

    return 0;
}