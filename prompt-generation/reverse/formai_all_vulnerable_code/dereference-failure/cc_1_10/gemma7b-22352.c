//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define GRAPH_MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** graph;
    int size;
} Graph;

Graph* createGraph() {
    Graph* graph = malloc(sizeof(Graph));
    graph->graph = malloc(sizeof(Node*) * GRAPH_MAX_SIZE);
    graph->size = 0;
    return graph;
}

void insertNode(Graph* graph, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (graph->size == 0) {
        graph->graph[0] = newNode;
    } else {
        graph->graph[graph->size] = newNode;
    }
    graph->size++;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        Node* current = graph->graph[i];
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph();
    insertNode(graph, 10);
    insertNode(graph, 20);
    insertNode(graph, 30);
    insertNode(graph, 40);
    traverseGraph(graph);

    return 0;
}