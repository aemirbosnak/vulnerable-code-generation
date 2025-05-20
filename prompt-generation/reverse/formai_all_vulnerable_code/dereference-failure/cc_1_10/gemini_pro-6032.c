//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// A struct to represent an edge in a graph
typedef struct edge {
    int source;
    int destination;
    int weight;
} edge;

// A struct to represent a graph
typedef struct graph {
    int num_vertices;
    int num_edges;
    edge *edges;
} graph;

// Create a new graph with the given number of vertices and edges
graph *create_graph(int num_vertices, int num_edges) {
    graph *g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = num_edges;
    g->edges = malloc(sizeof(edge) * num_edges);
    return g;
}

// Add an edge to the graph
void add_edge(graph *g, int source, int destination, int weight) {
    g->edges[g->num_edges].source = source;
    g->edges[g->num_edges].destination = destination;
    g->edges[g->num_edges].weight = weight;
    g->num_edges++;
}

// Print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->num_edges; i++) {
        printf("%d %d %d\n", g->edges[i].source, g->edges[i].destination, g->edges[i].weight);
    }
}

// Free the graph
void free_graph(graph *g) {
    free(g->edges);
    free(g);
}

int main() {
    // Create a new graph with 5 vertices and 7 edges
    graph *g = create_graph(5, 7);

    // Add edges to the graph
    add_edge(g, 0, 1, 10);
    add_edge(g, 0, 2, 20);
    add_edge(g, 1, 2, 30);
    add_edge(g, 1, 3, 40);
    add_edge(g, 2, 3, 50);
    add_edge(g, 3, 4, 60);
    add_edge(g, 4, 0, 70);

    // Print the graph
    print_graph(g);

    // Free the graph
    free_graph(g);

    return 0;
}