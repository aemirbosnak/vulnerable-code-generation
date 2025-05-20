//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct _Node {
    struct _Node* next;
    struct _Node* prev;
    int data;
    char* name;
};

struct _Graph {
    struct _Node* head;
    struct _Node* tail;
    int size;
    char** edges;
};

void _Graph_insert(struct _Graph* graph, int data) {
    struct _Node* newNode = malloc(sizeof(struct _Node));
    newNode->data = data;
    newNode->name = malloc(10);
    sprintf(newNode->name, "node_%d", graph->size);
    graph->size++;

    if (graph->head == NULL) {
        graph->head = newNode;
        graph->tail = newNode;
    } else {
        graph->tail->next = newNode;
        graph->tail = newNode;
    }
}

int main() {
    struct _Graph* graph = malloc(sizeof(struct _Graph));
    graph->head = NULL;
    graph->tail = NULL;
    graph->size = 0;
    graph->edges = NULL;

    _Graph_insert(graph, 5);
    _Graph_insert(graph, 10);
    _Graph_insert(graph, 15);
    _Graph_insert(graph, 20);

    struct _Node* node = graph->head;
    while (node) {
        printf("%s (%d)\n", node->name, node->data);
        node = node->next;
    }

    free(graph);
    return 0;
}