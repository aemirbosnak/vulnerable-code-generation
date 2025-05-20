//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node**adjList;
    int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->adjList = malloc(numVertices * sizeof(Node*));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

int main() {
    Graph* graph = createGraph(MAX);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    for (int i = 0; i < MAX; i++) {
        Node* current = graph->adjList[i];
        while (current) {
            printf("Edge from %d to %d\n", i, current->data);
            current = current->next;
        }
    }

    return 0;
}