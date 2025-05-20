//FormAI DATASET v1.0 Category: Graph representation ; Style: content
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertexIndex;
    int numEdges;
    int edges[MAX_VERTICES];
} Vertex;

typedef struct {
    Vertex vertices[MAX_VERTICES];
    int numVertices;
} Graph;

void addVertex(Graph* graph, int vertex) {
    graph->vertices[graph->numVertices].vertexIndex = vertex;
    graph->vertices[graph->numVertices].numEdges = 0;
    graph->numVertices++;
}

void addEdge(Graph* graph, int start, int end) {
    graph->vertices[start].edges[graph->vertices[start].numEdges] = end;
    graph->vertices[start].numEdges++;
}

void printGraph(Graph* graph) {
    printf("Vertices: ");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d ", graph->vertices[i].vertexIndex);
    }
    printf("\nEdges:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("  %d -> ", graph->vertices[i].vertexIndex);
        for (int j = 0; j < graph->vertices[i].numEdges; j++) {
            printf("%d ", graph->vertices[i].edges[j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = 0;

    addVertex(graph, 0);
    addVertex(graph, 1);
    addVertex(graph, 2);
    addVertex(graph, 3);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    printGraph(graph);

    free(graph);
    return 0;
}