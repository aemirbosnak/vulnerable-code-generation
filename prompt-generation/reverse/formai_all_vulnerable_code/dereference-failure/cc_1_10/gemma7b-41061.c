//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode {
    int data;
    struct GraphNode* next;
} GraphNode;

typedef struct Graph {
    GraphNode* head;
    GraphNode** adjacencyList;
} Graph;

void insertNode(Graph* graph, int data) {
    GraphNode* newNode = malloc(sizeof(GraphNode));
    newNode->data = data;
    newNode->next = NULL;

    if (graph->head == NULL) {
        graph->head = newNode;
    } else {
        graph->adjacencyList[data] = newNode;
    }
}

void traverseGraph(Graph* graph) {
    GraphNode* current = graph->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Graph* graph = malloc(sizeof(Graph));
    graph->head = NULL;
    graph->adjacencyList = NULL;

    insertNode(graph, 10);
    insertNode(graph, 20);
    insertNode(graph, 30);
    insertNode(graph, 40);
    insertNode(graph, 50);

    traverseGraph(graph);

    free(graph);

    return 0;
}