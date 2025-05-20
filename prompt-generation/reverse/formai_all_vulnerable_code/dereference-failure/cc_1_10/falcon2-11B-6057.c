//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the Graph Structure
typedef struct Graph {
    int vertices;
    int **adjacencyList;
} Graph;

// Function to create a new Graph
Graph *createGraph(int vertices) {
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->vertices = vertices;
    newGraph->adjacencyList = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        newGraph->adjacencyList[i] = (int *)malloc(vertices * sizeof(int));
    }
    return newGraph;
}

// Function to add an edge to the Graph
void addEdge(Graph *graph, int source, int destination) {
    graph->adjacencyList[source][destination] = 1;
}

// Function to display the Graph
void displayGraph(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjacencyList[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Creating a Graph
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Displaying the Graph
    displayGraph(graph);

    return 0;
}