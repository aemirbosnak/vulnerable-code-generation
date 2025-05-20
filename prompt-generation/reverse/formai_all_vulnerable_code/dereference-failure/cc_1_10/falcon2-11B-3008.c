//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

typedef struct graph {
    Node *head;
    Node *tail;
} Graph;

Graph* createGraph() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->head = NULL;
    g->tail = NULL;
    return g;
}

void addNode(Graph* g, char data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    if (g->head == NULL) {
        g->head = n;
        g->tail = n;
    } else {
        g->tail->next = n;
        g->tail = n;
    }
}

void printGraph(Graph* g) {
    if (g->head == NULL) {
        printf("Graph is empty.\n");
        return;
    }
    printf("Graph:\n");
    Node* curr = g->head;
    while (curr!= NULL) {
        printf("%c -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    Graph* g = createGraph();
    addNode(g, 'A');
    addNode(g, 'B');
    addNode(g, 'C');
    addNode(g, 'D');
    addNode(g, 'E');
    printGraph(g);
    return 0;
}