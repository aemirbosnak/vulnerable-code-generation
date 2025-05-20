//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph {
    int **adjList;
    int numVertices;
} Graph;

Graph *graph_create() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->adjList = (int **)malloc(MAX_VERTICES * sizeof(int *));
    graph->numVertices = 0;

    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void graph_add_vertex(Graph *graph) {
    graph->numVertices++;

    graph->adjList[graph->numVertices - 1] = (int *)malloc(MAX_VERTICES * sizeof(int));

    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->adjList[graph->numVertices - 1][i] = 0;
    }
}

void graph_add_edge(Graph *graph, int src, int dest) {
    graph->adjList[src][dest] = 1;
}

void graph_print(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] == 1) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

int main() {
    Graph *graph = graph_create();

    graph_add_vertex(graph);
    graph_add_vertex(graph);
    graph_add_vertex(graph);

    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 1, 2);

    graph_print(graph);

    return 0;
}