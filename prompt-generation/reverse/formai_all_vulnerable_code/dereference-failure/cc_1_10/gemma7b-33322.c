//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** graph;
    int size;
} Graph;

Graph* createGraph(int size) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = size;
    graph->graph = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        graph->graph[i] = NULL;
    }
    return graph;
}

void insertNode(Graph* graph, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (graph->graph[graph->size - 1] != NULL) {
        graph->graph[graph->size - 1]->next = newNode;
    } else {
        graph->graph[graph->size - 1] = newNode;
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
    Graph* graph = createGraph(5);
    insertNode(graph, 10);
    insertNode(graph, 20);
    insertNode(graph, 30);
    insertNode(graph, 40);
    insertNode(graph, 50);

    traverseGraph(graph);

    return 0;
}