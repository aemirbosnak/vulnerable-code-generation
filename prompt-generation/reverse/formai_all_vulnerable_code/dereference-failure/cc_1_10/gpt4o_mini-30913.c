//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int numVertices;
    int** adjMatrix;
};

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        
        // Initialize adjacency matrix with 0s
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int startVertex, int endVertex) {
    graph->adjMatrix[startVertex][endVertex] = 1;
    graph->adjMatrix[endVertex][startVertex] = 1; // Uncomment for undirected graph
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

// Helper function for depth-first search
void DFSUtil(int v, int visited[], struct Graph* graph) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[v][i] && !visited[i]) {
            DFSUtil(i, visited, graph);
        }
    }
}

// Function to perform depth-first search
void DFS(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize visited array
    }

    DFSUtil(startVertex, visited, graph);
    free(visited);
}

// Helper function for breadth-first search
void BFS(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize visited array
    }

    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currVertex = queue[front++];
        printf("%d ", currVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currVertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    free(visited);
    free(queue);
}

// Function to free the memory allocated for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

// Main function to demonstrate the graph operations
int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    // Adding edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    printf("Depth-First Search starting from vertex 0:\n");
    DFS(graph, 0);
    printf("\n");

    printf("Breadth-First Search starting from vertex 0:\n");
    BFS(graph, 0);
    printf("\n");

    freeGraph(graph);
    return 0;
}