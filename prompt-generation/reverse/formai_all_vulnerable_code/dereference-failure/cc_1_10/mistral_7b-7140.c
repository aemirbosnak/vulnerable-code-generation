//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 15

typedef struct Edge {
    int dest;
    struct Edge *next;
} Edge;

typedef struct Graph {
    int V;
    Edge *edge;
} Graph;

Graph *createGraph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = 0;
    graph->edge = NULL;
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->next = graph->edge;
    graph->edge = newEdge;
    graph->V++;
}

void printGraph(Graph *graph) {
    int i;
    for (i = 0; i < graph->V; i++) {
        printf("%d -> ", i);
        Edge *temp = graph->edge;
        while (temp != NULL) {
            if (temp->dest == i) {
                printf("%d ", i);
            }
            temp = temp->next;
        }
        printf("\n");
    }
}

void depthFirstSearch(Graph *graph, int src) {
    int visited[MAX_VERTICES] = {0};
    visited[src] = 1;
    printf("%d ", src);
    Edge *temp = graph->edge;
    while (temp != NULL) {
        int dest = temp->dest;
        if (visited[dest] == 0) {
            depthFirstSearch(graph, dest);
        }
        temp = temp->next;
    }
}

int main() {
    Graph *graph = createGraph();
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 1);

    printGraph(graph);
    printf("\nDepth First Search from vertex 1:\n");
    depthFirstSearch(graph, 1);

    return 0;
}