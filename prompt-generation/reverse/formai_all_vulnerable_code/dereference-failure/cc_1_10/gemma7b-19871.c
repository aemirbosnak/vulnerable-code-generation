//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Graph {
    Node** graph;
    int size;
};

void insert(struct Graph* graph, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (graph->size == 0) {
        graph->graph = (Node**)malloc(sizeof(Node*) * MAX_SIZE);
        graph->size = MAX_SIZE;
    }

    graph->graph[graph->size++] = newNode;
}

void traverse(struct Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        Node* current = graph->graph[i];
        printf("%c ", current->data);
    }
    printf("\n");
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->size = 0;
    graph->graph = NULL;

    insert(graph, 'a');
    insert(graph, 'b');
    insert(graph, 'c');
    insert(graph, 'd');
    insert(graph, 'e');

    traverse(graph);

    return 0;
}