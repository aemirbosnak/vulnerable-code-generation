//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef GRAPH_H
#define GRAPH_H

typedef struct Node {
    char name[20];
    struct Node* next;
} Node;

typedef struct Graph {
    Node** adjacencyList;
    int numVertices;
} Graph;

Graph* createGraph(int numVertices);
void addVertex(Graph* graph, char* name);
void addEdge(Graph* graph, char* source, char* destination);
void printGraph(Graph* graph);

#endif

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (Node**)malloc(numVertices * sizeof(Node*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

void addVertex(Graph* graph, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    graph->adjacencyList[graph->numVertices] = newNode;
    graph->numVertices++;
}

void addEdge(Graph* graph, char* source, char* destination) {
    Node* sourceNode = NULL;
    Node* destinationNode = NULL;

    for (Node* node = graph->adjacencyList[0]; node; node = node->next) {
        if (strcmp(node->name, source) == 0) {
            sourceNode = node;
        }
    }

    for (Node* node = graph->adjacencyList[0]; node; node = node->next) {
        if (strcmp(node->name, destination) == 0) {
            destinationNode = node;
        }
    }

    if (sourceNode && destinationNode) {
        sourceNode->next = destinationNode;
    }
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%s:", graph->adjacencyList[i]->name);
        for (Node* node = graph->adjacencyList[i]->next; node; node = node->next) {
            printf(" -> %s", node->name);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    addVertex(graph, "A");
    addVertex(graph, "B");
    addVertex(graph, "C");
    addVertex(graph, "D");
    addVertex(graph, "E");
    addEdge(graph, "A", "B");
    addEdge(graph, "A", "C");
    addEdge(graph, "B", "D");
    addEdge(graph, "C", "E");
    printGraph(graph);

    return 0;
}