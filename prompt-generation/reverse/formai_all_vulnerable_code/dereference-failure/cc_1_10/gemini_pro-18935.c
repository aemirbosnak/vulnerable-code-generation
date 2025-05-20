//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// A graph is represented by an adjacency matrix.
typedef struct graph {
    int **adj;
    int n;
} graph;

// A coloring is represented by an array of colors.
typedef int *coloring;

// Create a new graph with n vertices.
graph *new_graph(int n) {
    graph *g = malloc(sizeof(graph));
    g->n = n;
    g->adj = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        g->adj[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            g->adj[i][j] = 0;
        }
    }
    return g;
}

// Free the memory allocated for a graph.
void free_graph(graph *g) {
    for (int i = 0; i < g->n; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

// Add an edge to a graph.
void add_edge(graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

// Print a graph.
void print_graph(graph *g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// Create a new coloring for a graph.
coloring new_coloring(graph *g) {
    coloring c = malloc(sizeof(int) * g->n);
    for (int i = 0; i < g->n; i++) {
        c[i] = -1;
    }
    return c;
}

// Free the memory allocated for a coloring.
void free_coloring(coloring c) {
    free(c);
}

// Color a graph using the greedy algorithm.
coloring greedy_color(graph *g) {
    coloring c = new_coloring(g);
    int colors = 0;
    for (int i = 0; i < g->n; i++) {
        if (c[i] == -1) {
            c[i] = colors++;
            for (int j = i + 1; j < g->n; j++) {
                if (g->adj[i][j] == 1) {
                    c[j] = -1;
                }
            }
        }
    }
    return c;
}

// Print a coloring.
void print_coloring(coloring c, graph *g) {
    for (int i = 0; i < g->n; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
}

// Main function.
int main() {
    // Create a new graph.
    graph *g = new_graph(5);

    // Add edges to the graph.
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    // Print the graph.
    printf("Graph:\n");
    print_graph(g);

    // Color the graph using the greedy algorithm.
    coloring c = greedy_color(g);

    // Print the coloring.
    printf("Coloring:\n");
    print_coloring(c, g);

    // Free the memory allocated for the graph and coloring.
    free_graph(g);
    free_coloring(c);

    return 0;
}