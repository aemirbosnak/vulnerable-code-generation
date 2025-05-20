//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Define a structure for an edge in the graph
typedef struct Edge {
    int src, dest;
} Edge;

// Define a structure for the graph
typedef struct Graph {
    int V, E; // Number of vertices and edges
    Edge* edges; // Array of edges
} Graph;

// Create a graph with V vertices and E edges
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("Graph representation:\n");
    for (int i = 0; i < graph->E; i++) {
        printf("Edge %d: %d -> %d\n", i, graph->edges[i].src, graph->edges[i].dest);
    }
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int index, int src, int dest) {
    if (index < graph->E) {
        graph->edges[index].src = src;
        graph->edges[index].dest = dest;
    } else {
        printf("Index out of bounds while adding edge\n");
    }
}

// Function to perform Depth First Search from a given vertex
void DFSUtil(int v, int visited[], Graph* graph) {
    visited[v] = 1;
    printf("%d ", v);
    
    for (int i = 0; i < graph->E; i++) {
        if (graph->edges[i].src == v && !visited[graph->edges[i].dest]) {
            DFSUtil(graph->edges[i].dest, visited, graph);
        }
    }
}

// Function to initiate DFS traversal
void DFS(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    DFSUtil(startVertex, visited, graph);
    printf("\n");
    free(visited);
}

// Function to perform Breadth First Search from a given vertex
void BFS(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    int* queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Breadth First Search starting from vertex %d:\n", startVertex);
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < graph->E; i++) {
            if (graph->edges[i].src == current && !visited[graph->edges[i].dest]) {
                visited[graph->edges[i].dest] = 1;
                queue[rear++] = graph->edges[i].dest;
            }
        }
    }
    printf("\n");
    free(visited);
    free(queue);
}

// Main function to demonstrate the graph operations
int main() {
    int V = 5; // Number of vertices
    int E = 7; // Number of edges

    Graph* graph = createGraph(V, E);
    
    // Adding edges - create a simple graph
    addEdge(graph, 0, 0, 1);
    addEdge(graph, 1, 0, 4);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 3, 1, 3);
    addEdge(graph, 4, 3, 4);
    addEdge(graph, 5, 2, 3);
    addEdge(graph, 6, 4, 2);

    // Print the graph
    printGraph(graph);

    // Perform DFS starting from vertex 0
    DFS(graph, 0);

    // Perform BFS starting from vertex 0
    BFS(graph, 0);

    // Free allocated resources
    free(graph->edges);
    free(graph);
    
    return 0;
}