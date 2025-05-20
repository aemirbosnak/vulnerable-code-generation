//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_EDGES 1000
#define MAX_VERTICES 1000

typedef struct graph {
    int vertices;
    int edges;
    int* adjacencyList;
} Graph;

typedef struct vertex {
    int index;
    int degree;
} Vertex;

void initGraph(Graph* graph) {
    graph->vertices = 0;
    graph->edges = 0;
    graph->adjacencyList = NULL;
}

void addEdge(Graph* graph, int u, int v) {
    if (graph->vertices == MAX_VERTICES) {
        fprintf(stderr, "Graph is full.\n");
        return;
    }
    if (graph->edges == MAX_EDGES) {
        fprintf(stderr, "Too many edges.\n");
        return;
    }
    if (graph->adjacencyList == NULL) {
        graph->adjacencyList = (int*) calloc(MAX_VERTICES, sizeof(int));
    }
    if (u >= graph->vertices || u < 0 || u == v) {
        fprintf(stderr, "Invalid vertex index.\n");
        return;
    }
    if (v >= graph->vertices || v < 0) {
        fprintf(stderr, "Invalid vertex index.\n");
        return;
    }
    graph->adjacencyList[u]++;
    graph->adjacencyList[v]++;
    graph->edges++;
}

void printGraph(Graph* graph) {
    int i, j;
    for (i = 0; i < graph->vertices; i++) {
        printf("%d (%d)\n", i, graph->adjacencyList[i]);
        for (j = 0; j < graph->adjacencyList[i]; j++) {
            printf("-> %d\n", graph->adjacencyList[i * 2 + j]);
        }
    }
}

int main() {
    Graph graph;
    initGraph(&graph);
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 5);
    addEdge(&graph, 4, 5);
    printGraph(&graph);
    return 0;
}