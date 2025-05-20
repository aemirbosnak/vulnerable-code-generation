//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function to create a graph with a fixed size
Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = vertices;

    // Initialize the adjacency matrix to zero
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
    return g;
}

// Function to add an edge to the graph
void addEdge(Graph* g, int startVertex, int endVertex) {
    if (startVertex >= 0 && startVertex < g->numVertices && endVertex >= 0 && endVertex < g->numVertices) {
        g->adjMatrix[startVertex][endVertex] = 1;
        g->adjMatrix[endVertex][startVertex] = 1; // For undirected graph
    } else {
        printf("Error: Invalid vertices\n");
    }
}

// Function to print the adjacency matrix
void printGraph(Graph* g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform a depth-first search (DFS)
void DFS(Graph* g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

// Function to initiate DFS traversal
void performDFS(Graph* g) {
    bool* visited = (bool*)malloc(g->numVertices * sizeof(bool));
    for (int i = 0; i < g->numVertices; i++) {
        visited[i] = false;
    }

    printf("Depth First Traversal starting from vertex 0:\n");
    DFS(g, 0, visited);
    printf("\n");

    free(visited);
}

// Function to perform breadth-first search (BFS)
void BFS(Graph* g, int startVertex) {
    bool visited[MAX_VERTICES] = { false };
    int queue[MAX_VERTICES], front = -1, rear = -1;

    visited[startVertex] = true;
    queue[++rear] = startVertex;

    printf("Breadth First Traversal starting from vertex %d:\n", startVertex);
    while (front != rear) {
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

// Function to free the graph memory
void freeGraph(Graph* g) {
    free(g);
}

// Main function to demonstrate the graph
int main() {
    Graph* g = createGraph(5); // Create a graph with 5 vertices

    // Adding some edges
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);

    // Print the adjacency matrix
    printGraph(g);

    // Perform DFS
    performDFS(g);

    // Perform BFS
    BFS(g, 0);

    // Clean up
    freeGraph(g);

    return 0;
}