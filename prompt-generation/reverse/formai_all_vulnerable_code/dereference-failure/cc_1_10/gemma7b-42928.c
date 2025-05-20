//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Graph {
    int **adjList;
    int numVertices;
    int numEdges;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (int**)malloc(MAX_Vertices * sizeof(int*));
    graph->numVertices = 0;
    graph->numEdges = 0;
    return graph;
}

void addVertex(Graph* graph) {
    graph->adjList[graph->numVertices] = (int*)malloc(MAX_Edges * sizeof(int));
    graph->numVertices++;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjList[src][graph->numEdges] = dest;
    graph->numEdges++;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numEdges; j++) {
            if (graph->adjList[i][j] != -1) {
                printf("%d ", graph->adjList[i][j]);
            }
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