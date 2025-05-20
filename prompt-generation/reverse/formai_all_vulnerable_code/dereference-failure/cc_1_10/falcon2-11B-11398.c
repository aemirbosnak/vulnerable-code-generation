//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct _node {
    int data;
    struct _node *next;
} Node;

typedef struct _graph {
    Node *head;
    int size;
} Graph;

Graph* createGraph() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->head = NULL;
    g->size = 0;
    return g;
}

void addEdge(Graph* g, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = NULL;

    Node* temp = g->head;

    if (g->size == 0) {
        g->head = newNode;
        g->size++;
    } else {
        while (temp!= NULL && temp->data < src) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        g->size++;
    }
}

void printGraph(Graph* g) {
    Node* temp = g->head;
    while (temp!= NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Graph* g = createGraph();
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);
    addEdge(g, 4, 5);
    addEdge(g, 5, 6);
    addEdge(g, 6, 7);
    addEdge(g, 7, 8);
    addEdge(g, 8, 9);
    addEdge(g, 9, 1);

    printGraph(g);
    return 0;
}