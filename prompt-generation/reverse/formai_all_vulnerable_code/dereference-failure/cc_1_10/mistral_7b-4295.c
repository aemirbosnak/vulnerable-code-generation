//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Edge {
    int dest;
    struct Edge *next;
} Edge;

typedef struct Graph {
    int V;
    Edge *list[MAX_VERTICES];
} Graph;

void addEdge(Graph *graph, int src, int dest) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->next = graph->list[src];
    graph->list[src] = newEdge;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("\nVertex %d: ", i);
        for (Edge *edge = graph->list[i]; edge != NULL; edge = edge->next) {
            printf("-> %d", edge->dest);
        }
    }
}

int main() {
    Graph graph;
    int V = 5;

    graph.V = V;

    for (int i = 0; i < V; i++) {
        graph.list[i] = NULL;
    }

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 4);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    printf("Graph representation:\n");
    printGraph(&graph);

    return 0;
}