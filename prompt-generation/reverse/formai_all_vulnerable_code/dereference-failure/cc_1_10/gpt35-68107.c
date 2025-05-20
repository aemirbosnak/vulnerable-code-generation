//FormAI DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Edge {
    int dest;
    struct Edge *next;
} Edge;

typedef struct Vertex {
    int id;
    Edge *edgeList;
} Vertex;

Vertex *graph[MAX_VERTICES];
int nVertices = 0;

void addVertex(int id) {
    Vertex *v = (Vertex *) malloc(sizeof(Vertex));
    v->id = id;
    v->edgeList = NULL;
    graph[nVertices++] = v;
}

void addEdge(int src, int dest) {
    Edge *e = (Edge *) malloc(sizeof(Edge));
    e->dest = dest;
    e->next = graph[src]->edgeList;
    graph[src]->edgeList = e;
}

void printGraph(int start, int end) {
    if (start == end) {
        printf("%d", start);
        return;
    }

    printf("%d -> ", start);
    printGraph(graph[start]->edgeList->dest, end);
}

int main() {
    addVertex(0);
    addVertex(1);
    addVertex(2);
    addVertex(3);
    addVertex(4);
    addVertex(5);

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);

    int start = 0;
    int end = 5;

    printf("Graph Representation:\n");

    for (int i = 0; i < nVertices; i++) {
        printf("%d -> ", graph[i]->id);

        Edge *edgeList = graph[i]->edgeList;
        while (edgeList != NULL) {
            printf("%d -> ", edgeList->dest);
            edgeList = edgeList->next;
        }

        printf("NULL\n");
    }

    printf("\nPath from %d to %d: ", start, end);
    printGraph(start, end);
    printf("\n");

    return 0;
}