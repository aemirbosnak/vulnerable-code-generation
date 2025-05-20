//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct graph {
    struct node* head;
};

void add_node(struct graph* graph, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (graph->head == NULL) {
        graph->head = new_node;
    } else {
        struct node* current = graph->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void add_edge(struct graph* graph, int node1, int node2) {
    struct node* new_edge = (struct node*) malloc(sizeof(struct node));
    new_edge->data = node2;
    new_edge->next = NULL;

    struct node* current = graph->head;
    while (current->next!= NULL) {
        if (current->data == node1) {
            current->next->next = new_edge;
            break;
        }
        current = current->next;
    }
}

int main() {
    struct graph* graph = (struct graph*) malloc(sizeof(struct graph));
    add_node(graph, 1);
    add_node(graph, 2);
    add_node(graph, 3);
    add_node(graph, 4);
    add_node(graph, 5);

    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);

    struct node* current = graph->head;
    while (current->next!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);

    return 0;
}