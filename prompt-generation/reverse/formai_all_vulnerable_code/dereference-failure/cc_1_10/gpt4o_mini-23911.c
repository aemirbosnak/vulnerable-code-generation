//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a Graph
typedef struct Graph {
    int numVertices;                 // Number of vertices
    bool** adjMatrix;                // Adjacency matrix
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = (bool**)malloc(vertices * sizeof(bool*));
    for(int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (bool*)malloc(vertices * sizeof(bool));
        for(int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = false; // Initialize all edges to false
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int start, int end) {
    if(start >= 0 && start < graph->numVertices && end >= 0 && end < graph->numVertices) {
        graph->adjMatrix[start][end] = true;
        graph->adjMatrix[end][start] = true; // For undirected graph, add both directions
    } else {
        printf("Error: Vertex index out of bounds.\n");
    }
}

// Function to print the adjacency matrix of the graph
void printGraph(Graph* graph) {
    printf("Adjacency Matrix of the Graph:\n");
    for(int i = 0; i < graph->numVertices; i++) {
        for(int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j] ? 1 : 0);
        }
        printf("\n");
    }
}

// Function to perform Depth First Search (DFS)
void DFSUtil(Graph* graph, int vertex, bool* visited) {
    visited[vertex] = true; // Mark the current node as visited
    printf("%d ", vertex); // Print the current node

    for(int i = 0; i < graph->numVertices; i++) {
        // If there is an edge and not visited
        if(graph->adjMatrix[vertex][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Wrapper function for DFS
void DFS(Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for(int i = 0; i < graph->numVertices; i++) {
        visited[i] = false; // Initialize all vertices as not visited
    }
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    DFSUtil(graph, startVertex, visited);
    free(visited);
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    for(int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

// Main function demonstrating the graph representation
int main() {
    int vertices = 5; // Number of vertices in the graph
    Graph* graph = createGraph(vertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency matrix
    printGraph(graph);

    // Perform DFS
    DFS(graph, 0);

    // Free the graph resources
    freeGraph(graph);

    return 0;
}