//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

// Function prototypes
void printSolution(int color[], int V);
bool isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int color[], int c, int V);
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V);
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V);

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int V, m;
    
    // User input for number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // User input for adjacency matrix
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // User input for the number of colors
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    // Calling the graph coloring function
    if (graphColoring(graph, m, V)) {
        printf("Graph can be colored with %d colors.\n", m);
    } else {
        printf("Graph cannot be colored with %d colors.\n", m);
    }

    return 0;
}

// Function to print the solution
void printSolution(int color[], int V) {
    printf("Solution Exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Color %d\n", i + 1, color[i]);
    }
}

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int color[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the graph coloring problem
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V) {
    if (v == V) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return true;
            }
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

// Main function to check if graph can be colored with m colors
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V) {
    int *color = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize all colors to 0
    }

    if (!graphColoringUtil(graph, m, color, 0, V)) {
        free(color);
        return false;
    }

    printSolution(color, V);
    free(color);
    return true;
}