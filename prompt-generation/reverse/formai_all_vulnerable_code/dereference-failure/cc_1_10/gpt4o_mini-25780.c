//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5 // Number of vertices

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the m-coloring problem
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    // Base case: If all vertices are assigned a color then return true
    if (v == V) {
        return true;
    }

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution then remove it
            color[v] = 0; // Backtrack
        }
    }
    return false; // If no color can be assigned, return false
}

// Function to solve m-coloring problem using backtracking
bool graphColoring(int graph[V][V], int m) {
    int *color = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }

    if (graphColoringUtil(graph, m, color, 0) == false) {
        printf("Solution does not exist\n");
        free(color);
        return false;
    }

    // Print the solution
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
    free(color);
    return true;
}

// Driver program to test above functions
int main() {
    // Example graph represented in adjacency matrix
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}};

    int m = 3; // Number of colors
    graphColoring(graph, m);

    return 0;
}