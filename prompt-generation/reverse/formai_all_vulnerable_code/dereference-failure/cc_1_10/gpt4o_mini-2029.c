//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a graph
typedef struct Graph {
    int V; // Number of vertices
    int **adjMatrix; // Adjacency matrix
} Graph;

// Create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)calloc(V, sizeof(int));
    }
    
    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Directed graph
    graph->adjMatrix[dest][src] = 1; // For undirected graph behavior
}

// Print the graph's adjacency matrix
void printGraph(Graph* graph) {
    printf("Adjacency Matrix of the Graph:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Depth First Search algorithm
void DFSUtil(Graph* graph, int v, int *visited) {
    visited[v] = 1;
    printf("%d ", v);
    
    for (int i = 0; i < graph->V; i++) {
        if (graph->adjMatrix[v][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Call Depth First Search
void DFS(Graph* graph) {
    int *visited = (int*)calloc(graph->V, sizeof(int));
    printf("Depth First Traversal starting from vertex 0:\n");
    DFSUtil(graph, 0, visited);
    printf("\n");
    free(visited);
}

// Breadth First Search algorithm
void BFS(Graph* graph) {
    int *visited = (int*)calloc(graph->V, sizeof(int));
    int *queue = (int*)malloc(graph->V * sizeof(int));
    int front = -1, rear = -1;

    visited[0] = 1;
    queue[++rear] = 0;

    printf("Breadth First Traversal starting from vertex 0:\n");
    
    while (front != rear) {
        front++;
        int v = queue[front];
        printf("%d ", v);
        
        for (int i = 0; i < graph->V; i++) {
            if (graph->adjMatrix[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
    free(visited);
    free(queue);
}

// Free the graph's memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    // The curious case of the London Underground
    int numOfStations = 7;
    Graph* underground = createGraph(numOfStations);
    
    // Adding edges to denote direct connections between stations
    addEdge(underground, 0, 1); // Baker Street - 221B
    addEdge(underground, 0, 3); // Holborn
    addEdge(underground, 1, 2); // King's Cross
    addEdge(underground, 1, 4); // Oxford Circus
    addEdge(underground, 2, 5); // Farringdon
    addEdge(underground, 3, 4); // Covent Garden
    addEdge(underground, 4, 5); // Tottenham Court Road
    addEdge(underground, 5, 6); // Liverpool Street

    // Print the graph
    printGraph(underground);
    
    // Begin the traversals
    DFS(underground);
    BFS(underground);

    // Free allocated memory
    freeGraph(underground);
    
    printf("The underground puzzle was successfully solved, Watson!\n");
    return 0;
}