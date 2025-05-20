//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Alan Turing
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
            g->adjMatrix[i][j] = 0; // Initialize the adjacency matrix
        }
    }
    return g;
}

void addEdge(Graph* g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices || src < 0 || dest < 0) {
        printf("Error: Invalid vertex.\n");
        return;
    }
    g->adjMatrix[src][dest] = 1; // Add edge from src to dest
    g->adjMatrix[dest][src] = 1; // Since this is an undirected graph
}

void removeEdge(Graph* g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices || src < 0 || dest < 0) {
        printf("Error: Invalid vertex.\n");
        return;
    }
    g->adjMatrix[src][dest] = 0; // Remove edge
    g->adjMatrix[dest][src] = 0; // Remove edge in both directions
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j] == 1) {
                printf("-> %d ", j);
            }
        }
        printf("\n");
    }
}

int isConnected(Graph* g) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES], top = -1;

    visited[0] = 1; // Start with the first vertex
    stack[++top] = 0;

    while (top >= 0) {
        int current = stack[top--];
        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }

    for (int i = 0; i < g->numVertices; i++) {
        if (!visited[i]) {
            return 0; // Not connected
        }
    }
    return 1; // Connected
}

void freeGraph(Graph* g) {
    free(g);
}

int main() {
    int vertices = 5;
    Graph* g = createGraph(vertices);

    printf("Adding edges...\n");
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);

    printf("Graph representation:\n");
    printGraph(g);

    printf("Checking if the graph is connected...\n");
    if (isConnected(g)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    printf("Removing edge between vertex 1 and 2...\n");
    removeEdge(g, 1, 2);
    printGraph(g);

    printf("Checking if the graph is still connected...\n");
    if (isConnected(g)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    freeGraph(g);
    return 0;
}