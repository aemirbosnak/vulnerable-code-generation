//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 10
#define MAX_EDGES 100

typedef struct Graph {
    int numVertices;
    int numEdges;
    int **adjList;
} Graph;

Graph *createGraph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->numEdges = 0;
    graph->adjList = NULL;

    return graph;
}

void addVertex(Graph *graph) {
    graph->numVertices++;
    graph->adjList = (int **)realloc(graph->adjList, graph->numVertices * sizeof(int *));
    graph->adjList[graph->numVertices - 1] = NULL;
}

void addEdge(Graph *graph, int src, int dest) {
    graph->numEdges++;
    graph->adjList[src] = (int *)realloc(graph->adjList[src], (graph->numEdges + 1) * sizeof(int));
    graph->adjList[src][graph->numEdges] = dest;
}

int main() {
    Graph *graph = createGraph();
    addVertex(graph);
    addVertex(graph);
    addVertex(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->adjList[i]; j++) {
            printf("%d ", graph->adjList[i][j]);
        }
        printf("\n");
    }

    return 0;
}