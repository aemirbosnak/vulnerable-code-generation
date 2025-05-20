//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRAPH_SIZE 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node** graph = NULL;

void initializeGraph() {
    graph = (Node**)malloc(GRAPH_SIZE * sizeof(Node*));
    for (int i = 0; i < GRAPH_SIZE; i++) {
        graph[i] = NULL;
    }
}

void insertNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (graph[data] == NULL) {
        graph[data] = newNode;
    } else {
        graph[data]->next = newNode;
    }
}

void traverseGraph() {
    for (int i = 0; i < GRAPH_SIZE; i++) {
        Node* current = graph[i];
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    initializeGraph();
    insertNode(10);
    insertNode(20);
    insertNode(30);
    insertNode(40);
    insertNode(50);

    traverseGraph();

    return 0;
}