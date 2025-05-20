//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Graph {
    Node**adjList;
    int numVertices;
};

void insertVertex(struct Graph* graph, int data) {
    graph->numVertices++;
    graph->adjList = realloc(graph->adjList, graph->numVertices * sizeof(Node*));
    graph->adjList[graph->numVertices - 1] = malloc(sizeof(Node));
    graph->adjList[graph->numVertices - 1]->data = data;
    graph->adjList[graph->numVertices - 1]->next = NULL;
}

void insertEdge(struct Graph* graph, int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = NULL;

    graph->adjList[src]->next = newNode;
}

void traverseGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjList[i];
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = malloc(sizeof(struct Graph));
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

    traverseGraph(graph);

    return 0;
}