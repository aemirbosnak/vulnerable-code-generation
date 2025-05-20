//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Graph structure
typedef struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    int **adj; // Adjacency list
} Graph;

// Create a new graph with V vertices and E edges
Graph *createGraph(int V, int E) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

// Add an edge between vertices u and v
void addEdge(Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// Print the graph
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Check if the graph is colored properly
int isProperlyColored(Graph *graph, int *colors) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = i + 1; j < graph->V; j++) {
            if (graph->adj[i][j] && colors[i] == colors[j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Color the graph using the greedy algorithm
void greedyColoring(Graph *graph, int *colors) {
    int availableColors[graph->V];
    for (int i = 0; i < graph->V; i++) {
        availableColors[i] = 1;
    }

    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[i][j]) {
                availableColors[colors[j]] = 0;
            }
        }

        int color;
        for (color = 1; color <= graph->V; color++) {
            if (availableColors[color]) {
                break;
            }
        }

        colors[i] = color;
        availableColors[color] = 0;
    }
}

// Main function
int main() {
    // Create a graph
    Graph *graph = createGraph(4, 3);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Color the graph
    int colors[graph->V];
    greedyColoring(graph, colors);

    // Print the graph
    printGraph(graph);

    // Check if the graph is colored properly
    if (isProperlyColored(graph, colors)) {
        printf("The graph is colored properly.\n");
    } else {
        printf("The graph is not colored properly.\n");
    }

    // Free the graph
    for (int i = 0; i < graph->V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);

    return 0;
}