//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define a structure for an edge in the graph
typedef struct Edge {
    int src, dest;
} Edge;

// Define a structure for a graph
typedef struct Graph {
    int V, E; // Number of vertices and edges
    Edge* edges; // Array of edges
} Graph;

// Function to create a graph
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int index) {
    graph->edges[index].src = src;
    graph->edges[index].dest = dest;
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("Graph adjacency list representation:\n");
    for (int i = 0; i < graph->E; i++) {
        printf("%d -- %d\n", graph->edges[i].src, graph->edges[i].dest);
    }
}

// Function to perform Depth First Search (DFS) from a given vertex
void DFSUtil(int v, int visited[], Graph* graph) {
    visited[v] = 1; // Mark the current vertex as visited
    printf("%d ", v); // Print the vertex

    // Explore each adjacent vertex
    for (int i = 0; i < graph->E; i++) {
        if (graph->edges[i].src == v && !visited[graph->edges[i].dest]) {
            DFSUtil(graph->edges[i].dest, visited, graph);
        }
    }
}

// Function to perform DFS traversal from a source vertex
void DFS(Graph* graph, int startVertex) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    printf("Depth First Traversal starting from vertex %d:\n", startVertex);
    DFSUtil(startVertex, visited, graph);
    free(visited);
}

// Function to perform Breadth First Search (BFS) from a given vertex
void BFS(Graph* graph, int startVertex) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    int* queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = 1; // Mark the starting node as visited
    queue[rear++] = startVertex; // Add it to the queue

    printf("\nBreadth First Traversal starting from vertex %d:\n", startVertex);
    while (front < rear) {
        int currentVertex = queue[front++]; // Dequeue the vertex
        printf("%d ", currentVertex); // Print the current vertex

        // Explore each adjacent vertex
        for (int i = 0; i < graph->E; i++) {
            if (graph->edges[i].src == currentVertex && !visited[graph->edges[i].dest]) {
                visited[graph->edges[i].dest] = 1; // Mark as visited
                queue[rear++] = graph->edges[i].dest; // Enqueue
            }
        }
    }
    free(visited);
    free(queue);
}

// Main function to demonstrate the graph functionalities
int main() {
    int V = 5; // Number of vertices in the graph
    int E = 7; // Number of edges in the graph

    // Create a graph with V vertices and E edges
    Graph* graph = createGraph(V, E);

    // Adding edges to the graph
    addEdge(graph, 0, 1, 0);
    addEdge(graph, 0, 4, 1);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 1, 4, 4);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 3, 4, 6);

    // Print the graph representation
    printGraph(graph);
    
    // Perform DFS and BFS traversals
    DFS(graph, 0);
    BFS(graph, 0);

    // Clean up the allocated memory
    free(graph->edges);
    free(graph);

    return 0;
}