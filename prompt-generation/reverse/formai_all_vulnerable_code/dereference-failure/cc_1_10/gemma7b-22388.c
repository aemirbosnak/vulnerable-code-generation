//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph {
    int numVertices;
    int **adjList;
} Graph;

Graph *createGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (int **)malloc(sizeof(int *) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    if (graph->adjList[src] == NULL) {
        graph->adjList[src] = (int *)malloc(sizeof(int) * graph->numVertices);
    }
    graph->adjList[src][dest] = 1;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; graph->adjList[i] && j < graph->numVertices; j++) {
            if (graph->adjList[i][j] != 0) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);

    free(graph);
    return 0;
}