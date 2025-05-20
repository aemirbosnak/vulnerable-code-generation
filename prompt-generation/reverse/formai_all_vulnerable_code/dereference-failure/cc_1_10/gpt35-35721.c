//FormAI DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct graph {
    int numVertices;
    bool directed;
    node* adjList[MAX_VERTICES];
} graph;

node* createNode(int v) {
    node* newNode = malloc(sizeof(node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

graph* createGraph(int vertices, bool directed) {
    graph* newGraph = malloc(sizeof(graph));
    newGraph->numVertices = vertices;
    newGraph->directed = directed;

    for (int i = 0; i < vertices; i++) {
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

void addEdge(graph* graph, int src, int dst) {
    node* newNode = createNode(dst);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    if (!graph->directed) {
        newNode = createNode(src);
        newNode->next = graph->adjList[dst];
        graph->adjList[dst] = newNode;
    }
}

void printGraph(graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    graph* newGraph = createGraph(5, true);
    addEdge(newGraph, 0, 1);
    addEdge(newGraph, 0, 4);
    addEdge(newGraph, 1, 2);
    addEdge(newGraph, 1, 3);
    addEdge(newGraph, 1, 4);
    addEdge(newGraph, 2, 3);
    addEdge(newGraph, 3, 4);

    printGraph(newGraph);

    return 0;
}