//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Graph {
    int **adjList;
    int numVertices;
    int numEdges;
} Graph;

Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->adjList = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = (int*)malloc(numEdges * sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjList[src][graph->numEdges] = dest;
    graph->numEdges++;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numEdges; j++) {
            if (graph->adjList[i][j] != 0) {
                printf("%d ", graph->adjList[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5, 5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    traverseGraph(graph);

    return 0;
}