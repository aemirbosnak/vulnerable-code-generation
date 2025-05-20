//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

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
    graph->adjacencyList = realloc(graph->adjacencyList, graph->numVertices * sizeof(Node*));
    graph->adjacencyList[graph->numVertices - 1] = (Node*)malloc(sizeof(Node));
    graph->adjacencyList[graph->numVertices - 1]->data = data;
    graph->adjacencyList[graph->numVertices - 1]->next = NULL;
}

void insertEdge(struct Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = NULL;

    insertVertex(graph, src);

    graph->adjacencyList[src]->next = newNode;
}

void traverseGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjacencyList[i];
        printf("Vertex %d: ", i);
        while (current) {
            printf("-> Vertex %d", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = 0;
    graph->adjacencyList = NULL;

    insertVertex(graph, 0);
    insertVertex(graph, 1);
    insertVertex(graph, 2);
    insertEdge(graph, 0, 1);
    insertEdge(graph, 1, 2);

    traverseGraph(graph);

    return 0;
}