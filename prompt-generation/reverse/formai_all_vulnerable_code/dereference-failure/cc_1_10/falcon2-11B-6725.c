//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the graph
void printGraph(int graph[][50]) {
    int i, j;
    printf("Adjacency List Representation of Graph:\n");
    for (i = 0; i < 5; i++) {
        printf("Node %d:\t", i);
        for (j = 0; j < 5; j++) {
            if (graph[i][j] == 1)
                printf(" %d ", j);
        }
        printf("\n");
    }
}

// Function to check if a given graph is a valid C graph
int isValidCGraph(int graph[][50]) {
    int i, j;
    int numVertices = 5;
    int numEdges = 0;
    int adjList[50][50];

    // Initialize the adjacency list
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            adjList[i][j] = 0;
        }
    }

    // Calculate the number of edges in the graph
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            if (graph[i][j] == 1) {
                numEdges++;
            }
        }
    }

    // Check if the graph is valid
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            if (adjList[i][j] == 1) {
                printf("Error: Edge (%d, %d) already exists.\n", i, j);
                return 0;
            }
        }
    }

    return 1;
}

// Function to find a valid C graph coloring
int findCGraphColoring(int graph[][50]) {
    int i, j, k;
    int numVertices = 5;
    int numEdges = 0;
    int adjList[50][50];
    int colorList[50];
    int minColor = 0;

    // Initialize the adjacency list and color list
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            adjList[i][j] = 0;
        }
        colorList[i] = minColor;
        minColor++;
    }

    // Calculate the number of edges in the graph
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            if (graph[i][j] == 1) {
                numEdges++;
            }
        }
    }

    // Check if the graph is valid
    if (numEdges!= numVertices - 1) {
        printf("Error: Invalid graph - not a C graph.\n");
        return 0;
    }

    // Find the minimum color
    for (i = 0; i < numVertices; i++) {
        minColor = 0;
        for (j = 0; j < numVertices; j++) {
            if (adjList[i][j] == 1) {
                if (colorList[j] < minColor) {
                    minColor = colorList[j];
                }
            }
        }
        colorList[i] = minColor;
    }

    // Check if the graph is properly colored
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            if (adjList[i][j] == 1 && colorList[i] == colorList[j]) {
                printf("Error: Node %d and %d have the same color.\n", i, j);
                return 0;
            }
        }
    }

    printf("The graph is properly colored.\n");
    return 1;
}

int main() {
    int graph[5][5] = {{0, 1, 0, 0, 0},
                       {1, 0, 1, 0, 0},
                       {0, 1, 0, 1, 0},
                       {0, 0, 1, 0, 1},
                       {0, 0, 0, 1, 0}};

    int result = isValidCGraph(graph);
    if (result == 1) {
        printf("The graph is a valid C graph.\n");
    }

    result = findCGraphColoring(graph);
    if (result == 1) {
        printf("The graph is properly colored.\n");
    }

    return 0;
}