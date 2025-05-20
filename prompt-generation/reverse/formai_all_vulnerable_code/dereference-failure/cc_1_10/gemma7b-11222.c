//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** graph;
    int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->graph = (Node**)malloc(numVertices * sizeof(Node*));
    graph->numVertices = numVertices;
    return graph;
}

void insertVertex(Graph* graph, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    graph->graph[graph->numVertices++] = newNode;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->graph[i];
        printf("Vertex: %d ", current->data);
        while (current->next) {
            current = current->next;
            printf("-> ");
            printf("Vertex: %d ", current->data);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    insertVertex(graph, 1);
    insertVertex(graph, 2);
    insertVertex(graph, 3);
    insertVertex(graph, 4);
    insertVertex(graph, 5);
    insertVertex(graph, 6);

    traverseGraph(graph);

    return 0;
}