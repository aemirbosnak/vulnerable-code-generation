//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define a graph structure
typedef struct Graph {
    int **adj;
    int numVertices;
} Graph;

// Function to graph coloring
void graphColoring(Graph *graph) {
    // Allocate memory for the coloring array
    int *coloring = (int *)malloc(graph->numVertices * sizeof(int));

    // Initialize the coloring array
    for (int i = 0; i < graph->numVertices; i++) {
        coloring[i] = -1;
    }

    // Iterative coloring algorithm
    for (int i = 0; i < graph->numVertices; i++) {
        int availableColors = 0;
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adj[i][j] && coloring[j] != -1) {
                availableColors++;
            }
        }

        // If there are no available colors, then the graph is not colorable
        if (availableColors == 0) {
            return;
        }

        // Find the best available color
        int color = -1;
        for (int j = 0; j < availableColors; j++) {
            if (coloring[j] == -1) {
                color = j;
                break;
            }
        }

        // Assign the color to the vertex
        coloring[i] = color;
    }

    // Print the coloring
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d has color %d\n", i, coloring[i]);
    }
}

int main() {
    // Create a graph
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 5;
    graph->adj = (int **)malloc(graph->numVertices * sizeof(int *));
    for (int i = 0; i < graph->numVertices; i++) {
        graph->adj[i] = (int *)malloc(graph->numVertices * sizeof(int));
    }

    // Connect the vertices
    graph->adj[0][1] = 1;
    graph->adj[0][2] = 1;
    graph->adj[1][2] = 1;
    graph->adj[1][3] = 1;
    graph->adj[2][3] = 1;
    graph->adj[2][4] = 1;
    graph->adj[3][4] = 1;

    // Graph coloring
    graphColoring(graph);

    return 0;
}