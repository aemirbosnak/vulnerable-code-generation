//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// An edge in an undirected graph
typedef struct Edge {
    int src, dest;
} Edge;

// A graph is a collection of vertices and edges
typedef struct Graph {
    int V;   // Number of vertices
    int E;   // Number of edges
    Edge* edge;  // Array of edges
} Graph;

// Create a graph with V vertices and E edges
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;

    graph->edge = (Edge*) malloc(graph->E * sizeof(Edge));

    return graph;
}

// A utility function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    graph->edge[graph->E].src = src;
    graph->edge[graph->E].dest = dest;
    graph->E++;
}

// A utility function to print the graph
void printGraph(Graph* graph) {
    for (int e = 0; e < graph->E; e++) {
        printf("%d -- %d\n", graph->edge[e].src, graph->edge[e].dest);
    }
}

// A DFS based function to count reachable vertices from v
int DFS(Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    int count = 1;
    for (int e = 0; e < graph->E; e++) {
        if (graph->edge[e].src == v && !visited[graph->edge[e].dest]) {
            count += DFS(graph, graph->edge[e].dest, visited);
        } else if (graph->edge[e].dest == v && !visited[graph->edge[e].src]) {
            count += DFS(graph, graph->edge[e].src, visited);
        }
    }
    return count;
}

// The main function that returns count of vertices reachable from v
int countReachableVertices(Graph* graph, int v) {
    int* visited = (int*) malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    return DFS(graph, v, visited);
}

// Driver program to test the above functions
int main() {
    // Create a graph given in the above diagram
    Graph* graph = createGraph(4, 5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    // Print the graph
    printGraph(graph);

    // Get the number of reachable vertices from vertex 2
    int reachableVertices = countReachableVertices(graph, 2);
    printf("\nNumber of reachable vertices from vertex 2: %d\n", reachableVertices);

    return 0;
}