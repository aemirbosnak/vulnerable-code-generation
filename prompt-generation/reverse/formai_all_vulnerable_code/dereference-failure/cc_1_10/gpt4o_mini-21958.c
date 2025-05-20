//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5   // Number of vertices
#define COLORS 3 // Number of colors

// Function to check if the current color assignment is safe for vertex
bool isSafe(int graph[V][V], int coloring[], int vertex, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && coloring[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the coloring problem
bool graphColoringUtil(int graph[V][V], int m, int coloring[], int vertex) {
    if (vertex == V) {
        return true; // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) { // Trying different colors
        if (isSafe(graph, coloring, vertex, c)) {
            coloring[vertex] = c; // Assign color c to vertex

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, coloring, vertex + 1)) {
                return true;
            }

            coloring[vertex] = 0; // Backtrack
        }
    }
    return false; // No color can be assigned to this vertex
}

// Function to print the solution
void printSolution(int coloring[]) {
    printf("Solution exists: Assigned colors are:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i, coloring[i]);
    }
}

// Function to solve the Graph Coloring problem
void graphColoring(int graph[V][V], int m) {
    int *coloring = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++) {
        coloring[i] = 0; // Initialize all vertices as uncolored
    }

    if (graphColoringUtil(graph, m, coloring, 0) == false) {
        printf("Solution does not exist\n");
    } else {
        printSolution(coloring);
    }

    free(coloring);
}

// Driver code
int main() {
    // Graph representation using an adjacency matrix
    int graph[V][V] = {
        {0, 1, 1, 1, 0}, // Vertex 0 is connected to 1, 2, 3
        {1, 0, 0, 1, 1}, // Vertex 1 is connected to 0, 3, 4
        {1, 0, 0, 1, 0}, // Vertex 2 is connected to 0, 3
        {1, 1, 1, 0, 0}, // Vertex 3 is connected to 0, 1, 2
        {0, 1, 0, 0, 0}, // Vertex 4 is connected to 1
    };

    printf("Graph Coloring Problem:\n");
    graphColoring(graph, COLORS); // Function call to color the graph

    return 0;
}