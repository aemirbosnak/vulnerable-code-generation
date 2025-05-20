//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph with the specified number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    
    // Initialize adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    
    return graph;
}

// Function to add an edge between two vertices
void addEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        graph->adjMatrix[src][dest] = 1; // For directed graph
        graph->adjMatrix[dest][src] = 1; // Uncomment for an undirected graph
    } else {
        printf("Error: Invalid vertices.\n");
    }
}

// Function to display the adjacency matrix
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform DFS
void DFSUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to initiate DFS
void DFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    printf("Depth First Traversal starting from vertex %d:\n", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

// Function to perform BFS
void BFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = -1, back = -1;

    visited[startVertex] = 1;
    queue[++back] = startVertex;

    printf("Breadth First Traversal starting from vertex %d:\n", startVertex);

    while (front < back) {
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[++back] = i;
            }
        }
    }
    printf("\n");
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    free(graph);
}

// Main function demonstrating various operations on the graph
int main() {
    int vertices, edges, src, dest;

    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    if (vertices > MAX_VERTICES || vertices <= 0) {
        printf("Invalid number of vertices. Exiting.\n");
        return -1;
    }

    Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    displayGraph(graph);

    int startVertex;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &startVertex);
    DFS(graph, startVertex);

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &startVertex);
    BFS(graph, startVertex);

    freeGraph(graph);
    return 0;
}