//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the solution
void printSolution(int *colors, int n) {
    printf("Solution: \n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d ---> Color %d\n", i, colors[i]);
    }
}

// Function to check whether it is safe to assign color to a vertex
bool isSafe(int **graph, int n, int *colors, int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && colors[i] == c) {
            return false;
        }
    }
    return true;
}

// Utility function to solve the graph coloring problem
bool graphColoringUtil(int **graph, int m, int n, int *colors, int v) {
    if (v == n) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, n, colors, v, c)) {
            colors[v] = c;
            if (graphColoringUtil(graph, m, n, colors, v + 1)) {
                return true;
            }
            colors[v] = 0;  // Backtrack
        }
    }
    return false;
}

// Main function to color the graph using Backtracking
bool graphColoring(int **graph, int m, int n) {
    int *colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        colors[i] = 0;
    }

    if (graphColoringUtil(graph, m, n, colors, 0)) {
        printSolution(colors, n);
        free(colors);
        return true;
    }

    printf("Solution does not exist with %d colors.\n", m);
    free(colors);
    return false;
}

// Function to create a graph adjacency matrix
int **createGraph(int n) {
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(int **graph, int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Function to free the graph memory
void freeGraph(int **graph, int n) {
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
}

// Driver code
int main() {
    int n = 4; // Number of vertices
    int m = 3; // Number of colors
    int **graph = createGraph(n);

    // Adding edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    // Solve graph coloring problem
    if (!graphColoring(graph, m, n)) {
        printf("No solution found.\n");
    }

    // Free the graph memory
    freeGraph(graph, n);
    return 0;
}