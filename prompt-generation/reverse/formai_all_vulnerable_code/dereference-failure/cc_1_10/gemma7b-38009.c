//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Node {
    int index;
    struct Node* next;
} Node;

void createGraph(Node** graph, int numVertices) {
    *graph = (Node*)malloc(sizeof(Node) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        (*graph)[i].index = i;
        (*graph)[i].next = NULL;
    }
}

void addEdge(Node* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = dest;
    newNode->next = NULL;

    graph[src].next = newNode;
}

void printGraph(Node* graph) {
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
    Node** graph;
    createGraph(&graph, MAX_VERTICES);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}