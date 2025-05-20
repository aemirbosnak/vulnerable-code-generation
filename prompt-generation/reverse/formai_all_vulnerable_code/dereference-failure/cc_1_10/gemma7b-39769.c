//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int numVertices;
    int **adjList;
    char ***graphData;
} Graph;

Graph *createGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (int **)malloc(numVertices * sizeof(int *));
    graph->graphData = (char ***)malloc(numVertices * sizeof(char **));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = (int *)malloc(numVertices * sizeof(int));
        graph->graphData[i] = (char **)malloc(numVertices * sizeof(char *));
    }
    return graph;
}

void addEdge(Graph *graph, int srcVertex, int destVertex, char data) {
    graph->adjList[srcVertex][destVertex] = 1;
    graph->graphData[srcVertex][destVertex] = data;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] == 1) {
                printf("(%d, %d) - %c\n", i, j, graph->graphData[i][j]);
            }
        }
    }
}

int main() {
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1, 'a');
    addEdge(graph, 0, 2, 'b');
    addEdge(graph, 1, 2, 'c');
    addEdge(graph, 2, 3, 'd');
    addEdge(graph, 3, 4, 'e');
    printGraph(graph);

    return 0;
}