//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0; // Initialize adjacency matrix with zero
        }
    }
    return graph;
}

void addEdge(Graph* graph, int from, int to) {
    graph->adjacencyMatrix[from][to] = 1; // Add edge from `from` to `to`
    graph->adjacencyMatrix[to][from] = 1; // As it's undirected, add edge both ways
}

void removeEdge(Graph* graph, int from, int to) {
    graph->adjacencyMatrix[from][to] = 0; // Remove edge from `from` to `to`
    graph->adjacencyMatrix[to][from] = 0; // As it's undirected, remove edge both ways
}

void displayGraph(Graph* graph) {
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void depthFirstSearchUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the current vertex as visited
    printf("%d ", vertex); // Print the vertex

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            depthFirstSearchUtil(graph, i, visited); // Recursive DFS call
        }
    }
}

void depthFirstSearch(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Initialize visited array
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    depthFirstSearchUtil(graph, startVertex, visited);
    printf("\n");
}

void breadthFirstSearch(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Initialize visited array
    int queue[MAX_VERTICES], front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex; // Enqueue the starting vertex

    printf("Breadth First Search starting from vertex %d:\n", startVertex);

    while (front < rear) {
        int currentVertex = queue[front++]; // Dequeue vertex

        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i; // Enqueue the adjacent vertex
            }
        }
    }
    printf("\n");
}

void destroyGraph(Graph* graph) {
    free(graph); // Free allocated memory for graph
}

int main() {
    int numVertices = 5; // Change this for larger graphs
    Graph* graph = createGraph(numVertices);

    // Create a simple graph: 
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    displayGraph(graph);
    
    depthFirstSearch(graph, 0);
    breadthFirstSearch(graph, 0);

    removeEdge(graph, 1, 3);
    printf("After removing edge between 1 and 3:\n");
    displayGraph(graph);

    destroyGraph(graph); // Clean up
    return 0;
}