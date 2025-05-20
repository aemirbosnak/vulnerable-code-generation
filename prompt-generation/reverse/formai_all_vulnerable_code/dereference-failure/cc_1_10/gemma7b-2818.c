//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 200

typedef struct Node {
    int index;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    int numEdges;
    Node** adjacencyList;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->numEdges = 0;
    graph->adjacencyList = (Node**)malloc(MAX_VERTICES * sizeof(Node*));
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

void addVertex(Graph* graph) {
    graph->numVertices++;
    graph->adjacencyList[graph->numVertices - 1] = NULL;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
    graph->numEdges++;
}

int main() {
    Graph* graph = createGraph();
    addVertex(graph);
    addVertex(graph);
    addVertex(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjacencyList[i];
        while (current) {
            printf("%d ", current->index);
            current = current->next;
        }
        printf("\n");
    }

    return 0;
}