//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Cryptic
#include <stdio.h>  // for standard I/O
#include <stdlib.h> // for memory allocation
#include <stdbool.h> // for boolean datatype

// Structure to represent a graph
typedef struct Graph {
    int vertices;          // Number of vertices
    int **adjMatrix;      // Adjacency matrix
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph *g = (Graph *)malloc(sizeof(Graph)); // Allocate memory for graph
    g->vertices = vertices; // Set number of vertices
    g->adjMatrix = (int **)malloc(vertices * sizeof(int *)); // Allocate memory for adjacency matrix

    // Initialize the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        g->adjMatrix[i] = (int *)calloc(vertices, sizeof(int)); // Initialize rows to zero
    }
    
    return g; // Return the created graph
}

// Function to add an edge to the graph (undirected)
void addEdge(Graph *g, int src, int dest) {
    g->adjMatrix[src][dest] = 1; // Add edge from src to dest
    g->adjMatrix[dest][src] = 1; // Add edge from dest to src (undirected)
}

// Function to display the graph
void displayGraph(Graph *g) {
    printf("Graph Adjacency Matrix:\n");
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            printf("%d ", g->adjMatrix[i][j]); // Print adjacency values
        }
        printf("\n");
    }
}

// Function to delete the graph and free memory
void deleteGraph(Graph *g) {
    for (int i = 0; i < g->vertices; i++) {
        free(g->adjMatrix[i]); // Free each row
    }
    free(g->adjMatrix); // Free the adjacency matrix
    free(g); // Free the graph structure
}

// Depth-first search helper function
void DFSUtil(Graph *g, int vertex, bool visited[]) {
    visited[vertex] = true; // Mark the current node as visited
    printf("%d ", vertex); // Print the visited node

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited); // Recur for the adjacent vertex
        }
    }
}

// Function to perform depth-first search
void depthFirstSearch(Graph *g) {
    bool *visited = (bool *)malloc(g->vertices * sizeof(bool)); // Array to track visited vertices
    for (int i = 0; i < g->vertices; i++) {
        visited[i] = false; // Initialize all vertices as not visited
    }

    printf("Depth First Search from Vertex 0:\n");
    DFSUtil(g, 0, visited); // Start DFS from vertex 0
    printf("\n");
    free(visited); // Free visited array
}

// Main function
int main() {
    int n = 5; // Define the number of vertices
    Graph *g = createGraph(n); // Create a graph

    // Adding edges to the graph
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 4);
    addEdge(g, 3, 4);

    // Display the graph
    displayGraph(g);

    // Perform depth-first search
    depthFirstSearch(g);

    // Clean up and delete the graph
    deleteGraph(g);
    return 0; // Program ends successfully
}