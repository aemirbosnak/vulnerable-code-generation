//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define V 5 // Number of vertices

// Function to check whether it is safe to assign color to vertex v
int isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0; // A neighboring vertex has the same color
        }
    }
    return 1; // Safe to assign color
}

// Function to solve the m-coloring problem using backtracking
int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    // All vertices are assigned a color
    if (v == V) {
        return 1; // Success
    }
    
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to vertex v is safe
        if (isSafe(graph, color, v, c)) {
            color[v] = c; // Assign color c to vertex v
            
            // Recur to assign colors to the remaining vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return 1; // Success
            }
            
            // Backtrack
            color[v] = 0; // Reset color
        }
    }
    
    return 0; // Failure
}

// Function to initiate graph coloring
void graphColoring(int graph[V][V], int m) {
    int *color = (int *)malloc(V * sizeof(int));
    
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize all colors as 0
    }
    
    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < V; i++) {
            printf("Vertex %d --> Color %d\n", i + 1, color[i]);
        }
    } else {
        printf("Solution does not exist.\n");
    }
    
    free(color);
}

// Main function
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };
    
    int m = 3; // Number of colors
    graphColoring(graph, m);
    
    return 0;
}