//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// This is a simple graph data structure
typedef struct graph {
    int vertexCount;
    int* edges;
} Graph;

// A utility function to add an edge to the graph
void addEdge(Graph* g, int v1, int v2) {
    // Check if the edge already exists
    if (g->edges[v1 * g->vertexCount + v2]!= 0)
        return;

    // Add the edge to the graph
    g->edges[v1 * g->vertexCount + v2] = 1;
}

// A utility function to print the graph
void printGraph(Graph* g) {
    for (int i = 0; i < g->vertexCount; i++) {
        for (int j = 0; j < g->vertexCount; j++) {
            if (g->edges[i * g->vertexCount + j]!= 0)
                printf("%d ", i);
        }
        printf("\n");
    }
}

int main() {
    int vertexCount = 5;
    Graph g;
    g.vertexCount = vertexCount;
    g.edges = (int*) malloc(vertexCount * vertexCount * sizeof(int));

    // Create the graph
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            addEdge(&g, i, j);
        }
    }

    // Print the graph
    printGraph(&g);

    // Free the allocated memory
    free(g.edges);

    return 0;
}