//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 10
#define MAX_NODES 20

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct graph {
    Node *head;
} Graph;

Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph *graph, int from, int to) {
    Node *newNode = createNode(to);
    Node *current = graph->head;

    while (current!= NULL) {
        if (current->data == from) {
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Edge %d -> %d not added.\n", from, to);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printGraph(Graph *graph) {
    Node *current = graph->head;

    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Graph *romeo = (Graph*)malloc(sizeof(Graph));
    Graph *juliet = (Graph*)malloc(sizeof(Graph));

    addEdge(romeo, 1, 2);
    addEdge(romeo, 1, 3);
    addEdge(juliet, 4, 5);
    addEdge(juliet, 4, 6);
    addEdge(juliet, 5, 7);
    addEdge(juliet, 6, 7);

    printGraph(romeo);
    printf("\n");
    printGraph(juliet);

    return 0;
}