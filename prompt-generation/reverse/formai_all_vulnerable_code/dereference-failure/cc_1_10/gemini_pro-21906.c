//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Graph coloring problem
// Given a graph with n vertices and m edges, find a way to color each vertex with one of k colors such that no two adjacent vertices have the same color.

// Graph represented as an adjacency list
typedef struct node {
    int vertex;
    struct node *next;
} node;

typedef struct graph {
    int n;  // number of vertices
    int m;  // number of edges
    node **adj;  // adjacency list
} graph;

// Function to create a new graph
graph *create_graph(int n, int m) {
    graph *g = malloc(sizeof(graph));
    g->n = n;
    g->m = m;
    g->adj = malloc(n * sizeof(node *));
    for (int i = 0; i < n; i++) {
        g->adj[i] = NULL;
    }
    return g;
}

// Function to add an edge to the graph
void add_edge(graph *g, int u, int v) {
    node *new_node = malloc(sizeof(node));
    new_node->vertex = v;
    new_node->next = g->adj[u];
    g->adj[u] = new_node;
}

// Function to print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->n; i++) {
        node *current = g->adj[i];
        printf("%d: ", i);
        while (current != NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

// Function to check if the graph is colorable
int is_colorable(graph *g, int k) {
    // Initialize the colors of the vertices to -1
    int *color = malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++) {
        color[i] = -1;
    }

    // Try to color the graph using k colors
    for (int i = 0; i < g->n; i++) {
        if (color[i] == -1) {
            if (!color_graph(g, i, k, color)) {
                return 0;  // Graph is not colorable
            }
        }
    }

    // Graph is colorable
    return 1;
}

// Function to color the graph using k colors
int color_graph(graph *g, int v, int k, int *color) {
    // Mark the current vertex as visited
    color[v] = 1;

    // Try all possible colors for the current vertex
    for (int c = 1; c <= k; c++) {
        // Check if the current color is valid for the current vertex
        if (is_valid_color(g, v, c, color)) {
            // Color the current vertex with the current color
            color[v] = c;

            // Recursively color the remaining vertices
            if (color_graph(g, v, k, color)) {
                return 1;  // Graph is colored
            } else {
                // Backtrack and try a different color
                color[v] = -1;
            }
        }
    }

    // No valid color found for the current vertex
    return 0;  // Graph is not colorable
}

// Function to check if the current color is valid for the current vertex
int is_valid_color(graph *g, int v, int c, int *color) {
    // Check if any adjacent vertex is colored with the current color
    node *current = g->adj[v];
    while (current != NULL) {
        if (color[current->vertex] == c) {
            return 0;  // Color is not valid
        }
        current = current->next;
    }

    // Color is valid
    return 1;
}

// Main function
int main() {
    // Create a graph
    graph *g = create_graph(4, 5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);

    // Print the graph
    print_graph(g);

    // Check if the graph is colorable
    int k = 3;
    if (is_colorable(g, k)) {
        printf("Graph is colorable with %d colors.\n", k);
    } else {
        printf("Graph is not colorable with %d colors.\n", k);
    }

    return 0;
}