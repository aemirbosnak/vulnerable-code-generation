//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0; // Initialize adjacency matrix
        }
    }
    return g;
}

void addEdge(Graph* g, int src, int dest) {
    if (src < g->numVertices && dest < g->numVertices) {
        g->adjMatrix[src][dest] = 1; // Add edge from src to dest
        g->adjMatrix[dest][src] = 1; // Since the graph is undirected
    } else {
        printf("Error: Vertex out of bounds\n");
    }
}

void displayGraph(Graph* g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void dfsUtil(Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the vertex as visited
    printf("%d ", vertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfsUtil(g, i, visited);
        }
    }
}

void DFS(Graph* g, int startVertex) {
    int* visited = (int*)malloc(g->numVertices * sizeof(int));
    for (int i = 0; i < g->numVertices; i++) {
        visited[i] = 0; // Initialize all vertices as not visited
    }

    printf("Depth First Search starting from vertex %d:\n", startVertex);
    dfsUtil(g, startVertex, visited);
    free(visited);
}

void bfs(Graph* g, int startVertex) {
    int* visited = (int*)malloc(g->numVertices * sizeof(int));
    int* queue = (int*)malloc(g->numVertices * sizeof(int));
    int front = -1;
    int rear = -1;

    for (int i = 0; i < g->numVertices; i++) {
        visited[i] = 0; // Initialize all vertices as not visited
    }

    visited[startVertex] = 1; // Mark the start vertex as visited
    queue[++rear] = startVertex; // Enqueue the start vertex

    printf("Breadth First Search starting from vertex %d:\n", startVertex);
    
    while (front != rear) {
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark as visited
                queue[++rear] = i; // Enqueue
            }
        }
    }
    
    free(visited);
    free(queue);
}

int main() {
    int vertices = 5;
    Graph* g = createGraph(vertices);

    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);

    displayGraph(g);

    DFS(g, 0);
    printf("\n");

    bfs(g, 0);
    printf("\n");

    free(g);
    return 0;
}