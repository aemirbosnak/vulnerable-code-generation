//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
typedef struct Graph {
    int numVertices;                       // Number of vertices
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
} Graph;

// Function to create a graph with a specified number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1; // Directed edge from src to dest
    graph->adjacencyMatrix[dest][src] = 1; // Undirected edge
}

// Function to remove an edge from the graph
void removeEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 0;
    graph->adjacencyMatrix[dest][src] = 0;
}

// Function to display the adjacency matrix of the graph
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Depth First Search (DFS) utility
void DFSUtil(Graph* graph, int v, int visited[]) {
    visited[v] = 1; // Mark the current vertex as visited
    printf("%d ", v); // Print the vertex

    // Recur for all adjacent vertices
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[v][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to perform DFS traversal of the graph
void depthFirstSearch(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

// Breadth First Search (BFS) utility
void breadthFirstSearch(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Array to track visited vertices
    int queue[MAX_VERTICES], front = 0, rear = -1;
    
    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("Breadth First Search starting from vertex %d:\n", startVertex);
    
    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        
        // Visit all adjacent vertices
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

// Function to free the allocated memory for the graph
void freeGraph(Graph* graph) {
    free(graph);
}

// Main function
int main() {
    int vertices = 5; // Number of vertices
    Graph* graph = createGraph(vertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Display the graph's adjacency matrix
    displayGraph(graph);

    // Perform DFS and BFS traversals
    depthFirstSearch(graph, 0);
    breadthFirstSearch(graph, 0);

    // Clean up allocated memory
    freeGraph(graph);
    
    return 0;
}