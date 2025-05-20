//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PARTNERS 10  // Maximum number of partners at the gathering

// Structure to represent a graph
struct Graph {
    int V;  // Number of vertices (partners)
    int **adj; // Adjacency matrix
};

// Function to create an adjacency matrix for the graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = vertices;
    graph->adj = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adj[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0;  // Initialize with no edges
        }
    }
    return graph;
}

// Function to add an edge between two partners
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // Since it's an undirected graph
}

// Function to check if the color assignment is safe
bool isSafe(int v, struct Graph* graph, int *color, int c) {
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the coloring problem
bool graphColoringUtil(struct Graph* graph, int m, int *color, int v) {
    if (v == graph->V) {
        return true; // All vertices are assigned a color
    }
    
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // Assign color c
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }
            color[v] = 0; // Backtrack
        }
    }
    
    return false;
}

// Function to solve the graph coloring problem
bool graphColoring(struct Graph* graph, int m) {
    int *color = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        color[i] = 0; // Initialize with 0 (no color)
    }

    if (graphColoringUtil(graph, m, color, 0) == false) {
        printf("It's not possible to assign colors to the partners with %d colors.\n", m);
        return false;
    }

    printf("Coloring of partners:\n");
    for (int i = 0; i < graph->V; i++) {
        printf("Partner %d is colored with color %d\n", i + 1, color[i]);
    }

    free(color);
    return true;
}

int main() {
    struct Graph* graph = createGraph(MAX_PARTNERS);

    // Love connections (edges between partners)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);
    
    int m = 3; // Maximum number of colors (romantic groups)
    
    graphColoring(graph, m);

    // Free memory
    for (int i = 0; i < graph->V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);
    
    return 0;
}