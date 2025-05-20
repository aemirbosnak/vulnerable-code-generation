//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

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
        graph->adjMatrix[src][dest] = 1;  // Directed edge
        graph->adjMatrix[dest][src] = 1;  // Uncomment for undirected graph
    } else {
        printf("Error: Edge not added. Vertex out of bounds.\n");
    }
}

// Function to display the graph
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Depth First Search helper
void DFSUtil(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to perform Depth First Search
void DFS(Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    printf("Depth First Search starting from vertex %d:\n", startVertex);
    DFSUtil(graph, startVertex, visited);
    free(visited);
}

// Breadth First Search function
void BFS(Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = -1;

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    visited[startVertex] = true;
    queue[++rear] = startVertex;

    printf("\nBreadth First Search starting from vertex %d:\n", startVertex);
    
    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }

    free(visited);
    free(queue);
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    free(graph);
}

// Main function to demonstrate graph operations
int main() {
    int numVertices = 5;

    // Create a graph
    Graph* graph = createGraph(numVertices);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    // Display the graph
    displayGraph(graph);

    // Perform DFS and BFS
    DFS(graph, 0);
    BFS(graph, 0);

    // Free the graph memory
    freeGraph(graph);

    return 0;
}