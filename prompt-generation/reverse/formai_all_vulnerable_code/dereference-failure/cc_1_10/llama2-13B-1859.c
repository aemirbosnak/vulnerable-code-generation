//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure definition
struct Graph {
    int num_vertices;
    int *edges;
};

// Function to create a new graph
struct Graph *create_graph(int n) {
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    g->num_vertices = n;
    g->edges = (int *)malloc(n * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(struct Graph *g, int u, int v) {
    g->edges[u * g->num_vertices + v] = 1;
}

// Function to check if an edge exists
int has_edge(struct Graph *g, int u, int v) {
    return g->edges[u * g->num_vertices + v];
}

// Function to print the graph
void print_graph(struct Graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d:", i);
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->edges[i * g->num_vertices + j]) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
}

int main() {
    struct Graph *g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    print_graph(g);
    return 0;
}