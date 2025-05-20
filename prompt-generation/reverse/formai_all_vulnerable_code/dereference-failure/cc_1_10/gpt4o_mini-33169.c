//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define the structure for an edge in the graph
typedef struct Edge {
    int src, dest;
} Edge;

// Define the structure for a graph
typedef struct Graph {
    int V, E;
    Edge* edges;
} Graph;

// Function to create a graph with V vertices and E edges
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

// Function to print the graph edges
void printGraph(Graph* graph) {
    printf("Graph edges:\n");
    for (int i = 0; i < graph->E; i++) {
        printf("Edge %d: (%d, %d)\n", i + 1, graph->edges[i].src, graph->edges[i].dest);
    }
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int edgeIndex) {
    if (edgeIndex < graph->E) {
        graph->edges[edgeIndex].src = src;
        graph->edges[edgeIndex].dest = dest;
    } else {
        printf("Edge index out of bounds!\n");
    }
}

// Function to perform DFS traversal from a given vertex
void DFSUtil(int v, int visited[], Graph* graph) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < graph->E; i++) {
        if (graph->edges[i].src == v && !visited[graph->edges[i].dest]) {
            DFSUtil(graph->edges[i].dest, visited, graph);
        } else if (graph->edges[i].dest == v && !visited[graph->edges[i].src]) {
            DFSUtil(graph->edges[i].src, visited, graph);
        }
    }
}

// Function to invoke DFS traversal from a vertex
void DFS(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }
    printf("DFS traversal starting from vertex %d: ", startVertex);
    DFSUtil(startVertex, visited, graph);
    printf("\n");
    free(visited);
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    free(graph->edges);
    free(graph);
}

// Main function
int main() {
    int V = 5; // Number of vertices
    int E = 7; // Number of edges

    Graph* graph = createGraph(V, E);

    // Add edges to the graph
    addEdge(graph, 0, 1, 0);
    addEdge(graph, 0, 4, 1);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 1, 4, 4);
    addEdge(graph, 3, 4, 5);
    addEdge(graph, 2, 3, 6);

    // Print the graph
    printGraph(graph);

    // Perform DFS from vertex 0
    DFS(graph, 0);

    // Free the graph memory
    freeGraph(graph);

    return 0;
}