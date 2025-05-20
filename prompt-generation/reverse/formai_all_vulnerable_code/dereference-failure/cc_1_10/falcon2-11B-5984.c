//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform graph coloring using BFS
void graphColoring(int n, int *adj, int *colors) {
    int *visited = (int*)malloc(sizeof(int) * n);
    int *queue = (int*)malloc(sizeof(int) * n);
    int *temp = (int*)malloc(sizeof(int) * n);
    int i, j, k;

    // Mark all vertices as unvisited
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        queue[i] = 0;
    }

    // Start BFS from vertex 0
    visited[0] = 1;
    queue[0] = 1;

    for (i = 1; i < n; i++) {
        // If vertex i is unvisited
        if (visited[i] == 0) {
            // Mark vertex i as visited
            visited[i] = 1;

            // Traverse all adjacent vertices of vertex i
            for (j = 0; j < n; j++) {
                // If vertex j is unvisited and has not been visited before
                if (visited[j] == 0 && adj[i * n + j] == 1) {
                    // Put vertex j in the queue
                    queue[k++] = j;
                }
            }
        }
    }

    // Assign colors to each vertex
    for (i = 0; i < n; i++) {
        if (colors[i] == 0) {
            colors[i] = 1;
            for (j = 0; j < n; j++) {
                if (adj[i * n + j] == 1 && colors[j] == 0) {
                    colors[j] = 1;
                }
            }
        }
    }
}

// Function to print the graph
void printGraph(int n, int *adj) {
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i * n + j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n = 3;
    int adj[3][3] = { {1, 0, 1}, {0, 1, 1}, {1, 1, 0} };
    int colors[3] = {0, 0, 0};

    graphColoring(n, adj, colors);

    printf("Vertex 0: %d\n", colors[0]);
    printf("Vertex 1: %d\n", colors[1]);
    printf("Vertex 2: %d\n", colors[2]);

    printGraph(n, adj);

    return 0;
}