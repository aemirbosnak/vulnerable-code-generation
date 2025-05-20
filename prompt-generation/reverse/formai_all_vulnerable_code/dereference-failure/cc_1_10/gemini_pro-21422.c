//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// A graph edge
typedef struct Edge {
    int source;
    int destination;
    int weight;
} Edge;

// A graph
typedef struct Graph {
    int numVertices;
    int numEdges;
    Edge* edges;
} Graph;

// Create a new graph with numVertices vertices and numEdges edges
Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = (Edge*)malloc(numEdges * sizeof(Edge));
    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int source, int destination, int weight) {
    Edge edge;
    edge.source = source;
    edge.destination = destination;
    edge.weight = weight;
    graph->edges[graph->numEdges++] = edge;
}

// Print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numEdges; i++) {
        Edge edge = graph->edges[i];
        printf("Edge %d: %d -> %d (%d)\n", i, edge.source, edge.destination, edge.weight);
    }
}

// Free the graph
void freeGraph(Graph* graph) {
    free(graph->edges);
    free(graph);
}

// Main function
int main() {
    // Create a graph with 5 vertices and 7 edges
    Graph* graph = createGraph(5, 7);

    // Add edges to the graph
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 20);
    addEdge(graph, 1, 2, 30);
    addEdge(graph, 1, 3, 40);
    addEdge(graph, 1, 4, 50);
    addEdge(graph, 2, 3, 60);
    addEdge(graph, 3, 4, 70);

    // Print the graph
    printGraph(graph);

    // Free the graph
    freeGraph(graph);

    return 0;
}