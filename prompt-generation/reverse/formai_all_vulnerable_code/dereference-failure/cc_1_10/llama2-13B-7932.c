//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure to represent a graph
typedef struct {
    int num_vertices;
    int *adjacency_list;
} Graph;

// Function to create a new graph with the given number of vertices
Graph *new_graph(int num_vertices) {
    Graph *g = malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->adjacency_list = malloc(num_vertices * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(Graph *g, int v1, int v2) {
    g->adjacency_list[v1] = (g->adjacency_list[v1] ? : 0) | (1 << v2);
}

// Function to print the graph in a human-readable format
void print_graph(Graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < 32; j++) {
            if (g->adjacency_list[i] & (1 << j)) {
                printf("%d ", j);
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

    return 0;
}