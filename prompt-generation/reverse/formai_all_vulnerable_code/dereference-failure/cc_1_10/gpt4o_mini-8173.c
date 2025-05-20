//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a graph
typedef struct {
    int numVertices; // Number of vertices in the graph
    int** adjMatrix; // Adjacency matrix for the graph
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize all edges to 0
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int start, int end) {
    graph->adjMatrix[start][end] = 1; // Mark the edge from start to end
    graph->adjMatrix[end][start] = 1; // Because this is an undirected graph
}

// Function to display the adjacency matrix
void displayGraph(Graph* graph) {
    printf("Graph Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free memory allocated for the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]); // Free each row
    }
    free(graph->adjMatrix); // Free the array of rows
    free(graph); // Finally, free the graph itself
}

// Function to do a Depth First Search (DFS) on the graph
void DFS(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1; // Mark the current vertex as visited
    printf("%d ", vertex); // Print the vertex

    // Recurse for all the vertices adjacent to this vertex
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Function to perform DFS on the entire graph
void depthFirstTraversal(Graph* graph) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    memset(visited, 0, graph->numVertices * sizeof(int)); // Initialize visited array

    printf("Depth First Traversal starting from vertex 0:\n");
    DFS(graph, 0, visited);
    printf("\n");

    free(visited);
}

int main() {
    int numVertices = 5;
    Graph* graph = createGraph(numVertices);

    // Adding some edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Display the graph
    displayGraph(graph);

    // Perform Depth First Traversal
    depthFirstTraversal(graph);

    // Free allocated memory
    freeGraph(graph);
    return 0;
}