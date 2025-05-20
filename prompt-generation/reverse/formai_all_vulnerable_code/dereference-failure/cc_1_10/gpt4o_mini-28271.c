//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
int isSafe(int graph[][10], int color[], int v, int c, int V);
int graphColoringUtil(int graph[][10], int m, int color[], int v, int V);
void printSolution(int color[], int n);
int graphColoring(int graph[][10], int V, int m);

/* Function to check if the current color assignment is safe for vertex v */
int isSafe(int graph[][10], int color[], int v, int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0; // Not safe if adjacent vertex has the same color
        }
    }
    return 1; // Safe to assign this color
}

/* A recursive utility function to solve the graph coloring problem */
int graphColoringUtil(int graph[][10], int m, int color[], int v, int V) {
    if (v == V) {
        return 1; // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c, V)) {
            color[v] = c; // Assign color c to vertex v

            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return 1; // If assignment leads to a solution
            }

            color[v] = 0; // Backtrack
        }
    }
    return 0; // No color can be assigned
}

/* Function to print the solution */
void printSolution(int color[], int n) {
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }
}

/* Main function to solve the graph coloring problem */
int graphColoring(int graph[][10], int V, int m) {
    int *color = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }

    if (graphColoringUtil(graph, m, color, 0, V) == 0) {
        printf("Solution does not exist\n");
        return 0; // No solution
    }

    printSolution(color, V);
    free(color);
    return 1; // Solution exists
}

/* Driver program to test the above functions */
int main() {
    int V; // Number of vertices
    int m; // Number of colors

    // Example graph represented as an adjacency matrix
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    int graph[10][10] = {0};

    printf("Enter the adjacency matrix (0 or 1) for the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, V, m);
    return 0;
}