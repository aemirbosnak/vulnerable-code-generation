//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform DFS on the graph
void DFS(int v, int parent, int *visited, int *color) {
    // Mark the current vertex as visited
    visited[v] = 1;

    // Assign a color to the current vertex
    color[v] = 1;

    // Recursively visit all unvisited neighbors
    for (int i = 0; i < 4; i++) {
        int u = v * 4 + i;
        if (!visited[u]) {
            DFS(u, v, visited, color);
        }
    }
}

// Function to check if the graph has a valid coloring
int isValid(int *visited, int *color, int n) {
    for (int i = 0; i < n; i++) {
        if (visited[i] && color[i] > 1) {
            return 0;
        }
    }
    return 1;
}

// Function to find a valid coloring of the graph
void coloring(int *visited, int *color, int *parent, int n) {
    int *newColor = (int *)malloc(n * sizeof(int));
    memset(newColor, 0, n * sizeof(int));

    // Perform DFS on the graph
    DFS(0, -1, visited, newColor);

    // Check if the coloring is valid
    if (isValid(visited, newColor, n)) {
        printf("Valid coloring: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", newColor[i]);
        }
        printf("\n");
    } else {
        printf("No valid coloring found\n");
    }

    // Free the memory
    free(newColor);
}

int main() {
    int n = 8;
    int *visited = (int *)malloc(n * sizeof(int));
    int *color = (int *)malloc(n * sizeof(int));
    int *parent = (int *)malloc(n * sizeof(int));
    memset(visited, 0, n * sizeof(int));
    memset(color, 0, n * sizeof(int));
    memset(parent, -1, n * sizeof(int));

    // Create the graph
    visited[0] = 1;
    color[0] = 1;
    parent[0] = -1;

    visited[1] = 1;
    color[1] = 2;
    parent[1] = 0;

    visited[2] = 1;
    color[2] = 3;
    parent[2] = 0;

    visited[3] = 1;
    color[3] = 4;
    parent[3] = 0;

    visited[4] = 1;
    color[4] = 1;
    parent[4] = 0;

    visited[5] = 1;
    color[5] = 2;
    parent[5] = 0;

    visited[6] = 1;
    color[6] = 3;
    parent[6] = 0;

    visited[7] = 1;
    color[7] = 4;
    parent[7] = 0;

    // Find a valid coloring of the graph
    coloring(visited, color, parent, n);

    // Free the memory
    free(visited);
    free(color);
    free(parent);

    return 0;
}