//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 100

typedef struct Graph {
    int **adj;
    int numVertices;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adj = (int**)malloc(MAX_VERTS * sizeof(int*));
    graph->numVertices = 0;
    return graph;
}

void addVertex(Graph* graph) {
    graph->numVertices++;
    graph->adj[graph->numVertices - 1] = (int*)malloc(MAX_VERTS * sizeof(int));
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adj[i][j] == 1) {
                printf("%d ", j);
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

    printGraph(graph);

    return 0;
}