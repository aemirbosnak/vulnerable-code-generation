//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 10

typedef struct Edge {
    int src, dest;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int numVertices;
    Edge** adjList;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Edge**)malloc(numVertices * sizeof(Edge*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Edge* edge = malloc(sizeof(Edge));
    edge->src = src;
    edge->dest = dest;
    edge->next = NULL;

    Edge* lastEdge = graph->adjList[src];
    if (lastEdge) {
        lastEdge->next = edge;
    } else {
        graph->adjList[src] = edge;
    }
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Edge* edge = graph->adjList[i];
        while (edge) {
            printf("%d -> %d\n", edge->src, edge->dest);
            edge = edge->next;
        }
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    traverseGraph(graph);

    return 0;
}