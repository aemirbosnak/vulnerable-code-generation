//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a graph
struct Graph {
    int numVertices;
    char **adjMatrix;
};

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = malloc(vertices * sizeof(char *));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = malloc(vertices * sizeof(char));
        memset(graph->adjMatrix[i], '0', vertices);  // Initialize with '0'
    }

    return graph;
}

// Function to add edge to the graph
void addEdge(struct Graph *graph, int start, int end) {
    graph->adjMatrix[start][end] = '1';  // Marking the presence of an edge
    graph->adjMatrix[end][start] = '1';  // For undirected graph
}

// Function to print the adjacency matrix
void printGraph(struct Graph *graph) {
    printf("Adjacency Matrix of the Graph:\n");
    
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%c ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to delete the graph and free memory
void deleteGraph(struct Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

// Main function to demonstrate the graph representation
int main() {
    int vertices = 5; // Example: 5 vertices

    // Create the graph
    struct Graph *graph = createGraph(vertices);

    // Adding edges (artistic connections)
    addEdge(graph, 0, 1);  // A -- B
    addEdge(graph, 0, 4);  // A -- E
    addEdge(graph, 1, 2);  // B -- C
    addEdge(graph, 1, 3);  // B -- D
    addEdge(graph, 1, 4);  // B -- E
    addEdge(graph, 2, 3);  // C -- D
    addEdge(graph, 3, 4);  // D -- E

    // Print the graph representation
    printGraph(graph);

    // Clean up
    deleteGraph(graph);

    return 0;
}