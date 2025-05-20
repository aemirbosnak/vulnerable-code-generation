//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Graph {
    int numVertices;
    struct Node **adjList;
};

struct Node {
    int data;
    struct Node **next;
};

void insertVertex(struct Graph *graph, int data) {
    graph->numVertices++;
    graph->adjList = realloc(graph->adjList, graph->numVertices * sizeof(struct Node *));
    graph->adjList[graph->numVertices - 1] = malloc(sizeof(struct Node));
    graph->adjList[graph->numVertices - 1]->data = data;
    graph->adjList[graph->numVertices - 1]->next = NULL;
}

void insertEdge(struct Graph *graph, int src, int dest) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = NULL;
    graph->adjList[src]->next = newNode;
}

int main() {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = 0;
    graph->adjList = NULL;

    insertVertex(graph, 1);
    insertVertex(graph, 2);
    insertVertex(graph, 3);
    insertVertex(graph, 4);
    insertVertex(graph, 5);

    insertEdge(graph, 1, 2);
    insertEdge(graph, 1, 3);
    insertEdge(graph, 2, 4);
    insertEdge(graph, 3, 5);

    for (int i = 0; i < graph->numVertices; i++) {
        struct Node *node = graph->adjList[i];
        printf("Vertex %d: ", i + 1);
        while (node) {
            printf("--> Vertex %d ", node->data);
            node = node->next;
        }
        printf("\n");
    }

    return 0;
}