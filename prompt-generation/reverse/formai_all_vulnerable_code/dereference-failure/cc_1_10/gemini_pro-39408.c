//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// A graph is a collection of vertices and edges.
// A vertex is a point in space.
// An edge is a line segment that connects two vertices.
struct Graph {
    int V;  // Number of vertices
    int E;  // Number of edges
    int **adj;  // Adjacency matrix
};

// Create a new graph with V vertices and E edges.
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
    }
    return graph;
}

// Add an edge to the graph.
void addEdge(struct Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// Print the graph.
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Check if the graph is bipartite.
// A bipartite graph is a graph whose vertices can be divided into two disjoint sets such that no two vertices in the same set are adjacent.
int isBipartite(struct Graph* graph) {
    int color[graph->V];
    for (int i = 0; i < graph->V; i++) {
        color[i] = -1;
    }

    // Assign the first vertex a color.
    color[0] = 0;

    // Color the rest of the vertices.
    for (int i = 1; i < graph->V; i++) {
        // If the current vertex has already been colored, skip it.
        if (color[i] != -1) continue;

        // Otherwise, assign the current vertex a color different from its neighbors.
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[i][j] == 1 && color[i] == color[j]) {
                return 0;
            }
        }
        color[i] = 1 - color[i];
    }

    // If all vertices have been colored successfully, return 1.
    return 1;
}

// Main function.
int main() {
    // Create a graph.
    struct Graph* graph = createGraph(4, 4);

    // Add edges to the graph.
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Print the graph.
    printGraph(graph);

    // Check if the graph is bipartite.
    if (isBipartite(graph)) {
        printf("The graph is bipartite.\n");
    } else {
        printf("The graph is not bipartite.\n");
    }

    // Free the graph.
    for (int i = 0; i < graph->V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);

    return 0;
}