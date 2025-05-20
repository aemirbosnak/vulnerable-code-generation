//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    char data;
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

void insertNode(Graph* graph, char data) {
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
            printf("%c ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(MAX);
    insertNode(graph, 'a');
    insertNode(graph, 'b');
    insertNode(graph, 'c');
    insertNode(graph, 'd');
    insertNode(graph, 'e');

    traverseGraph(graph);

    return 0;
}