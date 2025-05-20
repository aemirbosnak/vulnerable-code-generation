//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a Graph
struct Graph {
    int numVertices;
    int **adjMatrix;
};

// Function to create a graph with given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Create adjacency matrix
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
    }

    // Initialize adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Directed edge
    graph->adjMatrix[dest][src] = 1; // Undirected edge
}

// Function to display the graph's adjacency matrix
void displayGraph(struct Graph *graph) {
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform a Depth First Search (DFS)
void DFSUtil(struct Graph *graph, int vertex, bool *visited) {
    visited[vertex] = true;
    printf("Visited %d\n", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to start DFS from a given vertex
void DFS(struct Graph *graph, int startVertex) {
    bool *visited = (bool *)malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    DFSUtil(graph, startVertex, visited);
    free(visited);
}

// Function to free the memory allocated for the graph
void freeGraph(struct Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

// Main function to demonstrate graph usage
int main() {
    int vertices = 5;
    struct Graph *graph = createGraph(vertices);

    printf("Adding edges...\n");
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    displayGraph(graph);

    printf("\nStarting DFS from vertex 0:\n");
    DFS(graph, 0);

    // Free graph memory
    freeGraph(graph);
    return 0;
}