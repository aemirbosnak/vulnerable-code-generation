//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// Structure to represent a graph
struct Graph {
    int numVertices;
    int numEdges;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to initialize graph with given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->numEdges = 0;
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
    graph->numEdges++;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    printf("Graph: \n");
    
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 4);

    printGraph(graph);

    return 0;
}