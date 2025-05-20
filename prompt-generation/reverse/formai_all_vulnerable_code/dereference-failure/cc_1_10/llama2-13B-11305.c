//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the graph structure
typedef struct {
    int num_vertices;
    int *edges;
} graph_t;

// Define a function to create a new graph
graph_t *new_graph(int n) {
    graph_t *g = (graph_t *) malloc(sizeof(graph_t));
    g->num_vertices = n;
    g->edges = (int *) malloc(n * n * sizeof(int));
    return g;
}

// Define a function to add an edge to the graph
void add_edge(graph_t *g, int v1, int v2) {
    g->edges[v1 * g->num_vertices + v2] = 1;
}

// Define a function to check if there is an edge between two vertices
int has_edge(graph_t *g, int v1, int v2) {
    return g->edges[v1 * g->num_vertices + v2];
}

// Define a function to print the graph
void print_graph(graph_t *g) {
    int i, j;
    for (i = 0; i < g->num_vertices; i++) {
        for (j = 0; j < g->num_vertices; j++) {
            if (g->edges[i * g->num_vertices + j]) {
                printf("(%d, %d)", i, j);
            }
        }
        printf("\n");
    }
}

// Define the main function
int main() {
    graph_t *g = new_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);
    print_graph(g);
    return 0;
}