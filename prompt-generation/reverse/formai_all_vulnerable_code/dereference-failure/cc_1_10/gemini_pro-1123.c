//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A graph is a collection of vertices and edges.
typedef struct graph {
    int V;      // Number of vertices
    int E;      // Number of edges
    int **adj;  // Adjacency matrix
} graph;

// Create a new graph with V vertices.
graph *create_graph(int V) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->V = V;
    g->E = 0;
    g->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        g->adj[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }
    return g;
}

// Add an edge between vertices u and v.
void add_edge(graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
    g->E++;
}

// Check if the graph is colorable with k colors.
int is_colorable(graph *g, int k) {
    // Create a vector to store the colors of the vertices.
    int *colors = (int *)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++) {
        colors[i] = -1;
    }

    // Initialize the colors of the vertices.
    for (int i = 0; i < g->V; i++) {
        if (colors[i] == -1) {
            if (!color_vertex(g, i, k, colors)) {
                return 0;
            }
        }
    }

    // Free the vector.
    free(colors);

    // The graph is colorable.
    return 1;
}

// Color the vertex v with color c.
int color_vertex(graph *g, int v, int c, int *colors) {
    // Check if the vertex is already colored.
    if (colors[v] != -1) {
        return 1;
    }

    // Check if the vertex can be colored with color c.
    for (int i = 0; i < g->V; i++) {
        if (g->adj[v][i] == 1 && colors[i] == c) {
            return 0;
        }
    }

    // Color the vertex with color c.
    colors[v] = c;

    // Return 1.
    return 1;
}

// Print the graph.
void print_graph(graph *g) {
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// Free the graph.
void free_graph(graph *g) {
    for (int i = 0; i < g->V; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

int main() {
    // Create a graph.
    graph *g = create_graph(5);

    // Add edges to the graph.
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    // Print the graph.
    print_graph(g);

    // Check if the graph is colorable with 3 colors.
    int k = 3;
    int colorable = is_colorable(g, k);

    // Print the result.
    if (colorable) {
        printf("The graph is colorable with %d colors.\n", k);
    } else {
        printf("The graph is not colorable with %d colors.\n", k);
    }

    // Free the graph.
    free_graph(g);

    return 0;
}