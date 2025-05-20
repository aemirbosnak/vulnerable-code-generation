//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->numVertices = vertices;

    // Initialize the adjacency matrix
    for(int i = 0; i < vertices; i++)
        for(int j = 0; j < vertices; j++)
            g->adjMatrix[i][j] = 0;

    return g;
}

// Function to add an edge to the graph
void addEdge(Graph *g, int src, int dest) {
    if (src < g->numVertices && dest < g->numVertices) {
        g->adjMatrix[src][dest] = 1; // Add edge
    } else {
        printf("Error: Invalid vertices for edge (%d -> %d)\n", src, dest);
    }
}

// Function to display the graph using its adjacency matrix
void displayGraph(Graph *g) {
    printf("Adjacency Matrix Representation of the Graph:\n");
    for(int i = 0; i < g->numVertices; i++) {
        for(int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform a Depth First Search (DFS)
void DFSUtil(Graph *g, int v, int visited[]) {
    visited[v] = 1; // Mark the current node as visited
    printf("%d ", v);

    for(int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[v][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

// Function to initiate DFS
void DFS(Graph *g, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Track visited vertices
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    DFSUtil(g, startVertex, visited);
    printf("\n");
}

// Function to perform Breadth First Search (BFS)
void BFS(Graph *g, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Track visited vertices
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[startVertex] = 1; // Mark the starting vertex as visited 
    queue[++rear] = startVertex; // Enqueue

    printf("Breadth First Search starting from vertex %d:\n", startVertex);
    while (front != rear) {
        front++;
        int currVertex = queue[front];
        printf("%d ", currVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark as visited
                queue[++rear] = i; // Enqueue
            }
        }
    }
    printf("\n");
}

// Main Function
int main() {
    int vertices = 5;
    Graph *g = createGraph(vertices);

    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);

    displayGraph(g);
    
    DFS(g, 0);
    BFS(g, 0);

    // Free memory
    free(g);
    return 0;
}