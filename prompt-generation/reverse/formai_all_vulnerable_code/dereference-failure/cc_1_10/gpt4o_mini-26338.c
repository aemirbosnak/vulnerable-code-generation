//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int **adjMatrix;
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
    }

    // Initialize the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1; // For undirected graph
    } else {
        printf("Error: Vertex out of bounds\n");
    }
}

// Function to print the adjacency matrix of the graph
void printGraph(Graph* graph) {
    printf("Adjacency Matrix Representation of the Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform a depth-first search (DFS)
void DFSUtil(int** adjMatrix, int vertex, int* visited, int numVertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(adjMatrix, i, visited, numVertices);
        }
    }
}

// Function to initiate DFS from a specific vertex
void DFS(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    printf("Depth-First Search starting from vertex %d:\n", startVertex);
    DFSUtil(graph->adjMatrix, startVertex, visited, graph->numVertices);
    printf("\n");
    free(visited);
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

// Main function to demonstrate the graph operations
int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    DFS(graph, 0);

    freeGraph(graph);

    return 0;
}