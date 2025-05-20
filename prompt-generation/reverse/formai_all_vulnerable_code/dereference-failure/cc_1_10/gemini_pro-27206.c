//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Graph structure
typedef struct graph {
    int V;          // Number of vertices
    int E;          // Number of edges
    int **adj;      // Adjacency matrix
} graph;

// Create a new graph with V vertices and E edges
graph *create_graph(int V, int E) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->V = V;
    g->E = E;
    g->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        g->adj[i] = (int *)malloc(V * sizeof(int));
    }
    return g;
}

// Free the memory allocated for the graph
void free_graph(graph *g) {
    for (int i = 0; i < g->V; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

// Add an edge to the graph
void add_edge(graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

// Print the adjacency matrix of the graph
void print_adj_matrix(graph *g) {
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// Color the graph using the greedy algorithm
int *greedy_coloring(graph *g) {
    int *color = (int *)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++) {
        color[i] = -1;
    }
    int available[g->V];
    for (int i = 0; i < g->V; i++) {
        available[i] = 1;
    }
    int min_color = 0;
    for (int i = 0; i < g->V; i++) {
        if (color[i] == -1) {
            for (int j = 0; j < g->V; j++) {
                if (g->adj[i][j] == 1 && color[j] == min_color) {
                    available[min_color] = 0;
                }
            }
            int j;
            for (j = 0; j < g->V; j++) {
                if (available[j]) {
                    break;
                }
            }
            color[i] = j;
            min_color = (min_color + 1) % g->V;
        }
    }
    return color;
}

// Print the coloring of the graph
void print_coloring(int *color, int V) {
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

// Main function
int main() {
    // Create a graph with 4 vertices and 5 edges
    graph *g = create_graph(4, 5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 0);

    // Print the adjacency matrix of the graph
    printf("Adjacency matrix:\n");
    print_adj_matrix(g);

    // Color the graph using the greedy algorithm
    int *color = greedy_coloring(g);

    // Print the coloring of the graph
    printf("Greedy coloring:\n");
    print_coloring(color, g->V);

    // Free the memory allocated for the graph
    free_graph(g);

    return 0;
}