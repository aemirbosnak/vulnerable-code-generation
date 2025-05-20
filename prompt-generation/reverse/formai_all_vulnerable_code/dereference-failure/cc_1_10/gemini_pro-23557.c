//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
    int v, w;    // To store the edge
} Edge;

typedef struct graph {
    int V, E;    // Number of vertices and edges
    Edge *edges;    // Array of edges
} Graph;

// Function to create a graph with V vertices and E edges
Graph *create_graph(int V, int E) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge *)malloc(E * sizeof(Edge));

    return graph;
}

// Function to add an edge to a graph
void add_edge(Graph *graph, int v, int w) {
    graph->edges[graph->E].v = v;
    graph->edges[graph->E].w = w;
    graph->E++;
}

// Function to print the graph
void print_graph(Graph *graph) {
    for (int i = 0; i < graph->E; i++) {
        printf("%d -> %d\n", graph->edges[i].v, graph->edges[i].w);
    }
}

int main() {
    // Create a graph with 4 vertices and 5 edges
    Graph *graph = create_graph(4, 5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);

    // Print the graph
    printf("The graph is:\n");
    print_graph(graph);

    return 0;
}