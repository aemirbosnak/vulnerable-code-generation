//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a Graph
struct Graph {
    int numVertices;
    int **adjMatrix;
};

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize adjacency matrix to 0
        }
    }
    return graph;
}

// Function to add edge
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Add edge from src to dest
    graph->adjMatrix[dest][src] = 1; // Since undirected, add edge from dest to src
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Function to free the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

// Depth-First Search (DFS) utility
void DFSUtil(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1; // Mark the current vertex as visited
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// DFS traversal 
void DFS(struct Graph* graph) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize visited vertices
    }

    printf("Depth First Traversal: ");
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
    printf("\n");
    free(visited);
}

// Breadth-First Search (BFS) utility
void BFS(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize visited vertices
    }
    
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = 1; // Mark startVertex as visited
    queue[rear++] = startVertex; // Enqueue startVertex

    printf("Breadth First Traversal: ");
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i; // Enqueue the adjacent vertex
            }
        }
    }
    printf("\n");
    free(queue);
    free(visited);
}

// Main function
int main() {
    int vertices = 5; // Number of vertices
    struct Graph* graph = createGraph(vertices);

    // Adding edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Print the graph
    printGraph(graph);

    // Perform DFS
    DFS(graph);

    // Perform BFS starting from vertex 0
    BFS(graph, 0);

    // Free the graph memory
    freeGraph(graph);
    return 0;
}