//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Graph {
    struct Node **adjList;
    int numVertices;
} Graph;

typedef struct Node {
    char data;
    struct Node *next;
} Node;

Graph *createGraph(int numVertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = malloc(numVertices * sizeof(struct Node *));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addToGraph(Graph *graph, char data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (graph->adjList[data] == NULL) {
        graph->adjList[data] = newNode;
    } else {
        graph->adjList[data]->next = newNode;
    }
}

void traverseGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node *node = graph->adjList[i];
        while (node) {
            printf("%c ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = createGraph(5);
    addToGraph(graph, 'a');
    addToGraph(graph, 'b');
    addToGraph(graph, 'c');
    addToGraph(graph, 'd');
    addToGraph(graph, 'e');

    traverseGraph(graph);

    free(graph);
    return 0;
}