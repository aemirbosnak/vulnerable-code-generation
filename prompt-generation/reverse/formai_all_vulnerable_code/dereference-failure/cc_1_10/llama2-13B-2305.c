//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the graph structure
typedef struct {
    int num_vertices;   // Number of vertices in the graph
    int *adjacency_list; // Adjacency list for each vertex
} Graph;

// Function to create a new graph
Graph* create_graph(int num_vertices) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->adjacency_list = (int*) malloc(num_vertices * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(Graph* g, int v1, int v2) {
    g->adjacency_list[v1] = g->adjacency_list[v1] ? g->adjacency_list[v1] : 0;
    g->adjacency_list[v1] |= (1 << v2);
}

// Function to traverse the graph
void traverse(Graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        if (g->adjacency_list[i] & (1 << i)) {
            printf("Vertex %d has edge to itself and vertices %d and %d\n", i, (int) (g->adjacency_list[i] & (1 << i)), (int) (g->adjacency_list[i] & (1 << (i + 1))));
        }
    }
}

int main() {
    Graph* g = create_graph(5);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    // Traverse the graph
    traverse(g);

    // Free the graph memory
    free(g->adjacency_list);
    free(g);

    return 0;
}