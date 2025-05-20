//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph with a specified number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Initialize adjacency matrix with zeros
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    if (src < graph->numVertices && dest < graph->numVertices) {
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1; // For undirected graph
    } else {
        printf("Vertex out of bounds. Edge not added.\n");
    }
}

// Function to remove an edge from the graph
void removeEdge(Graph* graph, int src, int dest) {
    if (src < graph->numVertices && dest < graph->numVertices) {
        graph->adjMatrix[src][dest] = 0;
        graph->adjMatrix[dest][src] = 0; // For undirected graph
    } else {
        printf("Vertex out of bounds. Edge not removed.\n");
    }
}

// Function to display the adjacency matrix of the graph
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Depth First Search (DFS) utility function
void DFSUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to perform Depth First Search on the graph
void DFS(Graph* graph) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize all vertices as not visited
    }

    printf("Depth First Search (DFS) starting from vertex 0:\n");
    DFSUtil(graph, 0, visited);
    free(visited);
}

// Breadth First Search (BFS) function
void BFS(Graph* graph) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    int queue[MAX_VERTICES];
    int front = 0, back = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize all vertices as not visited
    }

    visited[0] = 1;
    queue[back++] = 0; // Start from vertex 0

    printf("\nBreadth First Search (BFS) starting from vertex 0:\n");
    while (front < back) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[back++] = i; // Enqueue the vertex
            }
        }
    }
    free(visited);
}

// Main function to demonstrate graph operations
int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    
    displayGraph(graph);
    DFS(graph);
    BFS(graph);

    removeEdge(graph, 1, 4);
    printf("\nAfter removing edge (1, 4):\n");
    displayGraph(graph);

    free(graph);
    return 0;
}