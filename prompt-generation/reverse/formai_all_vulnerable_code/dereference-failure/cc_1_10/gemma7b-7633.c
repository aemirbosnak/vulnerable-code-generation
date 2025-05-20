//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Graph {
    int numVertices;
    int numEdges;
    int **adjList;
} Graph;

Graph* createGraph() {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->numEdges = 0;
    graph->adjList = NULL;

    return graph;
}

void addVertex(Graph* graph) {
    graph->numVertices++;
    graph->adjList = realloc(graph->adjList, graph->numVertices * sizeof(int*));
    graph->adjList[graph->numVertices - 1] = NULL;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->numEdges++;
    graph->adjList[src] = realloc(graph->adjList[src], (graph->numEdges) * sizeof(int));
    graph->adjList[src][graph->numEdges - 1] = dest;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numEdges; j++) {
            if (graph->adjList[i][j] != NULL) {
                printf("Edge from vertex %d to vertex %d\n", i, graph->adjList[i][j]);
            }
        }
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

    return 0;
}