//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_EDGES 1000

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct graph {
    int nodes;
    Node *head;
} Graph;

void add_node(Graph *g, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (g->head == NULL) {
        g->head = new_node;
        g->nodes = 1;
    } else {
        Node *temp = g->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        g->nodes++;
    }
}

void add_edge(Graph *g, int node1, int node2) {
    Node *temp1 = g->head;
    Node *temp2 = NULL;

    while (temp1!= NULL) {
        if (temp1->data == node1) {
            temp2 = temp1->next;
            temp1->next = NULL;
            g->head = temp2;
            g->head->next = temp1;
            g->head->next->next = NULL;
            g->nodes--;
            break;
        }
        temp1 = temp1->next;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->data = node2;
    new_node->next = NULL;

    if (temp2 == NULL) {
        g->head = new_node;
        g->head->next = temp1;
        g->nodes++;
    } else {
        Node *temp3 = g->head;
        while (temp3->next!= NULL) {
            temp3 = temp3->next;
        }
        temp3->next = new_node;
        g->head->next = new_node;
        g->nodes++;
    }
}

void print_graph(Graph *g) {
    Node *temp = g->head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Graph g;
    g.head = NULL;
    g.nodes = 0;

    add_node(&g, 1);
    add_node(&g, 2);
    add_node(&g, 3);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 3);
    print_graph(&g);

    return 0;
}