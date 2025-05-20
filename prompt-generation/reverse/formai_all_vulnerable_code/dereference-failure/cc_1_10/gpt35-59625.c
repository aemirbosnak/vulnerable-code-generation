//FormAI DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Graph representation using adjacency matrix
typedef struct Graph {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function to add vertex to the graph
void addVertex(Graph *graph) {
    if (graph->numVertices < MAX_VERTICES) {
        graph->numVertices++;
    } else {
        printf("Graph is full, cannot add another vertex!\n");
    }
}

// Function to add edge to the graph
void addEdge(Graph *graph, int source, int destination) {
    if (source < graph->numVertices && destination < graph->numVertices) {
        graph->vertices[source][destination] = 1;
        graph->vertices[destination][source] = 1;
    } else {
        printf("Invalid vertices!\n");
    }
}

// Function to print the graph
void printGraph(Graph *graph) {
    for (int i=0; i<graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        for (int j=0; j<graph->numVertices; j++) {
            if (graph->vertices[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;

    // Add vertices
    addVertex(graph);
    addVertex(graph);
    addVertex(graph);
    addVertex(graph);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    // Print graph
    printGraph(graph);

    return 0;
}