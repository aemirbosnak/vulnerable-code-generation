//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure representing a graph
typedef struct Graph {
    int numVertices;
    int **adjacencyMatrix;
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    graph->adjacencyMatrix = malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyMatrix[i] = malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0; // Initialize adjacency matrix
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int start, int end) {
    if (start >= graph->numVertices || end >= graph->numVertices) {
        fprintf(stderr, "Error: Vertex out of bounds\n");
        return;
    }
    
    graph->adjacencyMatrix[start][end] = 1; // Add edge from start to end
    graph->adjacencyMatrix[end][start] = 1; // Since it's undirected
}

// Function to print the graph as an adjacency matrix
void printGraph(Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function for DFS
void DFSUtil(int v, int visited[], Graph *graph) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[v][i] && !visited[i]) {
            DFSUtil(i, visited, graph);
        }
    }
}

// Wrapper function for DFS
void DFS(Graph *graph, int startVertex) {
    int *visited = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize visited array
    }
    DFSUtil(startVertex, visited, graph);
    free(visited);
}

// Free the graph memory
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);
}

int main() {
    Graph *graph = createGraph(5);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    printf("DFS starting from vertex 0:\n");
    DFS(graph, 0);
    printf("\n");

    freeGraph(graph);
    return 0;
}