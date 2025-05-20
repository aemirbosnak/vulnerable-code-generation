//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Graph {
    Node** adjacencyList;
    int numVertices;
    int numEdges;
};

void insertVertex(struct Graph* graph) {
    graph->numVertices++;
    graph->adjacencyList = realloc(graph->adjacencyList, graph->numVertices * MAX);
    graph->adjacencyList[graph->numVertices - 1] = NULL;
}

void insertEdge(struct Graph* graph, int srcVertex, int destVertex) {
    graph->numEdges++;
    graph->adjacencyList[srcVertex]->next = malloc(sizeof(Node));
    graph->adjacencyList[srcVertex]->next->data = destVertex;
    graph->adjacencyList[srcVertex]->next->next = NULL;
}

int main() {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = 0;
    graph->numEdges = 0;
    graph->adjacencyList = NULL;

    insertVertex(graph);
    insertVertex(graph);
    insertVertex(graph);
    insertVertex(graph);

    insertEdge(graph, 0, 1);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 3);

    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        for (Node* node = graph->adjacencyList[i]; node; node = node->next) {
            printf("-> %d ", node->data);
        }
        printf("\n");
    }

    return 0;
}