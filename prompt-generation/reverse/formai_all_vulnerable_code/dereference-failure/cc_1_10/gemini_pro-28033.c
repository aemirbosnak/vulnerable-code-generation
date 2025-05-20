//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// A graph is a collection of vertices and edges.
// A vertex is a point in space.
// An edge is a line connecting two vertices.
typedef struct graph {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} graph;

// A coloring of a graph is an assignment of colors to the vertices such that no two adjacent vertices have the same color.
typedef struct coloring {
    int *colors;
} coloring;

// Create a new graph with the given number of vertices and edges.
graph *create_graph(int num_vertices, int num_edges) {
    graph *g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = num_edges;
    g->adj_matrix = malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        g->adj_matrix[i] = malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
    return g;
}

// Add an edge to the graph.
void add_edge(graph *g, int v1, int v2) {
    g->adj_matrix[v1][v2] = 1;
    g->adj_matrix[v2][v1] = 1;
}

// Create a new coloring for the given graph.
coloring *create_coloring(graph *g) {
    coloring *c = malloc(sizeof(coloring));
    c->colors = malloc(g->num_vertices * sizeof(int));
    for (int i = 0; i < g->num_vertices; i++) {
        c->colors[i] = -1;
    }
    return c;
}

// Color the graph using the given coloring.
void color_graph(graph *g, coloring *c) {
    for (int i = 0; i < g->num_vertices; i++) {
        // Get the color of the current vertex.
        int color = c->colors[i];
        // Loop through the adjacent vertices.
        for (int j = 0; j < g->num_vertices; j++) {
            // If the adjacent vertex has the same color, then the coloring is invalid.
            if (g->adj_matrix[i][j] == 1 && c->colors[j] == color) {
                printf("The coloring is invalid.\n");
                return;
            }
        }
    }
    // The coloring is valid.
    printf("The coloring is valid.\n");
}

// Free the memory used by the graph.
void free_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        free(g->adj_matrix[i]);
    }
    free(g->adj_matrix);
    free(g);
}

// Free the memory used by the coloring.
void free_coloring(coloring *c) {
    free(c->colors);
    free(c);
}

// Main function.
int main() {
    // Create a new graph.
    graph *g = create_graph(4, 3);
    // Add edges to the graph.
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    // Create a new coloring for the graph.
    coloring *c = create_coloring(g);
    // Color the graph using the given coloring.
    color_graph(g, c);
    // Free the memory used by the graph and the coloring.
    free_graph(g);
    free_coloring(c);
    return 0;
}