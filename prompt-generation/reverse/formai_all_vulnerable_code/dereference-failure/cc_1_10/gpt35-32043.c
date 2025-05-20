//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Function to check if the current color assignment
// is safe for vertex v
int isSafe(int v, int **graph, int *color, int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to assign colors recursively to all vertices
int graphColoring(int **graph, int *color, int v, int V, int m) {
    // If all vertices are assigned a color, return true
    if (v == V) {
        return 1;
    }

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is possible
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;

            // Recur to assign colors to rest of the vertices
            if (graphColoring(graph, color, v + 1, V, m)) {
                return 1;
            }

            // If assigning color c doesn't lead to a solution,
            // then remove it and try other colors
            color[v] = 0;
        }
    }
    return 0;
}

int main() {
    int V = 5, m = 3; // The number of vertices and the number of colors
    int **graph = (int **) malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *) malloc(V * sizeof(int));
    }

    // Initialize graph with all edges as 1
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 1;
        }
    }

    // Assign 0 to all vertices initially
    int *color = (int *) malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    // Call the graphColoring function
    if (graphColoring(graph, color, 0, V, m)) {
        printf("Solution exists\n");
        for (int i = 0; i < V; i++) {
            printf("Vertex %d --> Color %d\n", i + 1, color[i]);
        }
    } else {
        printf("Solution does not exist\n");
    }

    // Free the memory allocated to the graph and color arrays
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
    free(color);

    return 0;
}