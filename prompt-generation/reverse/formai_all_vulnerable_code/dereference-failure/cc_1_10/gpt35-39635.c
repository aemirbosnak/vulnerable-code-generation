//FormAI DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a graph
typedef struct graph {
    int size;
    int* nodes;
    int** edges;
} Graph;

// Initializes a new graph of given size
Graph* createGraph(int size) {
    Graph* newGraph = (Graph*) malloc(sizeof(Graph));
    newGraph -> size = size;
    newGraph -> nodes = (int*) malloc(size * sizeof(int));
    newGraph -> edges = (int**) malloc(size * sizeof(int*));

    // Initialize the adjacency matrix with all zeros to start with
    for(int i = 0; i < size; ++i) {
        newGraph -> nodes[i] = i;
        newGraph -> edges[i] = (int*) calloc(size, sizeof(int));
    }
    return newGraph;
}

// Adds new edge to the graph
void addEdge(Graph* graph, int start, int end, int weight) {
    graph -> edges[start][end] = weight;
}

// Displays the graph using adjacency list
void displayGraph(Graph* graph) {
    printf("\nNodes in the graph: ");
    for(int i = 0; i < graph -> size; ++i) {
        printf("%d ", graph -> nodes[i]);
    }
    printf("\n\nEdges in the graph:\n");
    for(int i = 0; i < graph -> size; ++i) {
        printf("Node %d: ", i);
        for(int j = 0; j < graph -> size; ++j) {
            if(graph -> edges[i][j] != 0) {
                printf(" -> %d (weight = %d)", j, graph -> edges[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph* myGraph = createGraph(5);
    addEdge(myGraph, 0, 1, 10);
    addEdge(myGraph, 0, 2, 5);
    addEdge(myGraph, 1, 2, 2);
    addEdge(myGraph, 1, 3, 1);
    addEdge(myGraph, 2, 1, 3);
    addEdge(myGraph, 2, 3, 9);
    addEdge(myGraph, 2, 4, 2);
    addEdge(myGraph, 3, 4, 4);
    addEdge(myGraph, 4, 3, 6);

    displayGraph(myGraph);

    return 0;
}