//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 20
#define MAX_NAME_LENGTH 50

// Structure to represent a graph
typedef struct {
    char vertices[MAX_VERTICES][MAX_NAME_LENGTH];
    int **adjMatrix;
    int numVertices;
} Graph;

// Function to create a graph
Graph* createGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Dynamic memory allocation for adjacency matrix
    graph->adjMatrix = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(numVertices * sizeof(int));
        memset(graph->adjMatrix[i], 0, numVertices * sizeof(int)); // Initialize to 0
    }
    return graph;
}

// Function to add a vertex to the graph
void addVertex(Graph *g, char *name) {
    if (g->numVertices < MAX_VERTICES) {
        strcpy(g->vertices[g->numVertices], name);
        g->numVertices++;
    } else {
        printf("Graph is full! Cannot add more vertices.\n");
    }
}

// Function to add an edge to the graph
void addEdge(Graph *g, int start, int end) {
    if (start >= 0 && start < g->numVertices && end >= 0 && end < g->numVertices) {
        g->adjMatrix[start][end] = 1;
        g->adjMatrix[end][start] = 1; // For undirected graph
    } else {
        printf("Invalid edge!\n");
    }
}

// Function to display the graph
void displayGraph(Graph *g) {
    printf("Graph:\n");
    for (int i = 0; i < g->numVertices; i++) {
        printf("%s: ", g->vertices[i]);
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j]) {
                printf("%s ", g->vertices[j]);
            }
        }
        printf("\n");
    }
}

// Function to free the graph from memory
void freeGraph(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        free(g->adjMatrix[i]);
    }
    free(g->adjMatrix);
    free(g);
}

// Main function
int main() {
    Graph *myGraph = createGraph(0);

    printf("Welcome to the Graph Representation Program!\n");

    // Adding vertices
    addVertex(myGraph, "Vertex A");
    addVertex(myGraph, "Vertex B");
    addVertex(myGraph, "Vertex C");
    addVertex(myGraph, "Vertex D");

    // Adding edges
    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 2);
    addEdge(myGraph, 1, 2);
    addEdge(myGraph, 1, 3);

    // Displaying the graph
    displayGraph(myGraph);

    // Freeing memory
    freeGraph(myGraph);
    printf("Graph memory freed. Exiting program.\n");

    return 0;
}