//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Graph data structure
typedef struct Graph {
    int V;                 // Number of vertices
    int E;                 // Number of edges
    struct Edge* edge;     // Array of edges
} Graph;

// Edge data structure
typedef struct Edge {
    int src;             // Source vertex
    int dest;            // Destination vertex
    int weight;          // Weight of the edge
} Edge;

// Create a new graph
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*) malloc(graph->E * sizeof(Edge));
    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->edge[graph->E].src = src;
    graph->edge[graph->E].dest = dest;
    graph->edge[graph->E].weight = weight;
    graph->E++;
}

// Print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->E; i++) {
        printf("%d -> %d (%d)\n", graph->edge[i].src, graph->edge[i].dest, graph->edge[i].weight);
    }
}

// Main function
int main() {
    // Create a new graph
    Graph* graph = createGraph(5, 7);

    // Add edges to the graph
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 20);
    addEdge(graph, 0, 3, 30);
    addEdge(graph, 1, 2, 40);
    addEdge(graph, 1, 3, 50);
    addEdge(graph, 1, 4, 60);
    addEdge(graph, 2, 3, 70);

    // Print the graph
    printGraph(graph);

    return 0;
}