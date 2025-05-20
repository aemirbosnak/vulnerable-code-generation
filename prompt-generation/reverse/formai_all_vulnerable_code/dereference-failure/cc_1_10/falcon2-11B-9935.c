//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} Graph;

void createGraph(Graph *g) {
    Node *node = malloc(sizeof(Node));
    g->head = node;
    node->next = NULL;
    g->size = 1;
}

void addNode(Graph *g, int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (g->head == NULL) {
        g->head = newNode;
    } else {
        Node *temp = g->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    g->size++;
}

void displayGraph(Graph *g) {
    Node *temp = g->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Graph g;
    createGraph(&g);
    addNode(&g, 1);
    addNode(&g, 2);
    addNode(&g, 3);
    addNode(&g, 4);
    addNode(&g, 5);
    displayGraph(&g);
    return 0;
}