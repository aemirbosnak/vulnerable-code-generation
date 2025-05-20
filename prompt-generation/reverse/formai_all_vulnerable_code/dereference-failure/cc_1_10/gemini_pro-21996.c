//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COLORS 100

// Graph structure
typedef struct graph {
    int V;              // Number of vertices
    int E;              // Number of edges
    int **adj;          // Adjacency matrix
    int *color;         // Color of each vertex
} graph;

// Function to create a new graph
graph *create_graph(int V, int E) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->V = V;
    g->E = E;

    // Allocate memory for adjacency matrix
    g->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        g->adj[i] = (int *)malloc(V * sizeof(int));
    }

    // Initialize adjacency matrix to 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }

    // Allocate memory for color array
    g->color = (int *)malloc(V * sizeof(int));

    // Initialize color array to -1
    for (int i = 0; i < V; i++) {
        g->color[i] = -1;
    }

    return g;
}

// Function to add an edge to the graph
void add_edge(graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

// Function to print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the graph is colorable
int is_colorable(graph *g) {
    // Initialize color array to all 0
    for (int i = 0; i < g->V; i++) {
        g->color[i] = 0;
    }

    // Iterate over each vertex
    for (int v = 0; v < g->V; v++) {
        // If the vertex is not yet colored
        if (g->color[v] == 0) {
            // Try all possible colors
            for (int c = 1; c <= MAX_COLORS; c++) {
                // If the color is valid
                if (is_safe(g, v, c)) {
                    // Color the vertex
                    g->color[v] = c;

                    // Recursively check the remaining vertices
                    if (is_colorable(g)) {
                        return 1;
                    }

                    // If the remaining vertices are not colorable, reset the color of the current vertex
                    g->color[v] = 0;
                }
            }

            // If no valid color found for the current vertex, then the graph is not colorable
            return 0;
        }
    }

    // If all vertices are colored, then the graph is colorable
    return 1;
}

// Function to check if the color is valid for the vertex
int is_safe(graph *g, int v, int c) {
    // Iterate over all the neighbors of the vertex
    for (int i = 0; i < g->V; i++) {
        // If the neighbor is adjacent and has the same color
        if (g->adj[v][i] == 1 && g->color[i] == c) {
            return 0;
        }
    }

    // If no neighbor has the same color, then the color is valid
    return 1;
}

// Main function
int main() {
    // Create a graph
    graph *g = create_graph(4, 3);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);

    // Print the graph
    print_graph(g);

    // Check if the graph is colorable
    int colorable = is_colorable(g);

    if (colorable) {
        printf("The graph is colorable\n");
    } else {
        printf("The graph is not colorable\n");
    }

    return 0;
}