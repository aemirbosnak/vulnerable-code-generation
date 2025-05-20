//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a graph
typedef struct Graph {
    int numVertices; // Number of vertices in the graph
    int **adjMatrix; // Adjacency matrix
} Graph;

// Function to create a graph with a specified number of vertices
Graph* createGraph(int vertices) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    g->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        g->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
    }

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
    return g;
}

// Function to add an edge to the graph
void addEdge(Graph *g, int from, int to) {
    if (from < g->numVertices && to < g->numVertices) {
        g->adjMatrix[from][to] = 1; // Directed edge from 'from' to 'to'
        // For undirected graph: uncomment the line below
        // g->adjMatrix[to][from] = 1; 
    } else {
        printf("Error: Vertex number out of bounds.\n");
    }
}

// Function to display the adjacency matrix
void displayGraph(Graph *g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the graph
void freeGraph(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        free(g->adjMatrix[i]);
    }
    free(g->adjMatrix);
    free(g);
}

// Function to perform depth-first search (DFS)
void DFSUtil(Graph *g, int vertex, int *visited) {
    visited[vertex] = 1; // Mark the current vertex as visited
    printf("%d ", vertex); // Print the visited vertex

    for (int i = 0; i < g->numVertices; i++) {
        // If there is an edge and the vertex is not visited
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

// Function to initiate DFS from a given starting vertex
void DFS(Graph *g, int startVertex) {
    int *visited = (int *)malloc(g->numVertices * sizeof(int));
    
    // Mark all vertices as not visited
    for (int i = 0; i < g->numVertices; i++) {
        visited[i] = 0;
    }

    printf("Depth First Search starting from vertex %d:\n", startVertex);
    DFSUtil(g, startVertex, visited);
    printf("\n");

    free(visited); // Free allocated memory for visited array
}

// Function to perform breadth-first search (BFS)
void BFS(Graph *g, int startVertex) {
    int *visited = (int *)malloc(g->numVertices * sizeof(int));
    int *queue = (int *)malloc(g->numVertices * sizeof(int));
    int front = -1, rear = -1;

    // Mark all vertices as not visited
    for (int i = 0; i < g->numVertices; i++) {
        visited[i] = 0;
    }

    // Start from the starting vertex
    visited[startVertex] = 1;
    queue[++rear] = startVertex; // Enqueue the starting vertex
    printf("Breadth First Search starting from vertex %d:\n", startVertex);

    while (front < rear) {
        front++;
        int currentVertex = queue[front]; 
        printf("%d ", currentVertex); // Print the visited vertex

        // Traverse all adjacent vertices
        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark as visited
                queue[++rear] = i; // Enqueue adjacent vertex
            }
        }
    }
    printf("\n");

    free(visited);
    free(queue);
}

// Main function to demonstrate graph operations
int main() {
    int vertices = 5; // Create a graph with 5 vertices
    Graph *g = createGraph(vertices);

    // Adding edges to the graph
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 3, 4);

    // Display the graph represented by the adjacency matrix
    displayGraph(g);

    // Perform DFS and BFS
    DFS(g, 0);
    BFS(g, 0);

    // Free allocated memory for the graph
    freeGraph(g);
    return 0;
}