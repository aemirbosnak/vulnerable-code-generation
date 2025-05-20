//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Graph {
    Node** graph;
    int size;
};

void insertNode(struct Graph* graph, char data) {
    if (graph->size == graph->size) {
        graph->graph = realloc(graph->graph, (graph->size + 1) * sizeof(Node*));
        graph->size++;
    }

    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    graph->graph[graph->size - 1] = newNode;
}

void traverseGraph(struct Graph* graph) {
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
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->size = 0;
    graph->graph = NULL;

    insertNode(graph, 'a');
    insertNode(graph, 'b');
    insertNode(graph, 'c');
    insertNode(graph, 'd');
    insertNode(graph, 'e');

    traverseGraph(graph);

    return 0;
}