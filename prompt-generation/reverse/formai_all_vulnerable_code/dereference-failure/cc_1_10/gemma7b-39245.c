//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10

typedef struct Graph {
    int numVertices;
    int **adjList;
    char **vertexLabels;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = malloc(numVertices * sizeof(int*));
    graph->vertexLabels = malloc(numVertices * sizeof(char*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
        graph->vertexLabels[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjList[src] = realloc(graph->adjList[src], (graph->numVertices) * sizeof(int));
    graph->adjList[src][graph->adjList[src][0]] = dest;
    graph->adjList[src][graph->adjList[src][0]]++;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%s:", graph->vertexLabels[i]);
        for (int j = 0; graph->adjList[i][j] != NULL; j++) {
            printf(" --> %s", graph->vertexLabels[graph->adjList[i][j]]);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    printGraph(graph);

    free(graph->adjList);
    free(graph->vertexLabels);
    free(graph);

    return 0;
}