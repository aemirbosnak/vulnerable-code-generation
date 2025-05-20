//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Graph {
    int numVertices;
    Node** adjacencyList;
};

void insertVertex(struct Graph* graph) {
    if (graph->numVertices == MAX_Vertices) {
        return;
    }

    graph->numVertices++;
    graph->adjacencyList = (Node**)realloc(graph->adjacencyList, graph->numVertices * sizeof(Node*));

    graph->adjacencyList[graph->numVertices - 1] = (Node*)malloc(sizeof(Node));
    graph->adjacencyList[graph->numVertices - 1]->data = graph->numVertices;
    graph->adjacencyList[graph->numVertices - 1]->next = NULL;
}

void insertEdge(struct Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = NULL;

    if (graph->adjacencyList[src] == NULL) {
        insertVertex(graph);
    }

    graph->adjacencyList[src]->next = newNode;
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = 0;
    graph->adjacencyList = NULL;

    insertVertex(graph);
    insertVertex(graph);
    insertVertex(graph);

    insertEdge(graph, 0, 1);
    insertEdge(graph, 1, 2);

    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", graph->adjacencyList[i]->data);
        for (Node* node = graph->adjacencyList[i]->next; node; node = node->next) {
            printf("Edge to Vertex %d ", node->data);
        }
        printf("\n");
    }

    return 0;
}