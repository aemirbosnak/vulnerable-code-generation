//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_VERTICES 100

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int **adjacencyMatrix;
} Graph;

// Structure for thread parameters
typedef struct ThreadParams {
    Graph *graph;
    int vertex;
    int *visited;
} ThreadParams;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjacencyMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyMatrix[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0; // Initialize all edges to 0
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1; // Directed edge
}

// Function to print the graph
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d -> ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjacencyMatrix[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Function for each thread to explore a vertex
void *exploreVertex(void *params) {
    ThreadParams *p = (ThreadParams *)params;
    Graph *graph = p->graph;
    int vertex = p->vertex;
    int *visited = p->visited;

    if (visited[vertex] == 0) {
        visited[vertex] = 1;
        printf("Thread %ld: Exploring vertex %d\n", pthread_self(), vertex);

        // Explore all connected vertices
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[vertex][i] && !visited[i]) {
                ThreadParams *newParams = (ThreadParams *)malloc(sizeof(ThreadParams));
                newParams->graph = graph;
                newParams->vertex = i;
                newParams->visited = visited;

                pthread_t thread;
                pthread_create(&thread, NULL, exploreVertex, newParams);
                pthread_detach(thread); // Detach to manage the thread automatically
            }
        }
    }
    return NULL;
}

// Main function
int main() {
    int vertices = 5;

    // Create and populate the graph
    Graph *graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);

    printf("Graph:\n");
    printGraph(graph);

    // Array to keep track of visited vertices
    int *visited = (int *)malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0; // Mark all as unvisited
    }

    // Start exploring from vertex 0
    ThreadParams *initialParams = (ThreadParams *)malloc(sizeof(ThreadParams));
    initialParams->graph = graph;
    initialParams->vertex = 0;
    initialParams->visited = visited;

    pthread_t initialThread;
    pthread_create(&initialThread, NULL, exploreVertex, initialParams);
    pthread_join(initialThread, NULL); // Wait for the initial thread to finish

    // Cleanup
    free(visited);
    for (int i = 0; i < vertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);

    return 0;
}