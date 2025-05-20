//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define V 5 // Number of vertices

typedef struct {
    int u, v;
} Edge;

void addEdge(Edge edges[], int *edgeCount, int u, int v) {
    edges[*edgeCount].u = u;
    edges[*edgeCount].v = v;
    (*edgeCount)++;
}

int isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return 0; // False, color not safe
        }
    }
    return 1; // True, color safe
}

int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) { // All vertices are assigned a color
        return 1; // Success
    }
    for (int c = 1; c <= m; c++) { // Try different colors
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // Assign color
            if (graphColoringUtil(graph, m, color, v + 1)) { // Recur
                return 1; // Success
            }
            color[v] = 0; // Backtrack
        }
    }
    return 0; // No solution
}

void graphColoring(int graph[V][V], int m) {
    int *color = (int *)malloc(V * sizeof(int)); // Allocate color array
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize colors
    }
    
    if (graphColoringUtil(graph, m, color, 0) == 0) {
        printf("Solution does not exist\n");
        return; // No solution found
    }

    printf("Solution:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i+1, color[i]);
    }
    free(color); // Free allocated memory
}

int main() {
    int m = 3; // Number of colors
    int graph[V][V] = { 
        {0, 1, 1, 1, 0}, 
        {1, 0, 0, 1, 1}, 
        {1, 0, 0, 1, 0}, 
        {1, 1, 1, 0, 0}, 
        {0, 1, 0, 0, 0} 
    };

    printf("Coloring the graph with %d colors...\n", m);
    graphColoring(graph, m); // Function call to class the graph
    return 0;
}