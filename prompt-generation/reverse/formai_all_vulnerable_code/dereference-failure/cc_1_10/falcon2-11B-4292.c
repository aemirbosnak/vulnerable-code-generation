//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the graph structure
typedef struct graph {
    int numVertices;
    int* adjacencyList;
} graph;

// Define the graph coloring function
bool graphColoring(graph* g, int numColors) {
    // Initialize the coloring array
    int* coloring = malloc(g->numVertices * sizeof(int));
    if (coloring == NULL) {
        printf("Memory allocation failed.\n");
        return false;
    }

    // Initialize the coloring array with -1
    for (int i = 0; i < g->numVertices; i++) {
        coloring[i] = -1;
    }

    // Check if the number of colors is valid
    if (numColors > g->numVertices) {
        printf("Invalid number of colors.\n");
        return false;
    }

    // Coloring algorithm (DFS)
    for (int color = 0; color < numColors; color++) {
        bool changed = false;

        // Start DFS from the first vertex
        int startVertex = 0;
        int dfsStack[g->numVertices];
        int dfsStackIndex = 0;
        int dfsColorStack[g->numVertices];
        int dfsColorStackIndex = 0;

        // Push the start vertex to the stack
        dfsStack[dfsStackIndex++] = startVertex;
        dfsColorStack[dfsColorStackIndex++] = color;

        // Loop until the stack is empty
        while (dfsStackIndex > 0) {
            // Pop the top vertex from the stack
            int vertex = dfsStack[--dfsStackIndex];

            // Check if the vertex is already colored
            if (coloring[vertex]!= -1) {
                continue;
            }

            // Set the coloring of the vertex
            coloring[vertex] = color;

            // Check if any of its neighbors are already colored with the same color
            for (int neighbor = 0; neighbor < g->numVertices; neighbor++) {
                if (g->adjacencyList[vertex] == neighbor && coloring[neighbor] == color) {
                    // Color conflict, try another color
                    color++;
                    if (color == numColors) {
                        // No more colors available, coloring failed
                        printf("Coloring failed.\n");
                        changed = true;
                        break;
                    }

                    // Reset the coloring of the vertex
                    coloring[vertex] = -1;

                    // Start DFS again from the current vertex
                    startVertex = vertex;
                    dfsStack[dfsStackIndex++] = startVertex;
                    dfsColorStack[dfsColorStackIndex++] = color;

                    // Check if DFS has changed anything
                    if (!changed) {
                        break;
                    }
                }
            }
        }

        // Check if DFS has changed anything
        if (!changed) {
            break;
        }
    }

    // Free the memory
    free(coloring);

    return true;
}

// Main function
int main() {
    // Create the graph
    graph g;
    g.numVertices = 7;
    g.adjacencyList = malloc(g.numVertices * sizeof(int));
    if (g.adjacencyList == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Set the adjacency list
    g.adjacencyList[0] = 1;
    g.adjacencyList[1] = 2;
    g.adjacencyList[2] = 3;
    g.adjacencyList[3] = 4;
    g.adjacencyList[4] = 5;
    g.adjacencyList[5] = 6;
    g.adjacencyList[6] = 0;

    // Color the graph
    if (graphColoring(&g, 3)) {
        printf("Graph colored successfully.\n");
    } else {
        printf("Coloring failed.\n");
    }

    // Free the memory
    free(g.adjacencyList);
    free(g.adjacencyList);

    return 0;
}