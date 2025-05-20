//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A graph is represented as an adjacency list. Each node in the graph is
// represented by an integer, and each edge is represented by a pair of integers.
typedef struct edge {
    int source;
    int destination;
} edge;

// A graph is represented as an array of adjacency lists.
typedef struct graph {
    int num_nodes;
    int num_edges;
    edge* edges;
} graph;

// A coloring of a graph is represented as an array of integers. Each integer
// in the array represents the color of the corresponding node in the graph.
typedef struct coloring {
    int num_nodes;
    int* colors;
} coloring;

// Create a new graph with the specified number of nodes and edges.
graph* create_graph(int num_nodes, int num_edges) {
    graph* g = malloc(sizeof(graph));
    g->num_nodes = num_nodes;
    g->num_edges = num_edges;
    g->edges = malloc(sizeof(edge) * num_edges);
    return g;
}

// Add an edge to a graph.
void add_edge(graph* g, int source, int destination) {
    edge* e = &g->edges[g->num_edges++];
    e->source = source;
    e->destination = destination;
}

// Create a new coloring for a graph.
coloring* create_coloring(graph* g) {
    coloring* c = malloc(sizeof(coloring));
    c->num_nodes = g->num_nodes;
    c->colors = malloc(sizeof(int) * g->num_nodes);
    return c;
}

// Color a graph using the specified coloring.
void color_graph(graph* g, coloring* c) {
    for (int i = 0; i < g->num_nodes; i++) {
        c->colors[i] = rand() % 10 + 1;
    }
}

// Check if a graph is properly colored.
bool is_properly_colored(graph* g, coloring* c) {
    for (int i = 0; i < g->num_edges; i++) {
        edge* e = &g->edges[i];
        if (c->colors[e->source] == c->colors[e->destination]) {
            return false;
        }
    }
    return true;
}

// Print a graph.
void print_graph(graph* g) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < g->num_edges; j++) {
            edge* e = &g->edges[j];
            if (e->source == i) {
                printf("%d ", e->destination);
            }
        }
        printf("\n");
    }
}

// Print a coloring.
void print_coloring(coloring* c) {
    for (int i = 0; i < c->num_nodes; i++) {
        printf("Node %d: %d\n", i, c->colors[i]);
    }
}

// Free the memory allocated for a graph.
void free_graph(graph* g) {
    free(g->edges);
    free(g);
}

// Free the memory allocated for a coloring.
void free_coloring(coloring* c) {
    free(c->colors);
    free(c);
}

// Main function.
int main() {
    // Create a graph.
    graph* g = create_graph(4, 5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);

    // Print the graph.
    print_graph(g);

    // Create a coloring for the graph.
    coloring* c = create_coloring(g);

    // Color the graph.
    color_graph(g, c);

    // Print the coloring.
    print_coloring(c);

    // Check if the graph is properly colored.
    if (is_properly_colored(g, c)) {
        printf("The graph is properly colored.\n");
    } else {
        printf("The graph is not properly colored.\n");
    }

    // Free the memory allocated for the graph and the coloring.
    free_graph(g);
    free_coloring(c);

    return 0;
}