//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Initialize the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // No edge exists initially
        }
    }

    return graph;
}

void addEdge(Graph* graph, int startVertex, int endVertex) {
    graph->adjMatrix[startVertex][endVertex] = 1; // Mark the edge from start to end
    graph->adjMatrix[endVertex][startVertex] = 1; // Mark the edge from end to start (undirected graph)
}

void printGraph(Graph* graph) {
    printf("Adjacency Matrix of the Graph:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void depthFirstSearch(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the current vertex as visited
    printf("%d ", vertex); // Print the vertex

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            depthFirstSearch(graph, i, visited);
        }
    }
}

void breadthFirstSearch(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    visited[startVertex] = 1; // Mark the starting vertex as visited
    queue[++rear] = startVertex; // Enqueue the starting vertex

    printf("BFS from vertex %d: ", startVertex);
    while (front <= rear) {
        int currentVertex = queue[front++]; // Dequeue a vertex

        printf("%d ", currentVertex); // Print the current vertex

        // Enqueue all unvisited adjacent vertices
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark as visited
                queue[++rear] = i; // Enqueue
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices = 5; // Number of vertices in the graph
    Graph* graph = createGraph(vertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency matrix of the graph
    printGraph(graph);

    // Create an array to keep track of visited vertices for DFS
    int visited[MAX_VERTICES] = {0};

    // Perform DFS starting from vertex 0
    printf("DFS starting from vertex 0: ");
    depthFirstSearch(graph, 0, visited);
    printf("\n");

    // Perform BFS starting from vertex 0
    breadthFirstSearch(graph, 0);

    // Free allocated memory
    free(graph);

    return 0;
}