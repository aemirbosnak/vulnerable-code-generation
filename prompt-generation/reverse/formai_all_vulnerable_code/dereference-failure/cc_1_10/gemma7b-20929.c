//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int numVertices;
    int **adjList;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = (int*)malloc(numVertices * sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->adjList[u][v] = 1;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] == 1) {
                printf("%d - %d ", i, j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(MAX_VERTICES);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 8);
    addEdge(graph, 8, 9);
    addEdge(graph, 9, 10);

    printGraph(graph);

    return 0;
}