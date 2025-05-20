//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int numVertices;
    int **adjMatrix;
};

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
    }

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;  // For directed graph
    // Uncomment the next line for an undirected graph
    // graph->adjMatrix[dest][src] = 1;
}

// Function to print the adjacency matrix
void printGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Depth First Search (DFS)
void dfsUtil(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;  // Mark the vertex as visited
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfsUtil(graph, i, visited);
        }
    }
}

// Function to perform DFS on the graph
void depthFirstSearch(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;  // Initialize visited array
    }

    printf("Depth First Search starting from vertex %d:\n", startVertex);
    dfsUtil(graph, startVertex, visited);
    printf("\n");

    free(visited);  // Free allocated memory
}

// Function to perform Breadth First Search (BFS)
void breadthFirstSearch(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;  // Initialize visited array
    }

    visited[startVertex] = 1;  // Mark the starting vertex as visited
    queue[rear++] = startVertex;  // Enqueue starting vertex

    printf("Breadth First Search starting from vertex %d:\n", startVertex);
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;  // Mark as visited
                queue[rear++] = i;  // Enqueue the adjacent vertex
            }
        }
    }
    printf("\n");

    free(visited);  // Free allocated memory
    free(queue);    // Free allocated memory
}

// Main function
int main() {
    int vertices = 5;  // Define number of vertices
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    depthFirstSearch(graph, 0);
    breadthFirstSearch(graph, 0);

    // Free adjacency matrix memory
    for (int i = 0; i < vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

    return 0;
}