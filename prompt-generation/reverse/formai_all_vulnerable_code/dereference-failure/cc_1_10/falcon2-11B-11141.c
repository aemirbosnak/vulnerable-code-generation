//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct graph {
    Node* head;
} Graph;

void add_node(Graph* graph, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (graph->head == NULL) {
        graph->head = new_node;
        return;
    }

    Node* current = graph->head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void print_graph(Graph* graph) {
    Node* current = graph->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Graph graph;
    graph.head = NULL;

    add_node(&graph, 1);
    add_node(&graph, 2);
    add_node(&graph, 3);
    add_node(&graph, 4);
    add_node(&graph, 5);

    print_graph(&graph);

    return 0;
}