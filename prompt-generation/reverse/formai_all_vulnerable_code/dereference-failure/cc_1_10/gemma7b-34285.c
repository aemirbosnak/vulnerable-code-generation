//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph {
    int **adjList;
    int numVertices;
    int numEdges;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (int**)malloc(numVertices * sizeof(int*));
    graph->numVertices = numVertices;
    graph->numEdges = 0;

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->numEdges++;

    if (graph->adjList[src] == NULL) {
        graph->adjList[src] = (int*)malloc(graph->numVertices * sizeof(int));
    }

    graph->adjList[src][graph->numVertices] = dest;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);

        if (graph->adjList[i] != NULL) {
            for (int j = 0; graph->adjList[i][j] != NULL; j++) {
                printf("%d ", graph->adjList[i][j]);
            }

            printf("\n");
        } else {
            printf("No edges\n");
        }
    }
}

int main() {
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}