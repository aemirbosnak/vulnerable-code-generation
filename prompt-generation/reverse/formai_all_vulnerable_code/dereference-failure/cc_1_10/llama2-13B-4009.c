//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure definition
typedef struct {
    int num_vertices;
    int *edges;
} Graph;

// Function to create a new graph
Graph *new_graph(int n) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->num_vertices = n;
    g->edges = (int *)malloc(n * n * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(Graph *g, int v1, int v2) {
    g->edges[v1 * g->num_vertices + v2] = 1;
}

// Function to print the graph
void print_graph(Graph *g) {
    int i, j;
    for (i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d:", i);
        for (j = 0; j < g->num_vertices; j++) {
            if (g->edges[i * g->num_vertices + j] == 1) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph *g = new_graph(10);

    // Add some edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 5);
    add_edge(g, 4, 6);
    add_edge(g, 5, 7);
    add_edge(g, 6, 8);
    add_edge(g, 7, 9);

    // Print the graph
    print_graph(g);

    // Free the graph memory
    free(g->edges);
    free(g);

    return 0;
}