//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node* head;
};

void addNode(struct Graph* graph, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = graph->head;
    graph->head = newNode;
    graph->V++;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newEdge = (struct Node*) malloc(sizeof(struct Node));
    newEdge->data = 0;
    newEdge->next = graph->head;
    graph->head = newEdge;
    addNode(graph, src);
    addNode(graph, dest);
}

void printGraph(struct Graph* graph) {
    struct Node* current = graph->head;
    printf("Nodes in the graph: ");
    for (int i = 0; i < graph->V; i++) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    printf("Edges in the graph: ");
    current = graph->head;
    while (current!= NULL) {
        printf("%d -> %d ", current->data, current->next->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = 5;
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    printGraph(graph);
    return 0;
}