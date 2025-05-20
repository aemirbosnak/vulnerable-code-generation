//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Graph structure
typedef struct {
    int num_vertices;    // Number of vertices
    int *adjacency_list; // Adjacency list
} Graph;

// Function to create a new graph
Graph* new_graph(int num_vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->adjacency_list = (int*)malloc(num_vertices * sizeof(int));
    return g;
}

// Function to add a vertex to the graph
void add_vertex(Graph* g, int vertex) {
    g->adjacency_list[g->num_vertices] = vertex;
    g->num_vertices++;
}

// Function to add an edge to the graph
void add_edge(Graph* g, int vertex1, int vertex2) {
    g->adjacency_list[vertex1] = vertex2;
}

// Function to print the graph
void print_graph(Graph* g) {
    int i, j;
    for (i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d:", i);
        for (j = 0; j < g->adjacency_list[i]; j++) {
            printf(" %d", g->adjacency_list[i * g->num_vertices + j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* g = new_graph(5);

    // Add some vertices and edges
    add_vertex(g, 1);
    add_vertex(g, 2);
    add_vertex(g, 3);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 1, 3);

    // Print the graph
    print_graph(g);

    // Free the graph memory
    free(g->adjacency_list);
    free(g);

    return 0;
}