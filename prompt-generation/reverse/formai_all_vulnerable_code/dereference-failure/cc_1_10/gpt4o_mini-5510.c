//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Structure representing a graph
typedef struct Graph {
    int numVertices;      // Number of vertices
    int** adjMatrix;      // Adjacency matrix
} Graph;

// Function to create a graph with given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
    }
    
    // Initialize the adjacency matrix to zero
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // No edges initially
        }
    }
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int start, int end) {
    if (start >= graph->numVertices || end >= graph->numVertices) {
        printf("Error: Vertex out of bounds!\n");
        return;
    }
    graph->adjMatrix[start][end] = 1; // Add edge from start to end
    graph->adjMatrix[end][start] = 1; // For undirected graph, add edge back
}

// Function to print the adjacency matrix
void printGraph(Graph* graph) {
    printf("Adjacency Matrix: \n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

// Function for Depth First Search
void DFSUtil(int vertex, int* visited, Graph* graph) {
    visited[vertex] = 1; // Mark the current node as visited
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] && !visited[i]) {
            DFSUtil(i, visited, graph);
        }
    }
}

// Function to initiate DFS traversal
void DFS(Graph* graph) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize visited array
    }

    printf("DFS Traversal: ");
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            DFSUtil(i, visited, graph);
        }
    }
    printf("\n");
    free(visited);
}

// Function for Breadth First Search
void BFS(Graph* graph) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize visited array
    }

    int queue[graph->numVertices];
    int front = 0, rear = 0;

    // Start from first node
    visited[0] = 1;
    queue[rear++] = 0;

    printf("BFS Traversal: ");
    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[vertex][i] && !visited[i]) {
                visited[i] = 1; // Mark as visited
                queue[rear++] = i; // Enqueue vertex
            }
        }
    }
    printf("\n");
    free(visited);
}

// Main function to demonstrate graph operations
int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    printGraph(graph);
    DFS(graph);
    BFS(graph);
    
    freeGraph(graph);
    return 0;
}