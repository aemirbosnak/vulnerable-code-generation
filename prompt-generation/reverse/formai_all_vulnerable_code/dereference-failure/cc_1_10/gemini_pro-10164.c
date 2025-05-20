//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Graph data structure
typedef struct Graph {
    int vertices;    // Number of vertices
    int edges;      // Number of edges
    int **adj;      // Adjacency matrix
} Graph;

// Create a new graph
Graph * create_graph(int vertices, int edges) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    graph->adj = (int **) malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adj[i] = (int *) malloc(vertices * sizeof(int));
    }
    return graph;
}

// Free the memory allocated for the graph
void free_graph(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);
}

// Add an edge to the graph
void add_edge(Graph *graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;
}

// Print the graph
void print_graph(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Check if the graph is bipartite
int is_bipartite(Graph *graph) {
    int *colors = (int *) malloc(graph->vertices * sizeof(int));

    // Initialize all vertices as uncolored
    for (int i = 0; i < graph->vertices; i++) {
        colors[i] = -1;
    }

    // Assign colors to the vertices
    int color = 0;
    for (int i = 0; i < graph->vertices; i++) {
        if (colors[i] == -1) {
            if (!assign_color(graph, i, color, colors)) {
                return 0;
            }
            color++;
        }
    }

    free(colors);
    return 1;
}

// Assign a color to a vertex
int assign_color(Graph *graph, int vertex, int color, int *colors) {
    if (colors[vertex] != -1) {
        return colors[vertex] == color;
    }

    colors[vertex] = color;

    // Check if the adjacent vertices have the same color
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj[vertex][i] == 1 && !assign_color(graph, i, 1 - color, colors)) {
            return 0;
        }
    }

    return 1;
}

// Main function
int main() {
    // Create a graph
    Graph *graph = create_graph(4, 3);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);

    // Print the graph
    print_graph(graph);

    // Check if the graph is bipartite
    if (is_bipartite(graph)) {
        printf("The graph is bipartite.\n");
    } else {
        printf("The graph is not bipartite.\n");
    }

    // Free the memory allocated for the graph
    free_graph(graph);

    return 0;
}