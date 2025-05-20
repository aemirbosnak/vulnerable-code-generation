//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Graph structure definition
typedef struct {
    int num_vertices;  // Number of vertices in the graph
    int *adjacency_list;  // Adjacency list for each vertex
} Graph;

// Function to create an empty graph
Graph *new_graph(int num_vertices) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->adjacency_list = (int *)malloc(num_vertices * sizeof(int));
    return g;
}

// Function to add a vertex to the graph
void add_vertex(Graph *g, int vertex) {
    g->num_vertices++;
    g->adjacency_list = (int *)realloc(g->adjacency_list, g->num_vertices * sizeof(int));
    g->adjacency_list[vertex] = 0; // Initialize as unvisited
}

// Function to add an edge to the graph
void add_edge(Graph *g, int vertex1, int vertex2) {
    g->adjacency_list[vertex1] |= (1 << vertex2); // Add edge from vertex1 to vertex2
}

// Function to print the graph
void print_graph(Graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d:", i);
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->adjacency_list[i] & (1 << j)) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph *g = new_graph(10);

    // Add some vertices and edges
    add_vertex(g, 0);
    add_vertex(g, 1);
    add_vertex(g, 2);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);

    // Print the graph
    print_graph(g);

    // Free the graph memory
    free(g->adjacency_list);
    free(g);

    return 0;
}