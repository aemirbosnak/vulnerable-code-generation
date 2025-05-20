//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_VERTICES 1000

typedef struct Edge {
    int src, dest, weight;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int numVertices;
    Edge** adjList;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = malloc(numVertices * sizeof(Edge**));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Edge* edge = malloc(sizeof(Edge));
    edge->src = src;
    edge->dest = dest;
    edge->weight = weight;
    edge->next = graph->adjList[src];
    graph->adjList[src] = edge;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Edge* edge = graph->adjList[i];
        while (edge) {
            printf("Vertex: %d, Edge: %d, Weight: %d\n", edge->src, edge->dest, edge->weight);
            edge = edge->next;
        }
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 20);
    addEdge(graph, 1, 2, 30);
    addEdge(graph, 2, 3, 40);
    addEdge(graph, 3, 4, 50);

    traverseGraph(graph);

    return 0;
}