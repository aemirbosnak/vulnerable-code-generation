//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

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
void addEdge(Graph* graph, int start, int end) {
    if (start >= 0 && start < graph->numVertices && end >= 0 && end < graph->numVertices) {
        graph->adjMatrix[start][end] = true;
        graph->adjMatrix[end][start] = true; // For undirected graph
    } else {
        fprintf(stderr, "Error adding edge: Vertex out of bounds\n");
    }
}

// Function to display the adjacency matrix
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix for the graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Depth First Search (DFS)
void dfsUtil(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] && !visited[i]) {
            dfsUtil(graph, i, visited);
        }
    }
}

// Function to initiate DFS traversal from a given starting vertex
void depthFirstSearch(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    dfsUtil(graph, startVertex, visited);
    printf("\n");
}

// Function to perform Breadth First Search (BFS)
void breadthFirstSearch(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[startVertex] = true;
    queue[++rear] = startVertex;

    printf("Breadth First Search starting from vertex %d:\n", startVertex);
    
    while (front != rear) {
        front++;
        int currentVertex = queue[front];
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

// Function to free memory allocated for the graph
void freeGraph(Graph* graph) {
    free(graph);
}

// Main function to test the graph implementation
int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 2);
    addEdge(graph, 4, 3);

    displayGraph(graph);
    
    depthFirstSearch(graph, 0);
    
    breadthFirstSearch(graph, 0);

    freeGraph(graph);

    return 0;
}