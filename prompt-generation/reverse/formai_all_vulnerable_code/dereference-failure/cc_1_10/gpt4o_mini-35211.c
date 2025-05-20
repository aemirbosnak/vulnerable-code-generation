//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// A structure to represent a graph
typedef struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph with a specified number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize edges to 0
        }
    }
    return graph;
}

// Function to add an edge between two vertices
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // Undirected graph
}

// Function to print the adjacency matrix of the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Greedy algorithm for graph coloring
void greedyGraphColoring(Graph* graph) {
    int result[MAX_VERTICES]; // Store colors assigned to vertices
    for (int i = 0; i < graph->numVertices; i++) {
        result[i] = -1; // Initialize all vertices as uncolored
    }

    result[0] = 0; // Assign the first color to the first vertex

    // Temporary array to store the available colors
    int available[MAX_VERTICES];
    for (int u = 0; u < graph->numVertices; u++) {
        available[u] = 1; // Mark all colors as available
    }

    // Assign colors to remaining vertices
    for (int u = 1; u < graph->numVertices; u++) {
        // Mark colors of adjacent vertices as unavailable
        for (int v = 0; v < graph->numVertices; v++) {
            if (graph->adjMatrix[u][v] == 1 && result[v] != -1) {
                available[result[v]] = 0; // Color is not available
            }
        }

        // Find the first available color
        int cr;
        for (cr = 0; cr < graph->numVertices; cr++) {
            if (available[cr]) {
                break;
            }
        }
        result[u] = cr; // Assign the found color to vertex u

        // Reset the available array for the next iteration
        for (int v = 0; v < graph->numVertices; v++) {
            if (graph->adjMatrix[u][v] == 1 && result[v] != -1) {
                available[result[v]] = 1; // Restore availability
            }
        }
    }

    // Print the result
    printf("Vertex Color Assignment:\n");
    for (int u = 0; u < graph->numVertices; u++) {
        printf("Vertex %d --> Color %d\n", u, result[u]);
    }
}

// Main function to execute the program
int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    // Creating a sample graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Adjacency Matrix of the Graph:\n");
    printGraph(graph);

    greedyGraphColoring(graph);

    free(graph); // Freeing allocated memory
    return 0;
}