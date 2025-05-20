//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** adjacencyList;
    int numVertices;
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

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = NULL;

    if (graph->adjacencyList[src] == NULL) {
        graph->adjacencyList[src] = newNode;
    } else {
        Node* temp = graph->adjacencyList[src];
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
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