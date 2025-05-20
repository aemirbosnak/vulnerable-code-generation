//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define MAX_EDGES 1000

typedef struct {
    int from;
    int to;
    int weight;
} Edge;

typedef struct {
    int size;
    int capacity;
    Edge *edges;
} Graph;

Graph *createGraph() {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->size = 0;
    graph->capacity = MAX_NODES;
    graph->edges = (Edge *) malloc(MAX_EDGES * sizeof(Edge));
    return graph;
}

void addEdge(Graph *graph, int from, int to, int weight) {
    if (graph->size == graph->capacity) {
        printf("Graph is full!\n");
        return;
    }
    graph->edges[graph->size] = (Edge) {.from = from,.to = to,.weight = weight };
    graph->size++;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->size; i++) {
        printf("Edge %d: (%d, %d) with weight %d\n", i, graph->edges[i].from, graph->edges[i].to, graph->edges[i].weight);
    }
}

int main() {
    Graph *graph = createGraph();
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 5);
    addEdge(graph, 1, 2, 15);
    addEdge(graph, 1, 3, 20);
    addEdge(graph, 2, 3, 30);
    addEdge(graph, 2, 4, 25);
    addEdge(graph, 3, 4, 35);
    printGraph(graph);
    return 0;
}