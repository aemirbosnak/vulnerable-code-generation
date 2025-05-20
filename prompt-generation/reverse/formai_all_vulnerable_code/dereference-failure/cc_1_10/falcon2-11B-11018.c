//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Define the graph structure
typedef struct {
    int n; // Number of vertices
    int **adj; // Adjacency list
    int color; // Color of the vertex
} Graph;

// Define the graph coloring function
int graph_color(Graph *graph, int color) {
    int i, j;
    int *visited = (int*)calloc(graph->n, sizeof(int)); // Array to keep track of visited vertices
    for (i = 0; i < graph->n; i++) {
        visited[i] = 0; // Initially all vertices are unvisited
    }
    for (i = 0; i < graph->n; i++) {
        if (!visited[i]) { // If vertex is unvisited
            int count = 0;
            for (j = 0; j < graph->n; j++) {
                if (graph->adj[i][j] == 1) {
                    if (visited[j] == 1) {
                        count++;
                    }
                }
            }
            if (count <= color - 1) {
                visited[i] = 1; // Mark the vertex as visited
                graph->color = color;
                color++; // Increment the color
            } else {
                printf("Graph cannot be colored with %d colors\n", color);
                return 0;
            }
        }
    }
    return 1;
}

// Define the main function
int main() {
    int n; // Number of vertices
    int **adj; // Adjacency list
    int color; // Number of colors
    Graph graph;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    graph.n = n;

    printf("Enter the adjacency list: ");
    adj = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)calloc(n, sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter the edge weight %d %d: ", i+1, j+1);
            scanf("%d", &adj[i][j]);
        }
    }

    graph.adj = adj;

    printf("Enter the number of colors: ");
    scanf("%d", &color);

    graph_color(&graph, color);

    printf("Graph is %d-colorable\n", color);

    return 0;
}