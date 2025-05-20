//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Graph data structure
typedef struct graph {
    int V;              // Number of vertices
    int E;              // Number of edges
    int **adj;          // Adjacency matrix
} graph;

// Create a new graph
graph *create_graph(int V) {
    graph *g = malloc(sizeof(graph));
    g->V = V;
    g->E = 0;
    g->adj = malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        g->adj[i] = malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }
    return g;
}

// Add an edge to the graph
void add_edge(graph *g, int u, int v, int weight) {
    g->adj[u][v] = weight;
    g->adj[v][u] = weight;
    g->E++;
}

// Print the adjacency matrix of the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// Free the memory allocated to the graph
void free_graph(graph *g) {
    for (int i = 0; i < g->V; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

// Main function
int main() {
    // Create a new graph
    graph *g = create_graph(5);

    // Add edges to the graph
    add_edge(g, 0, 1, 1);
    add_edge(g, 0, 2, 2);
    add_edge(g, 1, 2, 3);
    add_edge(g, 1, 3, 4);
    add_edge(g, 2, 3, 5);
    add_edge(g, 3, 4, 6);

    // Print the adjacency matrix of the graph
    printf("Adjacency matrix:\n");
    print_graph(g);

    // Free the memory allocated to the graph
    free_graph(g);

    return 0;
}