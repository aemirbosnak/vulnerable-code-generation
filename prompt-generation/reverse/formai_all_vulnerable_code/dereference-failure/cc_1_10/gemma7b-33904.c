//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** adjacencyList;
    int numVertices;
} Graph;

Graph* graphCreate(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->adjacencyList = NULL;
    graph->numVertices = numVertices;

    return graph;
}

void graphAddEdge(Graph* graph, int srcVertex, int destVertex) {
    Node** adjacencyList = graph->adjacencyList;
    Node* newNode = malloc(sizeof(Node));
    newNode->data = destVertex;
    newNode->next = NULL;

    if (adjacencyList == NULL) {
        adjacencyList = malloc(sizeof(Node*) * graph->numVertices);
        graph->adjacencyList = adjacencyList;
    }

    adjacencyList[srcVertex] = newNode;
}

void graphPrint(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* node = graph->adjacencyList[i];
        printf("Vertex %d: ", i);
        while (node) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = graphCreate(5);
    graphAddEdge(graph, 0, 1);
    graphAddEdge(graph, 0, 2);
    graphAddEdge(graph, 1, 2);
    graphAddEdge(graph, 2, 3);
    graphAddEdge(graph, 3, 4);

    graphPrint(graph);

    return 0;
}