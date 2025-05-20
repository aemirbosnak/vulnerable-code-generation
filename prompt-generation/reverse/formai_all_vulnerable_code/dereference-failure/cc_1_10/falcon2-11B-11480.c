//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* nodes;
    int size;
    int maxSize;
    int* edges;
    int* edgeTo;
    int* edgeFrom;
    int edgeCount;
} Graph;

Graph createGraph(int nodesSize, int edgesSize) {
    Graph graph = {
       .nodes = (int*)malloc(nodesSize * sizeof(int)),
       .size = 0,
       .maxSize = nodesSize,
       .edges = (int*)malloc(edgesSize * sizeof(int)),
       .edgeTo = (int*)malloc(edgesSize * sizeof(int)),
       .edgeFrom = (int*)malloc(edgesSize * sizeof(int)),
       .edgeCount = 0
    };
    return graph;
}

void destroyGraph(Graph* graph) {
    free(graph->nodes);
    free(graph->edges);
    free(graph->edgeTo);
    free(graph->edgeFrom);
    free(graph);
}

void addEdge(Graph* graph, int nodeA, int nodeB) {
    if (graph->edgeCount >= graph->maxSize) {
        int newSize = graph->maxSize * 2;
        int* newNodes = (int*)realloc(graph->nodes, newSize * sizeof(int));
        int* newEdges = (int*)realloc(graph->edges, newSize * sizeof(int));
        int* newEdgeTo = (int*)realloc(graph->edgeTo, newSize * sizeof(int));
        int* newEdgeFrom = (int*)realloc(graph->edgeFrom, newSize * sizeof(int));
        graph->nodes = newNodes;
        graph->edges = newEdges;
        graph->edgeTo = newEdgeTo;
        graph->edgeFrom = newEdgeFrom;
        graph->maxSize = newSize;
    }
    graph->edges[graph->edgeCount] = nodeB;
    graph->edgeTo[nodeA] = graph->edgeCount;
    graph->edgeFrom[graph->edgeCount] = nodeA;
    graph->edgeCount++;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        printf("Node %d -> ", i);
        for (int j = 0; j < graph->edgeCount; j++) {
            if (graph->edgeFrom[j] == i) {
                printf("%d ", graph->edges[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int nodesSize = 5;
    int edgesSize = 3;
    Graph graph = createGraph(nodesSize, edgesSize);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    printGraph(&graph);

    destroyGraph(&graph);

    return 0;
}