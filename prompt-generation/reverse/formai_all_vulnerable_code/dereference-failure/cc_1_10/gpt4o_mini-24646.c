//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 5 // Number of vertices in the graph

// Function to print the solution
void printSolution(int color[]) {
    printf("Solution: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d => Color %d\n", i, color[i]);
    }
}

// Check if the current color assignment is safe for vertex v
bool isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// A recursive utility function to solve m-coloring problem
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        return true; // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c; // Assign color c to vertex v
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }
            color[v] = 0; // Backtrack
        }
    }
    return false; // No valid coloring was found
}

// This function solves the m-coloring problem using graphColoringUtil
bool graphColoring(int graph[V][V], int m) {
    int* color = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist\n");
        free(color);
        return false;
    }

    printSolution(color); // Print the solution
    free(color);
    return true;
}

int main() {
    // Example graph adjacency matrix (5 vertices)
    int graph[V][V] = { {0, 1, 1, 1, 0},
                        {1, 0, 0, 1, 1},
                        {1, 0, 0, 1, 1},
                        {1, 1, 1, 0, 0},
                        {0, 1, 1, 0, 0} };

    int m = 3; // Number of colors

    graphColoring(graph, m); // Call the graph coloring function

    return 0;
}