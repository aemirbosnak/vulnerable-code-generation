//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Graph {
    int numVertices;
    int numEdges;
    int **adjList;
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
    graph->adjList = (int**)realloc(graph->adjList, graph->numVertices * sizeof(int*));
    graph->adjList[graph->numVertices - 1] = NULL;
}

void addEdge(Graph* graph, int srcVertex, int destVertex) {
    graph->numEdges++;
    graph->adjList[srcVertex] = (int*)realloc(graph->adjList[srcVertex], graph->numEdges * sizeof(int));
    graph->adjList[srcVertex][graph->numEdges - 1] = destVertex;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; graph->adjList[i] && j < graph->adjList[i][0]; j++) {
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
    addEdge(graph, 2, 0);

    traverseGraph(graph);

    return 0;
}