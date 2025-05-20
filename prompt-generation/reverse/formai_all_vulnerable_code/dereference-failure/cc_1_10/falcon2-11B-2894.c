//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to check if a graph is 2-colorable
int is_2_colorable(int V, int E) {
    int **adj = (int **)malloc(sizeof(int *) * V);
    for (int i = 0; i < V; i++) {
        adj[i] = (int *)malloc(sizeof(int) * V);
    }
    
    // Initialize the adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }
    
    // Add edges to the graph
    for (int i = 0; i < E; i++) {
        int u = rand() % V;
        int v = rand() % V;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    // Attempt to color the graph with two colors
    int *colors = (int *)malloc(sizeof(int) * V);
    for (int i = 0; i < V; i++) {
        colors[i] = 0;
    }
    
    // Color the graph
    int color = 0;
    for (int i = 0; i < V; i++) {
        if (colors[i] == 0) {
            color = 1;
            colors[i] = color;
            
            for (int j = 0; j < V; j++) {
                if (adj[i][j] && colors[j] == color) {
                    colors[j] = -1; // Color conflict
                }
            }
        }
    }
    
    // Check if the graph is 2-colorable
    for (int i = 0; i < V; i++) {
        if (colors[i] == -1) {
            return 0;
        }
    }
    
    free(adj);
    free(colors);
    
    return 1;
}

int main() {
    int V = 10;
    int E = 10;
    
    int result = is_2_colorable(V, E);
    
    if (result) {
        printf("The graph is 2-colorable.\n");
    } else {
        printf("The graph is not 2-colorable.\n");
    }
    
    return 0;
}