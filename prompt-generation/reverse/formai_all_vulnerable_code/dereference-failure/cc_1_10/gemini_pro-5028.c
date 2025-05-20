//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Graph representation
typedef struct graph {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} graph;

// Graph creation
graph *create_graph(int num_vertices) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = 0;
    g->adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        g->adj_matrix[i] = (int *)malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
    return g;
}

// Graph edge addition
void add_edge(graph *g, int u, int v) {
    g->adj_matrix[u][v] = 1;
    g->adj_matrix[v][u] = 1;
    g->num_edges++;
}

// Graph printing
void print_graph(graph *g) {
    printf("Graph with %d vertices and %d edges:\n", g->num_vertices, g->num_edges);
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create a graph with 5 vertices
    graph *g = create_graph(5);
  
    // Add some edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 4, 0);

    // Print the graph
    print_graph(g);

    return 0;
}