//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjacencyList;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (Node**)malloc(numVertices * sizeof(Node*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, char source, char destination) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = destination;
    newNode->next = graph->adjacencyList[source];
    graph->adjacencyList[source] = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjacencyList[i];
        printf("%c ", current->data);
    }
    printf("\n");
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 'a', 'b');
    addEdge(graph, 'a', 'c');
    addEdge(graph, 'c', 'd');
    addEdge(graph, 'c', 'e');

    printGraph(graph);

    return 0;
}