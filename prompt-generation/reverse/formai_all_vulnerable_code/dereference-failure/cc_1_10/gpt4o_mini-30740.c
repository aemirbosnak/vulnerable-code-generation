//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a graph
typedef struct Graph {
    int numVertices;          // Number of vertices in the graph
    bool **adjMatrix;        // Adjacency matrix to store connections
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (bool**)malloc(vertices * sizeof(bool*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (bool*)malloc(vertices * sizeof(bool));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = false;  // Initialize all edges to false
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    if (src < graph->numVertices && dest < graph->numVertices) {
        graph->adjMatrix[src][dest] = true; // Connect the source to destination
        graph->adjMatrix[dest][src] = true; // Undirected graph: connect destination to source
    } else {
        fprintf(stderr, "Edge cannot be added: Invalid vertices (%d, %d)\n", src, dest);
    }
}

// Function to print the adjacency matrix
void printGraph(Graph* graph) {
    printf("Adjacency Matrix of the Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j] ? 1 : 0);
        }
        printf("\n");
    }
}

// Function to free graph memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]); // Free each row of the adjacency matrix
    }
    free(graph->adjMatrix); // Free the adjacency matrix
    free(graph); // Free the graph structure
}

// Check for a specific condition indicating a potential oddity
bool checkGraphCondition(Graph* graph) {
    // This function serves a paranoid purpose... what if there's a disconnected node?
    for (int i = 0; i < graph->numVertices; i++) {
        bool connected = false;
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j]) {
                connected = true;
                break;
            }
        }
        if (!connected) {
            fprintf(stderr, "Warning: Vertex %d is completely isolated!\n", i);
            return false; // Found an isolated node
        }
    }
    return true; // No issues found
}

// Main function
int main() {
    int numVertices = 5;
    Graph* graph = createGraph(numVertices);

    // Adding some edges (in a paranoid manner!)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 2, 4);

    // Potentially irregular vertices
    addEdge(graph, 2, 2); // Adding a self-loop (just in case!)
    
    // Print the graph - observe every bit
    printGraph(graph); 

    // Check for graph integrity paranoia
    if (!checkGraphCondition(graph)) {
        fprintf(stderr, "The graph has anomalies! Investigate immediately.\n");
        freeGraph(graph);
        return EXIT_FAILURE; // Immediate exit on error
    }

    printf("Graph sanity check passed. All seems well... for now.\n");

    // Free memory before exit
    freeGraph(graph);
    return EXIT_SUCCESS;
}