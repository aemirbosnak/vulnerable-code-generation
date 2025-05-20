//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Maximum number of vertices in the graph
#define MAX 20

// Structure to represent a graph using an adjacency matrix
struct Graph {
    int numVertices;
    int adjMatrix[MAX][MAX];
};

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* newGraph = (struct Graph*)malloc(sizeof(struct Graph));
    newGraph->numVertices = vertices;

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            newGraph->adjMatrix[i][j] = 0;
        }
    }
    return newGraph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // For undirected graph
}

// Function to remove an edge from the graph
void removeEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 0;
    graph->adjMatrix[dest][src] = 0; // For undirected graph
}

// Function to display the adjacency matrix of the graph
void displayGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Depth First Search (DFS) on the graph
void DFSUtil(struct Graph* graph, int vertex, bool visited[]) {
    // Mark the current vertex as visited
    visited[vertex] = true;
    printf("%d ", vertex);

    // Recursively visit all the adjacent vertices
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to perform DFS on the entire graph
void DFS(struct Graph* graph) {
    bool visited[MAX] = {false};
    printf("Depth First Search Traversal:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
    printf("\n");
}

// Function to perform Breadth First Search (BFS) on the graph
void BFS(struct Graph* graph, int startVertex) {
    bool visited[MAX] = {false};
    int queue[MAX], front = -1, rear = -1;

    // Mark the start vertex as visited
    visited[startVertex] = true;
    queue[++rear] = startVertex;

    printf("Breadth First Search Traversal:\n");
    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        // Visit all adjacent vertices
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter each edge (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    displayGraph(graph);
    DFS(graph);
    printf("Enter start vertex for BFS: ");
    scanf("%d", &src);
    BFS(graph, src);

    // Clean up
    free(graph);
    return 0;
}