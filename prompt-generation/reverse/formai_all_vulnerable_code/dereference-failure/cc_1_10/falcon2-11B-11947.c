//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
} Graph;

void insertNode(Graph* g, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (g->head == NULL) {
        g->head = newNode;
    } else {
        Node* curr = g->head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void printGraph(Graph* g) {
    Node* curr = g->head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void bfs(Graph* g, int start, int end) {
    Node* q = NULL;
    Node* curr = NULL;
    Node* next = NULL;
    bool visited[MAX_NODES] = { false };

    insertNode(g, start);
    insertNode(g, end);

    curr = g->head;
    while (curr!= NULL) {
        next = curr->next;
        if (!visited[curr->data]) {
            visited[curr->data] = true;
            q = curr;
            curr = next;
        } else {
            curr = next;
        }
    }

    while (q!= NULL) {
        curr = q;
        q = q->next;
        printf("%d ", curr->data);
    }
    printf("\n");
}

int main() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->head = NULL;

    insertNode(g, 1);
    insertNode(g, 2);
    insertNode(g, 3);
    insertNode(g, 4);
    insertNode(g, 5);

    printf("Initial graph:\n");
    printGraph(g);

    bfs(g, 1, 4);

    printf("Breadth-first search:\n");
    printGraph(g);

    return 0;
}