//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define GRAPH_MAX_SIZE 10

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Graph {
    Node** graph;
    int size;
} Graph;

Graph* graph_create(int size) {
    Graph* g = malloc(sizeof(Graph));
    g->graph = malloc(sizeof(Node*) * size);
    g->size = size;

    for (int i = 0; i < size; i++) {
        g->graph[i] = NULL;
    }

    return g;
}

void graph_add_node(Graph* g, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (g->graph[g->size - 1] != NULL) {
        g->graph[g->size - 1]->next = newNode;
        newNode->prev = g->graph[g->size - 1];
    } else {
        g->graph[g->size - 1] = newNode;
    }

    g->size++;
}

void graph_print(Graph* g) {
    for (int i = 0; i < g->size; i++) {
        Node* current = g->graph[i];

        while (current) {
            printf("%c ", current->data);
            current = current->next;
        }

        printf("\n");
    }
}

int main() {
    Graph* g = graph_create(GRAPH_MAX_SIZE);

    graph_add_node(g, 'a');
    graph_add_node(g, 'b');
    graph_add_node(g, 'c');
    graph_add_node(g, 'd');

    graph_print(g);

    return 0;
}