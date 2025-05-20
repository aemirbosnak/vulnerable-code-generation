//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Graph Coloring Problem
// Given a graph, determine the minimum number of colors needed to color the nodes such that no two adjacent nodes have the same color.

// Graph represented as adjacency list
struct Graph {
    int V; // number of vertices
    int E; // number of edges
    int **adj; // adjacency list
};

// Create a new graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// Check if the graph is colorable with m colors
int isColorable(struct Graph* graph, int m) {
    // Color the vertices with m colors
    int colors[graph->V];
    for (int i = 0; i < graph->V; i++) {
        colors[i] = -1;
    }
    
    // Try to color the graph with m colors
    for (int i = 0; i < graph->V; i++) {
        if (colors[i] == -1) {
            if (!colorVertex(graph, i, colors, m)) {
                return 0;
            }
        }
    }
    
    return 1;
}

// Color the vertex with m colors
int colorVertex(struct Graph* graph, int v, int colors[], int m) {
    // Try all m colors
    for (int c = 0; c < m; c++) {
        // Check if the color is available
        if (isColorAvailable(graph, v, c, colors)) {
            // Assign the color to the vertex
            colors[v] = c;
            
            // Recursively color the remaining vertices
            if (colorVertex(graph, v + 1, colors, m)) {
                return 1;
            }
            
            // If the remaining vertices cannot be colored, reset the color of the vertex
            colors[v] = -1;
        }
    }
    
    return 0;
}

// Check if the color is available for the vertex
int isColorAvailable(struct Graph* graph, int v, int c, int colors[]) {
    // Check if any of the adjacent vertices have the same color
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

// Print the graph coloring
void printGraphColoring(struct Graph* graph, int colors[]) {
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
}

int main() {
    // Create a graph
    struct Graph* graph = createGraph(4, 3);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    
    // Check if the graph is 3-colorable
    int m = 3;
    if (isColorable(graph, m)) {
        // Print the graph coloring
        int colors[graph->V];
        colorVertex(graph, 0, colors, m);
        printGraphColoring(graph, colors);
    } else {
        printf("The graph is not 3-colorable.\n");
    }
    
    return 0;
}