//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void removeEdge(Graph* graph, int src, int dest);
void displayGraph(Graph* graph);
void freeGraph(Graph* graph);
bool isEdge(Graph* graph, int src, int dest);
void depthFirstSearch(Graph* graph, int startVertex, bool visited[]);
void breadthFirstSearch(Graph* graph, int startVertex);
void findShortestPath(Graph* graph, int startVertex, int endVertex);
void printPath(int parent[], int j);

// Main function
int main() {
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Graph adjacency matrix:\n");
    displayGraph(graph);

    printf("\nDFS starting from vertex 0:\n");
    bool visited[MAX_VERTICES] = {false};
    depthFirstSearch(graph, 0, visited);

    printf("\nBFS starting from vertex 0:\n");
    breadthFirstSearch(graph, 0);

    printf("\nShortest path from vertex 0 to vertex 3:\n");
    findShortestPath(graph, 0, 3);
    
    removeEdge(graph, 1, 3);
    printf("\nGraph adjacency matrix after removing edge (1, 3):\n");
    displayGraph(graph);

    freeGraph(graph);
    return 0;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph->adjacencyMatrix[i][j] = 0;

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1; // for undirected graph
}

// Function to remove an edge from the graph
void removeEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 0;
    graph->adjacencyMatrix[dest][src] = 0; // for undirected graph
}

// Function to display the graph's adjacency matrix
void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
void freeGraph(Graph* graph) {
    free(graph);
}

// Function to check if there is an edge between two vertices
bool isEdge(Graph* graph, int src, int dest) {
    return graph->adjacencyMatrix[src][dest] != 0;
}

// DFS utility function
void depthFirstSearch(Graph* graph, int startVertex, bool visited[]) {
    visited[startVertex] = true;
    printf("%d ", startVertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (isEdge(graph, startVertex, i) && !visited[i]) {
            depthFirstSearch(graph, i, visited);
        }
    }
}

// BFS function
void breadthFirstSearch(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES], front = 0, rear = -1;

    visited[startVertex] = true;
    queue[++rear] = startVertex;

    while (front <= rear) {
        int currentVertex = queue[front++];

        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (isEdge(graph, currentVertex, i) && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

// Function to find the shortest path using BFS
void findShortestPath(Graph* graph, int startVertex, int endVertex) {
    int parent[MAX_VERTICES];
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES], front = 0, rear = -1;

    for (int i = 0; i < graph->numVertices; i++)
        parent[i] = -1;

    visited[startVertex] = true;
    queue[++rear] = startVertex;

    while (front <= rear) {
        int currentVertex = queue[front++];

        if (currentVertex == endVertex) {
            printPath(parent, endVertex);
            return;
        }

        for (int i = 0; i < graph->numVertices; i++) {
            if (isEdge(graph, currentVertex, i) && !visited[i]) {
                visited[i] = true;
                parent[i] = currentVertex;
                queue[++rear] = i;
            }
        }
    }

    printf("No path exists\n");
}

// Helper function to print the path from start to end vertex
void printPath(int parent[], int j) {
    if (j == -1)
        return;

    printPath(parent, parent[j]);
    printf("%d ", j);
}