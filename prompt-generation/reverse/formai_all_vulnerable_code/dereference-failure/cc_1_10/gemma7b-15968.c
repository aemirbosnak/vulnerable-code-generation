//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Graph {
    int **adjList;
    int numVertices;
    int numEdges;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (int**)malloc(numVertices * sizeof(int*));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = (int*)malloc(MAX * sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjList[src][graph->numEdges++] = dest;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numEdges; j++) {
            if (graph->adjList[i][j] != 0) {
                printf("%d ", graph->adjList[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    traverseGraph(graph);

    free(graph->adjList);
    free(graph);

    return 0;
}