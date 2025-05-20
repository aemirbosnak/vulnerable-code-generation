//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Graph {
    int numVertices;
    int numEdges;
    char **adjList;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->numEdges = 0;
    graph->adjList = NULL;
    return graph;
}

void addVertex(Graph* graph) {
    graph->numVertices++;
    graph->adjList = (char**)realloc(graph->adjList, graph->numVertices * sizeof(char*));
    graph->adjList[graph->numVertices - 1] = NULL;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->numEdges++;
    graph->adjList[src] = (char*)realloc(graph->adjList[src], graph->numEdges * sizeof(char));
    graph->adjList[src][graph->numEdges - 1] = dest;
}

void traverseGraph(Graph* graph) {
    int i, j;
    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; graph->adjList[i] && j < graph->numEdges; j++) {
            printf("%d ", graph->adjList[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph();
    addVertex(graph);
    addVertex(graph);
    addVertex(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    traverseGraph(graph);

    free(graph);
    return 0;
}