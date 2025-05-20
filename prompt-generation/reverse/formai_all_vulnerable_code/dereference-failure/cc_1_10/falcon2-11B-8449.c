//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Function to perform Graph Coloring Problem
int GraphColoringProblem(int n, int m, int* adj, int* color) {
    // Allocate memory for graph representation
    int graph[n][n];

    // Initialize graph with 0's
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Create edges for graph
    for (int i = 0; i < m; i++) {
        int u = adj[i * 2];
        int v = adj[i * 2 + 1];
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Perform Graph Coloring Problem
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                color[i] = color[j];
            } else if (color[i] == color[j]) {
                return -1; // Invalid color
            } else {
                color[i] = color[j] + 1;
            }
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    return 0;
}

int main() {
    int n = 6;
    int m = 5;
    int* adj = malloc(m * sizeof(int));
    int* color = malloc(n * sizeof(int));

    // Create edges for graph
    adj[0] = 1;
    adj[1] = 2;
    adj[2] = 3;
    adj[3] = 4;
    adj[4] = 5;
    adj[5] = 6;

    // Perform Graph Coloring Problem
    GraphColoringProblem(n, m, adj, color);

    // Print graph with colors
    printf("Graph with colors:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
        for (int j = 0; j < n; j++) {
            if (color[j] == i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Free memory
    free(adj);
    free(color);

    return 0;
}