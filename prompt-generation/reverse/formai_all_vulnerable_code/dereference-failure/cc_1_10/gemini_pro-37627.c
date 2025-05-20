//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Graph data structure
typedef struct graph {
    int V;              // Number of vertices
    int E;              // Number of edges
    int **adj;          // Adjacency list
    int *color;         // Color of each vertex
} graph;

// Create a new graph
graph *create_graph(int V, int E) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->V = V;
    g->E = E;
    g->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        g->adj[i] = (int *)malloc(V * sizeof(int));
    }
    g->color = (int *)malloc(V * sizeof(int));
    return g;
}

// Free the memory allocated for the graph
void free_graph(graph *g) {
    for (int i = 0; i < g->V; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g->color);
    free(g);
}

// Add an edge to the graph
void add_edge(graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

// Print the adjacency list of the graph
void print_adj_list(graph *g) {
    for (int i = 0; i < g->V; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->V; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// Check if the graph is colorable with k colors
int is_colorable(graph *g, int k) {
    // Initialize the color of each vertex to -1
    for (int i = 0; i < g->V; i++) {
        g->color[i] = -1;
    }

    // Try to color the graph using k colors
    for (int i = 0; i < g->V; i++) {
        if (g->color[i] == -1) {
            if (!color_vertex(g, i, k)) {
                return 0;
            }
        }
    }

    // If the graph is colored successfully, return 1
    return 1;
}

// Color a vertex with a given color
int color_vertex(graph *g, int v, int k) {
    // Try all possible colors for the vertex
    for (int i = 0; i < k; i++) {
        // Check if the color is available for the vertex
        int available = 1;
        for (int j = 0; j < g->V; j++) {
            if (g->adj[v][j] && g->color[j] == i) {
                available = 0;
                break;
            }
        }

        // If the color is available, color the vertex and return
        if (available) {
            g->color[v] = i;
            return 1;
        }
    }

    // If no color is available, return 0
    return 0;
}

// Print the coloring of the graph
void print_coloring(graph *g) {
    for (int i = 0; i < g->V; i++) {
        printf("%d: %d\n", i, g->color[i]);
    }
}

int main() {
    // Create a graph
    graph *g = create_graph(5, 6);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);

    // Print the adjacency list of the graph
    print_adj_list(g);

    // Check if the graph is colorable with 3 colors
    int k = 3;
    int is_3_colorable = is_colorable(g, k);

    // Print the result
    if (is_3_colorable) {
        printf("The graph is colorable with %d colors.\n", k);
        print_coloring(g);
    } else {
        printf("The graph is not colorable with %d colors.\n", k);
    }

    // Free the memory allocated for the graph
    free_graph(g);

    return 0;
}