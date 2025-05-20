//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Node {
    int index;
    struct Node* next;
} Node;

void createNetwork(Node** graph) {
    *graph = (Node*)malloc(sizeof(Node) * MAX_VERTICES);
    for (int i = 0; i < MAX_VERTICES; i++) {
        (*graph)[i].index = -1;
        (*graph)[i].next = NULL;
    }
}

void addEdge(Node* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = dest;
    newNode->next = NULL;

    graph[src].next = newNode;
}

void printNetwork(Node* graph) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        Node* current = graph[i].next;
        printf("Vertex %d: ", i);
        while (current) {
            printf("-> Vertex %d ", current->index);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Node* graph;
    createNetwork(&graph);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    printNetwork(graph);

    return 0;
}