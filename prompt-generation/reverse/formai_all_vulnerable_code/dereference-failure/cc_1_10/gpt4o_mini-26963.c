//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0; // Initialize to 0
        }
    }
    return graph;
}

// Function to add an edge
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1; // For undirected graph
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("Adjacency Matrix of the Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform a Depth-First Search (DFS)
void DFS(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Function to perform DFS traversal
void DFS_Traversal(Graph* graph) {
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Function to perform BFS traversal
void BFS_Traversal(Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            // Start BFS from this vertex
            visited[i] = 1;
            queue[++rear] = i; // Enqueue the vertex
            printf("Visited %d\n", i);

            while (front < rear) {
                front++;
                int currentVertex = queue[front];

                for (int j = 0; j < graph->numVertices; j++) {
                    if (graph->adjacencyMatrix[currentVertex][j] == 1 && !visited[j]) {
                        visited[j] = 1;
                        queue[++rear] = j; // Enqueue
                        printf("Visited %d\n", j);
                    }
                }
            }
        }
    }
}

int main() {
    int vertices;
    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    Graph* graph = createGraph(vertices);

    int edges;
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            printf("Invalid edge!\n");
            i--; // Decrement to allow for re-entry
            continue;
        }
        addEdge(graph, src, dest);
    }

    printGraph(graph);
    printf("\nDFS Traversal:\n");
    DFS_Traversal(graph);

    printf("\nBFS Traversal:\n");
    BFS_Traversal(graph);

    free(graph);
    return 0;
}