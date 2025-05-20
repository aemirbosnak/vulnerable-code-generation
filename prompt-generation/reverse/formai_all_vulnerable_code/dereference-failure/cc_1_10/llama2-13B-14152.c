//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure definition
typedef struct {
    int vertices; // number of vertices
    int edges; // number of edges
    int *adjacency_list; // array of adjacency lists
} Graph;

// Function to create a new graph
Graph* new_graph(int v, int e) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->vertices = v;
    g->edges = e;
    g->adjacency_list = (int*) malloc(v * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(Graph* g, int v1, int v2) {
    g->adjacency_list[v1]++;
    g->adjacency_list[v2]++;
    g->edges++;
}

// Function to print the graph
void print_graph(Graph* g) {
    for (int i = 0; i < g->vertices; i++) {
        printf("Vertex %d has %d edges\n", i, g->adjacency_list[i]);
    }
}

int main() {
    Graph* g = new_graph(5, 10);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    // Print the graph
    print_graph(g);

    // Free the graph memory
    free(g->adjacency_list);
    free(g);

    return 0;
}