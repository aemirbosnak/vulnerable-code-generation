//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 50

typedef struct Graph {
    int **adjList;
    int numVertices;
    int numEdges;
} Graph;

Graph *graph_create() {
    Graph *graph = malloc(sizeof(Graph));
    graph->adjList = malloc(MAX_VERTICES * sizeof(int *));
    graph->numVertices = 0;
    graph->numEdges = 0;

    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void graph_add_vertex(Graph *graph) {
    graph->numVertices++;

    graph->adjList[graph->numVertices - 1] = malloc(MAX_EDGES * sizeof(int));
}

void graph_add_edge(Graph *graph, int src, int dest) {
    graph->numEdges++;

    graph->adjList[src][graph->numEdges - 1] = dest;
}

void graph_print(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->adjList[i][0]; j++) {
            printf("%d ", graph->adjList[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = graph_create();

    graph_add_vertex(graph);
    graph_add_vertex(graph);
    graph_add_vertex(graph);

    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 0, 2);
    graph_add_edge(graph, 1, 2);
    graph_add_edge(graph, 2, 3);

    graph_print(graph);

    free(graph);

    return 0;
}