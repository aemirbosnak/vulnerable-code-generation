//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int numVertices;
    int **adjMatrix;
};

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++)
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph->adjMatrix[i][j] = 0;

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // For undirected graph
}

// Function to print the adjacency matrix of the graph
void printGraph(struct Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated to the graph
void freeGraph(struct Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++)
        free(graph->adjMatrix[i]);
    free(graph->adjMatrix);
    free(graph);
}

// Function to perform BFS traversal from a given vertex
void BFS(struct Graph *graph, int startVertex) {
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    int queue[graph->numVertices]; // Simple queue for BFS
    int front = 0, rear = -1;

    // Mark the starting vertex as visited
    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("BFS traversal starting from vertex %d:\n", startVertex);

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    free(visited);
}

// Function to perform DFS traversal from a given vertex
void DFSUtil(struct Graph *graph, int vertex, int *visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(struct Graph *graph, int startVertex) {
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    printf("DFS traversal starting from vertex %d:\n", startVertex);
    DFSUtil(graph, startVertex, visited);

    free(visited);
}

int main() {
    int numVertices = 5;
    struct Graph *graph = createGraph(numVertices);

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

    // Perform BFS and DFS
    BFS(graph, 0);
    printf("\n");
    DFS(graph, 0);
    printf("\n");

    // Free the allocated memory
    freeGraph(graph);
    return 0;
}