//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// A graph is represented as an adjacency list.
// Each node in the graph is represented by an integer, and each edge is represented by a pair of integers.
typedef struct edge {
    int u;
    int v;
} edge;

// A graph is represented as an array of adjacency lists.
typedef struct graph {
    int num_nodes;
    int num_edges;
    edge *edges;
} graph;

// A coloring is represented as an array of integers, where each integer represents the color of the corresponding node.
typedef struct coloring {
    int num_nodes;
    int *colors;
} coloring;

// Create a new graph.
graph *create_graph(int num_nodes, int num_edges) {
    graph *g = malloc(sizeof(graph));
    g->num_nodes = num_nodes;
    g->num_edges = num_edges;
    g->edges = malloc(num_edges * sizeof(edge));
    return g;
}

// Add an edge to a graph.
void add_edge(graph *g, int u, int v) {
    g->edges[g->num_edges].u = u;
    g->edges[g->num_edges].v = v;
    g->num_edges++;
}

// Create a new coloring.
coloring *create_coloring(int num_nodes) {
    coloring *c = malloc(sizeof(coloring));
    c->num_nodes = num_nodes;
    c->colors = malloc(num_nodes * sizeof(int));
    return c;
}

// Color a graph.
void color_graph(graph *g, coloring *c) {
    // Initialize the colors of all nodes to 0.
    for (int i = 0; i < g->num_nodes; i++) {
        c->colors[i] = 0;
    }

    // Iterate over all nodes in the graph.
    for (int i = 0; i < g->num_nodes; i++) {
        // If the current node is not colored, then color it.
        if (c->colors[i] == 0) {
            // Get the set of colors that are not used by the neighbors of the current node.
            int used_colors[g->num_nodes];
            for (int j = 0; j < g->num_nodes; j++) {
                used_colors[j] = 0;
            }
            for (int j = 0; j < g->num_edges; j++) {
                if (g->edges[j].u == i) {
                    used_colors[c->colors[g->edges[j].v]] = 1;
                } else if (g->edges[j].v == i) {
                    used_colors[c->colors[g->edges[j].u]] = 1;
                }
            }

            // Find the first unused color.
            int color = 1;
            while (used_colors[color] == 1) {
                color++;
            }

            // Color the current node with the first unused color.
            c->colors[i] = color;
        }
    }
}

// Print a coloring.
void print_coloring(coloring *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d: color %d\n", i, c->colors[i]);
    }
}

// Free the memory used by a graph.
void free_graph(graph *g) {
    free(g->edges);
    free(g);
}

// Free the memory used by a coloring.
void free_coloring(coloring *c) {
    free(c->colors);
    free(c);
}

// Main function.
int main() {
    // Create a graph.
    graph *g = create_graph(5, 4);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    // Create a coloring.
    coloring *c = create_coloring(5);

    // Color the graph.
    color_graph(g, c);

    // Print the coloring.
    print_coloring(c);

    // Free the memory used by the graph and the coloring.
    free_graph(g);
    free_coloring(c);

    return 0;
}