//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// A structure to represent a graph
typedef struct Graph {
    int numVertices;
    int numEdges;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// A utility function to create a new graph
Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// A utility function to add an edge to a graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// A utility function to print the adjacency matrix of a graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// A utility function to check if a graph is bipartite
bool isBipartite(Graph* graph) {
    int color[MAX_VERTICES];

    // Initialize all vertices as unassigned
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = -1;
    }

    // Assign colors to vertices
    color[0] = 0;
    for (int i = 1; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] == 1 && color[i] == color[j]) {
                return false;
            }
        }
        color[i] = 1 - color[i];
    }

    return true;
}

// Driver code to test the above functions
int main() {
    // Create a graph with 4 vertices and 4 edges
    Graph* graph = createGraph(4, 4);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Print the adjacency matrix of the graph
    printGraph(graph);

    // Check if the graph is bipartite
    bool is_bipartite = isBipartite(graph);

    if (is_bipartite) {
        printf("The graph is bipartite\n");
    } else {
        printf("The graph is not bipartite\n");
    }

    return 0;
}