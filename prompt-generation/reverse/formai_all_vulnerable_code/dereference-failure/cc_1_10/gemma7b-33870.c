//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph {
    int **adjList;
    int numVertices;
    int isDirected;
} Graph;

Graph* createGraph(int numVertices, int isDirected) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = (int*)malloc(sizeof(int) * (isDirected ? numVertices : 1));
    }
    graph->isDirected = isDirected;
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjList[src][dest] = 1;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] != 0) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

int main() {
    Graph* graph = createGraph(5, 1);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 2);

    printGraph(graph);

    free(graph);

    return 0;
}