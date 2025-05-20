//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: surprised
// Behold, a C program that paints a vivid tapestry of graphs to surprise and delight!

#include <stdio.h>
#include <stdlib.h>

// Graph structure - a canvas for our connections
typedef struct Graph {
    int numVertices;      // The bustling hub of our graph
    int numEdges;         // The vibrant veins coursing through it
    int** adjacencyMatrix; // The intricate web that weaves our graph together
} Graph;

// Vertex - a vibrant dot on our graph's canvas
typedef struct Vertex {
    int data;                 // The unique identity of the vertex
    int* connectedVertices;  // The companions it shares its connections with
    int numConnectedVertices; // The count of companions
} Vertex;

// Unveiling the tapestry of our graph
void print_graph(Graph* graph) {
    int i, j;
    printf("Behold, the graph's intricate embrace!\n");
    for (i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d whispers to:\n", i+1);
        for (j = 0; j < graph->numVertices; j++) {
            if (graph->adjacencyMatrix[i][j]) {
                printf("\tVertex %d", j+1);
            }
        }
        printf("\n");
    }
}

// The heart of our graph - where connections are forged
void add_edge(Graph* graph, int from, int to) {
    graph->adjacencyMatrix[from-1][to-1] = 1;
    graph->adjacencyMatrix[to-1][from-1] = 1;
    graph->numEdges++;
}

// A journey of a thousand miles starts with a single step - initializing our graph
Graph* create_graph(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    graph->adjacencyMatrix = malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyMatrix[i] = malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Setting the stage for our graph's performance
int main() {
    // A canvas of 5 vertices, waiting eagerly for connections
    Graph* graph = create_graph(5);

    // Weaving the tapestry - adding connections one by one
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 4);
    add_edge(graph, 2, 5);
    add_edge(graph, 5, 3);

    // Unveiling our masterpiece - the graph in all its glory
    print_graph(graph);

    return 0;
}