//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = vertices;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
    return g;
}

// Function to add an edge to the graph (undirected)
void addEdge(Graph* g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices) {
        fprintf(stderr, "Error: Vertex out of bounds\n");
        return;
    }
    g->adjacencyMatrix[src][dest] = 1;
    g->adjacencyMatrix[dest][src] = 1; // Undirected graph  - symmetrical
}

// Function to remove an edge from the graph (undirected)
void removeEdge(Graph* g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices) {
        fprintf(stderr, "Error: Vertex out of bounds\n");
        return;
    }
    g->adjacencyMatrix[src][dest] = 0;
    g->adjacencyMatrix[dest][src] = 0; // Undirected graph
}

// Function to print the adjacency matrix of the graph
void printGraph(Graph* g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function for Depth-First Search (DFS)
void DFSUtil(Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the vertex as visited
    printf("%d ", vertex); // Print the vertex

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

// Function to perform DFS
void DFS(Graph* g, int startingVertex) {
    int visited[MAX_VERTICES] = {0}; // Initialize visited array
    DFSUtil(g, startingVertex, visited);
}

// Function for Breadth-First Search (BFS)
void BFS(Graph* g, int startingVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES], front = -1, rear = -1;

    visited[startingVertex] = 1;
    queue[++rear] = startingVertex;    

    while (front < rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

// Free graph memory
void freeGraph(Graph* g) {
    free(g);
}

// Main function to test the graph functionality
int main() {
    int vertices = 5;
    Graph* g = createGraph(vertices);

    // Adding edges
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 4);
    
    // Printing the graph
    printGraph(g);

    // Running DFS and BFS
    printf("DFS starting from vertex 0:\n");
    DFS(g, 0);
    printf("\n");

    printf("BFS starting from vertex 0:\n");
    BFS(g, 0);
    printf("\n");

    // Cleanup
    freeGraph(g);
    return 0;
}