//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 4
#define MAX_VERTICES 5

// A structure to represent the graph
struct graph {
    int V; // number of vertices
    int **adj; // 2d dynamic array to represent adjacency matrix
};

// Function to initialize a new graph with V vertices
struct graph *init_graph(int V) {
    struct graph *g = (struct graph *) malloc(sizeof(struct graph));
    g->V = V;
    g->adj = (int **) malloc(sizeof(int *) * V);
    for (int i = 0; i < V; ++i) {
        g->adj[i] = (int *) malloc(sizeof(int) * V);
        for (int j = 0; j < V; ++j) {
            g->adj[i][j] = 0;
        }
    }
    return g;
}

// Function to add an edge between two vertices
void add_edge(struct graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

// Function to print the graph
void print_graph(struct graph *g) {
    for (int i = 0; i < g->V; ++i) {
        for (int j = 0; j < g->V; ++j) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to check if it is safe to color a vertex with a certain color
int safe_to_color(struct graph *g, int vertex, int color, int *colors) {
    for (int i = 0; i < g->V; ++i) {
        if (g->adj[vertex][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the graph coloring problem recursively using backtracking
int graph_color(struct graph *g, int *colors, int vertex) {
    if (vertex == g->V) {
        return 1;
    }
    for (int i = 1; i <= MAX_COLORS; ++i) {
        if (safe_to_color(g, vertex, i, colors)) {
            colors[vertex] = i;
            if (graph_color(g, colors, vertex + 1)) {
                return 1;
            }
            colors[vertex] = 0;
        }
    }
    return 0;
}

int main() {
    // Initialize the graph
    struct graph *g = init_graph(MAX_VERTICES);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 4);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    // Print the graph
    printf("Graph:\n");
    print_graph(g);

    // Initialize the color array with zeros
    int colors[MAX_VERTICES] = {0};

    // Solve the graph coloring problem
    if (graph_color(g, colors, 0)) {
        printf("The graph can be colored using at most %d colors.\n", MAX_COLORS);
        printf("Colors of vertices:\n");
        for (int i = 0; i < g->V; ++i) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("The graph cannot be colored using at most %d colors.\n", MAX_COLORS);
    }

    // Free the graph
    for (int i = 0; i < g->V; ++i) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);

    return 0;
}