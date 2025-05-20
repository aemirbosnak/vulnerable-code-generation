//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Graph {
    Node** graph;
    int size;
};

void insertNode(struct Graph* graph, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (graph->size == 0) {
        graph->graph = malloc(sizeof(Node*) * MAX_SIZE);
        graph->graph[0] = newNode;
        graph->size = 1;
    } else {
        graph->graph[graph->size++] = newNode;
    }
}

void traverseGraph(struct Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        Node* current = graph->graph[i];
        printf("%d ", current->data);
    }
    printf("\n");
}

int main() {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->size = 0;
    graph->graph = NULL;

    insertNode(graph, 10);
    insertNode(graph, 20);
    insertNode(graph, 30);
    insertNode(graph, 40);
    insertNode(graph, 50);

    traverseGraph(graph);

    return 0;
}