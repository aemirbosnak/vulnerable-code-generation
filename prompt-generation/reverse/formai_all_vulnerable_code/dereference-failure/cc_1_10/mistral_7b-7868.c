//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define EDGE_WEIGHT_TYPE int

typedef struct Edge {
    int dest;
    EDGE_WEIGHT_TYPE weight;
} Edge;

typedef struct Graph {
    int V;
    Edge* edgeList;
} Graph;

void addEdge(Graph* graph, int src, int dest, EDGE_WEIGHT_TYPE weight) {
    Edge* newEdge = (Edge*) malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;

    int eIndex = 0;
    for (; eIndex < graph->V; eIndex++) {
        if (graph->edgeList[eIndex].dest == src) {
            graph->edgeList[eIndex].dest = dest;
            graph->edgeList[eIndex].weight = weight;
            return;
        }
    }

    int edgeSize = sizeof(Edge) * graph->V;
    graph->edgeList = (Edge*) realloc(graph->edgeList, edgeSize + sizeof(Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    graph->edgeList[graph->V++] = *newEdge;
}

void printGraph(Graph* graph) {
    printf("Graph:\n");
    printf("Vertices: %d\n", graph->V);

    printf("Edges: \n");
    for (int i = 0; i < graph->V; i++) {
        printf("Source %d -> Destination %d : Weight %d\n", i, graph->edgeList[i].dest, graph->edgeList[i].weight);
    }
}

int main() {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = 5;

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 1, 4, 1);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 3, 4, 6);

    printGraph(graph);

    free(graph->edgeList);
    free(graph);

    return 0;
}