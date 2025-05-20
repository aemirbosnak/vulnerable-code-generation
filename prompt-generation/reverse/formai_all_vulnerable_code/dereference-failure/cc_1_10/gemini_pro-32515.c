//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A utility function to check if the current color assignment
// is safe for vertex v with color c.
bool isSafe(int *color, int v, int c, int **graph, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// A recursive utility function to solve the m-coloring problem
bool graphColoring(int *color, int m, int **graph, int V) {
    // If all vertices are assigned a color then return true
    if (V == 0) {
        return true;
    }

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is safe
        if (isSafe(color, V, c, graph, V)) {
            color[V] = c;
            // Recur to assign colors to the remaining V-1 vertices
            if (graphColoring(color, m, graph, V - 1)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution, then
            // remove the color and try another color
            color[V] = 0;
        }
    }

    // If no color can be assigned to this vertex then return false
    return false;
}

// Driver code
int main() {
    int V = 4;
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }

    // Define the graph
    // 0 1 1 1
    // 1 0 1 0
    // 1 1 0 1
    // 1 0 1 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[0][3] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][0] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][0] = 1;
    graph[3][2] = 1;

    int m = 3; // Number of colors
    int *color = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if (graphColoring(color, m, graph, V)) {
        printf("Solution exists:\n");
        for (int i = 0; i < V; i++) {
            printf("%d ", color[i]);
        }
        printf("\n");
    } else {
        printf("Solution does not exist\n");
    }

    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
    free(color);

    return 0;
}