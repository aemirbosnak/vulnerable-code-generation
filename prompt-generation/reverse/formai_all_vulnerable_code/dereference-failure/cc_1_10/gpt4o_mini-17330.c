//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function to initialize a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Initialize the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0; // No edges initially
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int start, int end) {
    if (start >= 0 && start < graph->numVertices && 
        end >= 0 && end < graph->numVertices) {
        graph->adjacencyMatrix[start][end] = 1; // Directed graph
    } else {
        printf("Invalid edge between %d and %d\n", start, end);
    }
}

// Function to display the graph's adjacency matrix
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform a Depth First Search on the graph
void DFSUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the current vertex as visited
    printf("%d ", vertex); // Print the visited vertex

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited); // Recursive call
        }
    }
}

// Function to initiate DFS for graph traversal
void depthFirstSearch(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices
    printf("DFS starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

// Function to perform a Breadth First Search on the graph
void breadthFirstSearch(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex; // Enqueue the start vertex
    printf("BFS starting from vertex %d: ", startVertex);

    while (front < rear) {
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Marking as visited
                queue[++rear] = i; // Enqueue the adjacent vertex
            }
        }
    }
    printf("\n");
}

// Function to free the graph's allocated memory
void freeGraph(Graph* graph) {
    free(graph);
}

int main() {
    int numVertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int start, end;
        printf("Enter edge %d (start end): ", i + 1);
        scanf("%d %d", &start, &end);
        addEdge(graph, start, end);
    }

    displayGraph(graph);

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    depthFirstSearch(graph, startVertex);
    
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    breadthFirstSearch(graph, startVertex);
    
    freeGraph(graph);
    return 0;
}