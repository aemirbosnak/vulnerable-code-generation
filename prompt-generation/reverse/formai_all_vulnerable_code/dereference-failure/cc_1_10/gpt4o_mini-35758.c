//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define V 4 // Number of vertices in the graph

// Function to check if the current color assignment is safe for vertex v
int isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0; // Not safe, adjacent vertex has the same color
        }
    }
    return 1; // Safe to color vertex v with color c
}

// Recursive utility function to solve the graph coloring problem
int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    // Base case: If all vertices are assigned a color then return true
    if (v == V) {
        return 1; // All vertices are colored
    }

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to vertex v is safe
        if (isSafe(graph, color, v, c)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the remaining vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return 1; // If successful, propagate true up the stack
            }

            // If assigning color c doesn't lead to a solution, remove it (backtrack)
            color[v] = 0; // Remove color (backtrack)
        }
    }

    return 0; // If no color can be assigned, return false
}

// Function to solve the graph coloring problem
int graphColoring(int graph[V][V], int m) {
    int *color = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize color array
    }

    // Start from the first vertex
    if (graphColoringUtil(graph, m, color, 0) == 0) {
        printf("Solution does not exist\n");
        return 0;
    }

    // Print the solution
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
    free(color); // Free allocated memory
    return 1;
}

// Main function
int main() {
    // A simple graph represented using an adjacency matrix
    // Graph:
    // (0)---(1)
    //  |   / |
    //  |  /  |
    // (2)---(3)
    int graph[V][V] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    int m = 3; // Number of colors
    graphColoring(graph, m);

    return 0;
}