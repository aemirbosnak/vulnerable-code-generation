//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[20];
    struct Node* next;
} Node;

typedef struct Graph {
    Node** adjacencyList;
    int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjacencyList = (Node**)malloc(numVertices * sizeof(Node));
    graph->numVertices = numVertices;
    return graph;
}

void insertVertex(Graph* graph, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    graph->adjacencyList[graph->numVertices++] = newNode;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjacencyList[i];
        while (current) {
            printf("%s ", current->name);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    insertVertex(graph, "A");
    insertVertex(graph, "B");
    insertVertex(graph, "C");
    insertVertex(graph, "D");
    insertVertex(graph, "E");

    traverseGraph(graph);

    return 0;
}