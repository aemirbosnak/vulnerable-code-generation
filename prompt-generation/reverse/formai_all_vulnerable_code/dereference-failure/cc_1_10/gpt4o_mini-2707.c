//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    // Initialize the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge in the graph
void addEdge(Graph* graph, int start, int end) {
    if (start >= 0 && start < graph->numVertices && end >= 0 && end < graph->numVertices) {
        graph->adjMatrix[start][end] = 1; // Directed graph
        graph->adjMatrix[end][start] = 1; // Uncomment for undirected graph
    } else {
        printf("Invalid edge!\n");
    }
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("Graph representation (Adjacency Matrix):\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Depth First Search
void DFSUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to initiate DFS Traverse
void DFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    DFSUtil(graph, startVertex, visited);
}

// Function to perform Breadth First Search
void BFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

// Driver program to demonstrate graph
int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
    
    printf("\nDFS starting from vertex 0:\n");
    DFS(graph, 0);

    printf("\n\nBFS starting from vertex 0:\n");
    BFS(graph, 0);

    free(graph);
    return 0;
}