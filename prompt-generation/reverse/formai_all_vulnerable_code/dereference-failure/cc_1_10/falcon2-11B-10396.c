//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Graph;

void add_node(Graph *graph, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (graph->head == NULL) {
        graph->head = new_node;
        graph->tail = new_node;
    } else {
        new_node->next = graph->head;
        graph->head = new_node;
    }
}

void print_graph(Graph *graph) {
    if (graph->head == NULL) {
        printf("Graph is empty.\n");
        return;
    }

    Node *current = graph->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    add_node(graph, 1);
    add_node(graph, 2);
    add_node(graph, 3);
    add_node(graph, 4);
    add_node(graph, 5);
    add_node(graph, 6);
    add_node(graph, 7);
    add_node(graph, 8);
    add_node(graph, 9);
    add_node(graph, 10);
    print_graph(graph);

    return 0;
}