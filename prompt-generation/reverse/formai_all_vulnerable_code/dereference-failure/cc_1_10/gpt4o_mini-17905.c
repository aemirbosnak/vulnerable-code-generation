//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure representing a graph
typedef struct Graph {
    int V; // Number of vertices
    int **adjMatrix; // Adjacency matrix
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = vertices;

    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize adjacency matrix
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Add edge from src to dest
    graph->adjMatrix[dest][src] = 1; // Add edge from dest to src (undirected)
}

// Function to display the graph's adjacency matrix
void displayGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Depth First Search
void DFSUtil(Graph *graph, int v, bool *visited) {
    visited[v] = true;
    printf("%d ", v);
    for (int i = 0; i < graph->V; i++) {
        if (graph->adjMatrix[v][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to start DFS traversal
void DFS(Graph *graph, int startVertex) {
    bool *visited = (bool *)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;
    
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
    free(visited);
}

// Function to free the graph's memory
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

// Function to create a graph with a specific structure
Graph* createShapeShifterGraph() {
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    return graph;
}

// Main function
int main() {
    Graph *shapeShifterGraph = createShapeShifterGraph();

    printf("Adjacency Matrix Representation of the Shape Shifter Graph:\n");
    displayGraph(shapeShifterGraph);

    DFS(shapeShifterGraph, 0);

    freeGraph(shapeShifterGraph);
    return 0;
}