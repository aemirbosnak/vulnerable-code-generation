//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Function to check if a given vertex is safe to assign a color
int isSafe(int vertices, int colors, int** graph, int color, int vertex) {
    // If the vertex is already colored or is a neighbor of a colored vertex, return false
    for (int i = 0; i < vertices; i++) {
        if (graph[i][vertex] == 1 || graph[vertex][i] == 1) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the graph coloring problem
int solveGraphColoring(int vertices, int colors, int** graph) {
    int** result = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        result[i] = (int*)malloc(colors * sizeof(int));
    }

    // Initialize all vertices as not colored
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < colors; j++) {
            result[i][j] = -1;
        }
    }

    for (int color = 0; color < colors; color++) {
        // If all vertices are colored, return success
        if (isSafe(vertices, colors, graph, color, 0) == 0) {
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < colors; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            return 0;
        }
    }

    return 1;
}

int main() {
    // Example graph with 5 vertices and 3 colors
    int vertices = 5;
    int colors = 3;
    int** graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Create the graph
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[0][3] = 1;
    graph[0][4] = 1;

    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;

    graph[2][4] = 1;

    graph[3][4] = 1;

    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[4][2] = 1;
    graph[4][3] = 1;

    int result = solveGraphColoring(vertices, colors, graph);

    if (result == 0) {
        printf("Graph coloring problem solved successfully!\n");
    } else {
        printf("Graph coloring problem not solved\n");
    }

    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}