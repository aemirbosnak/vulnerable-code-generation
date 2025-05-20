//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int **adjMatrix;
    int numVertices;
} Graph;

Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)calloc(vertices, sizeof(int));
    }

    return graph;
}

void addEdge(Graph *graph, int startVertex, int endVertex) {
    if (startVertex < graph->numVertices && endVertex < graph->numVertices) {
        graph->adjMatrix[startVertex][endVertex] = 1;
        graph->adjMatrix[endVertex][startVertex] = 1; // For undirected graph
    } else {
        fprintf(stderr, "Error: Vertex number exceeds limit.\n");
    }
}

void removeEdge(Graph *graph, int startVertex, int endVertex) {
    if (startVertex < graph->numVertices && endVertex < graph->numVertices) {
        graph->adjMatrix[startVertex][endVertex] = 0;
        graph->adjMatrix[endVertex][startVertex] = 0; // For undirected graph
    } else {
        fprintf(stderr, "Error: Vertex number exceeds limit.\n");
    }
}

void displayGraph(Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

void dfsUtil(Graph *graph, int vertex, int *visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfsUtil(graph, i, visited);
        }
    }
}

void depthFirstSearch(Graph *graph, int startVertex) {
    int *visited = (int *)calloc(graph->numVertices, sizeof(int));
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    dfsUtil(graph, startVertex, visited);
    printf("\n");
    free(visited);
}

int main() {
    int vertexCount = 5;
    Graph *graph = createGraph(vertexCount);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    displayGraph(graph);

    depthFirstSearch(graph, 0);

    removeEdge(graph, 0, 1);
    printf("After removing edge (0, 1):\n");
    displayGraph(graph);

    freeGraph(graph);
    return 0;
}