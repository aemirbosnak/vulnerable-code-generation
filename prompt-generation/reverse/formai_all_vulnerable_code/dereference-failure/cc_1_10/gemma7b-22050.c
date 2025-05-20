//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Graph {
    Node** adjacencyList;
    int numVertices;
};

void insertVertex(struct Graph* graph, int data) {
    graph->numVertices++;
    graph->adjacencyList = (Node**)realloc(graph->adjacencyList, graph->numVertices * sizeof(Node*));
    graph->adjacencyList[graph->numVertices - 1] = (Node*)malloc(sizeof(Node));
    graph->adjacencyList[graph->numVertices - 1]->data = data;
    graph->adjacencyList[graph->numVertices - 1]->next = NULL;
}

void insertEdge(struct Graph* graph, int src, int dest) {
    insertVertex(graph, dest);
    graph->adjacencyList[src]->next = graph->adjacencyList[dest];
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = 0;
    graph->adjacencyList = NULL;

    insertVertex(graph, 1);
    insertVertex(graph, 2);
    insertVertex(graph, 3);
    insertVertex(graph, 4);

    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 3);
    insertEdge(graph, 3, 4);

    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d ", graph->adjacencyList[i]->data);
    }

    printf("\n");

    return 0;
}