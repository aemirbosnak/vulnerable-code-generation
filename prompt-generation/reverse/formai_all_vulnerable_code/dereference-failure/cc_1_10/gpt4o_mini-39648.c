//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100 

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = false;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int startVertex, int endVertex) {
    if (startVertex < graph->numVertices && endVertex < graph->numVertices) {
        graph->adjMatrix[startVertex][endVertex] = true;
        graph->adjMatrix[endVertex][startVertex] = true; // For undirected graph
    } else {
        printf("Error: Vertex index out of bounds.\n");
    }
}

// Function to print the adjacency matrix of the graph
void printGraph(Graph* graph) {
    printf("Adjacency Matrix of the graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j] ? 1 : 0);
        }
        printf("\n");
    }
}

// Function to perform Depth First Search (DFS)
void DFSUtil(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to initiate DFS from a given vertex
void DFS(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    printf("DFS starting from vertex %d:\n", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

// Function for Breadth First Search (BFS)
void BFS(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES], front = 0, rear = -1;

    visited[startVertex] = true;
    queue[++rear] = startVertex;

    printf("BFS starting from vertex %d:\n", startVertex);
    
    while (front <= rear) {
        int currentVertex = queue[front++];

        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

// Function to delete the graph and free allocated memory
void deleteGraph(Graph* graph) {
    free(graph);
}

// Main function
int main() {
    int numVertices = 5;
    Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    DFS(graph, 0);
    BFS(graph, 0);

    deleteGraph(graph);
    return 0;
}