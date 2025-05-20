//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Graph {
    int **adj;
    int numVertices;
    char **label;
} Graph;

Graph *graphCreate(int numVertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adj = malloc(numVertices * sizeof(int *));
    graph->label = malloc(numVertices * sizeof(char *));

    for (int i = 0; i < numVertices; i++) {
        graph->adj[i] = malloc(numVertices * sizeof(int));
        graph->label[i] = malloc(20 * sizeof(char));
    }

    return graph;
}

void graphDestroy(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adj[i]);
        free(graph->label[i]);
    }

    free(graph->adj);
    free(graph->label);
    free(graph);
}

void graphAddEdge(Graph *graph, int src, int dest) {
    graph->adj[src][dest] = 1;
}

void graphPrint(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adj[i][j] == 1) {
                printf("%c --> %c\n", graph->label[i], graph->label[j]);
            }
        }
    }
}

int main() {
    Graph *graph = graphCreate(5);
    graphAddEdge(graph, 0, 1);
    graphAddEdge(graph, 0, 2);
    graphAddEdge(graph, 1, 2);
    graphAddEdge(graph, 1, 3);
    graphAddEdge(graph, 2, 3);
    graphAddEdge(graph, 3, 4);
    graphAddEdge(graph, 4, 5);

    graphPrint(graph);

    graphDestroy(graph);

    return 0;
}