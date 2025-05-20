//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Graph {
    int numNodes;
    int numEdges;
    int **adjacencyList;
};

typedef struct Graph Graph;

Graph *createGraph(int numNodes) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    graph->numEdges = 0;
    graph->adjacencyList = (int**)malloc(sizeof(int*) * numNodes);
    for (int i = 0; i < numNodes; i++) {
        graph->adjacencyList[i] = (int*)malloc(sizeof(int) * numNodes);
    }
    return graph;
}

void addEdge(Graph *graph, int source, int dest) {
    graph->adjacencyList[source][graph->numEdges] = dest;
    graph->numEdges++;
}

void removeEdge(Graph *graph, int source, int dest) {
    int *temp = (int*)malloc(sizeof(int));
    temp[0] = dest;
    graph->adjacencyList[source][graph->numEdges] = temp;
    graph->numEdges--;
}

void viewEdges(Graph *graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        for (int j = 0; j < graph->numEdges; j++) {
            printf("%d %d\n", i, graph->adjacencyList[i][j]);
        }
    }
}

int main() {
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    viewEdges(graph);
    removeEdge(graph, 0, 1);
    viewEdges(graph);
    free(graph->adjacencyList[0]);
    free(graph->adjacencyList);
    free(graph);
    return 0;
}