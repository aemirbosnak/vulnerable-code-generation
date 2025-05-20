//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_VERTICES 10

typedef struct Graph {
    int numVertices;
    int **adjList;
} Graph;

Graph *graph_create(int numVertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void graph_add_edge(Graph *graph, int srcVertex, int destVertex) {
    if (graph->adjList[srcVertex] == NULL) {
        graph->adjList[srcVertex] = malloc(sizeof(int *) * graph->numVertices);
    }
    graph->adjList[srcVertex][destVertex] = 1;
}

void graph_print(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; graph->adjList[i] && j < graph->numVertices; j++) {
            if (graph->adjList[i][j] != 0) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

int main() {
    Graph *graph = graph_create(5);
    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 0, 2);
    graph_add_edge(graph, 1, 2);
    graph_add_edge(graph, 2, 3);
    graph_add_edge(graph, 3, 4);
    graph_print(graph);

    return 0;
}