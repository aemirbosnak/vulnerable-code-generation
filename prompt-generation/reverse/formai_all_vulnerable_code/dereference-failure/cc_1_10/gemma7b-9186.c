//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjacencyList;
} Graph;

void insertVertex(Graph* graph, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (graph->adjacencyList == NULL) {
        graph->adjacencyList = (Node**)malloc(graph->numVertices * sizeof(Node*));
    }

    graph->adjacencyList[graph->numVertices++] = newNode;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* currentVertex = graph->adjacencyList[i];
        while (currentVertex) {
            printf("%d ", currentVertex->data);
            currentVertex = currentVertex->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 5;
    graph->adjacencyList = NULL;

    insertVertex(graph, 1);
    insertVertex(graph, 2);
    insertVertex(graph, 3);
    insertVertex(graph, 4);
    insertVertex(graph, 5);

    traverseGraph(graph);

    return 0;
}