//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct graph {
    node *head;
    int size;
} graph;

void insert_node(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_graph(graph *g) {
    if (g == NULL) {
        printf("Graph is empty\n");
        return;
    }
    node *temp = g->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    graph *g = (graph *)malloc(sizeof(graph));
    g->head = NULL;
    g->size = 0;

    insert_node(&g->head, 1);
    insert_node(&g->head, 2);
    insert_node(&g->head, 3);
    insert_node(&g->head, 4);
    insert_node(&g->head, 5);

    printf("Graph:\n");
    print_graph(g);

    return 0;
}