//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a graph
struct Graph {
    int numVertices;           // Number of vertices
    int** adjMatrix;          // Adjacency matrix
};

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;  // Initialize all edges to zero
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Add edge from src to dest
    graph->adjMatrix[dest][src] = 1; // For undirected graph, add edge in both directions
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

// Depth First Search (DFS) utility function
void DFSUtil(struct Graph* graph, int v, bool visited[]) {
    visited[v] = true;  // Mark the current node as visited
    printf("%d ", v);   // Print the current node

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[v][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to perform Depth First Search (DFS) on the graph
void DFS(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false; // Initialize all vertices as not visited
    }

    // Call the recursive DFS utility function
    DFSUtil(graph, startVertex, visited);
    free(visited); // Free allocated memory
}

// Breadth First Search (BFS) function
void BFS(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    // Initialize all vertices as not visited
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    visited[startVertex] = true; // Mark the starting node as visited
    queue[rear++] = startVertex;  // Enqueue the starting vertex

    while (front < rear) {
        int currentVertex = queue[front++]; // Dequeue a vertex
        printf("%d ", currentVertex); // Print the current vertex

        // Loop through all adjacent vertices
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true; // Mark it as visited
                queue[rear++] = i; // Enqueue it
            }
        }
    }

    free(visited); // Free allocated memory
    free(queue);   // Free allocated memory
}

// Function to clean up graph memory
void destroyGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]); // Free each row of the adjacency matrix
    }
    free(graph->adjMatrix); // Free the adjacency matrix
    free(graph); // Free the graph structure
}

// Main function to demonstrate the graph implementation
int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    
    // Displaying the graph
    displayGraph(graph);
    
    // Performing DFS
    printf("DFS starting from vertex 0:\n");
    DFS(graph, 0);
    printf("\n");

    // Performing BFS
    printf("BFS starting from vertex 0:\n");
    BFS(graph, 0);
    printf("\n");

    // Freeing the allocated memory for the graph
    destroyGraph(graph);

    return 0;
}