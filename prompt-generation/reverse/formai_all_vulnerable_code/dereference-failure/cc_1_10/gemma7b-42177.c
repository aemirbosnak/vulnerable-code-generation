//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Graph {
    Node** adjacencyList;
    int numVertices;
    int numEdges;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjacencyList = (Node**)malloc(numVertices * sizeof(Node*));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (graph->adjacencyList[src] == NULL) {
        graph->adjacencyList[src] = newNode;
    } else {
        graph->adjacencyList[src]->next = newNode;
    }

    graph->numEdges++;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjacencyList[i];
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    traverseGraph(graph);

    return 0;
}