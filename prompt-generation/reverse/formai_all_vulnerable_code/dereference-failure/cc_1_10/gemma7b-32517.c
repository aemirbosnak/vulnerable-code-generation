//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int index;
    struct Node* next;
} Node;

void topoMap(int numVertices) {
    Node** graph = (Node**)malloc(numVertices * sizeof(Node*));
    for (int i = 0; i < numVertices; i++) {
        graph[i] = NULL;
    }

    // Create a graph
    graph[0] = (Node*)malloc(sizeof(Node));
    graph[0]->index = 0;
    graph[0]->next = NULL;

    graph[1] = (Node*)malloc(sizeof(Node));
    graph[1]->index = 1;
    graph[1]->next = NULL;

    graph[2] = (Node*)malloc(sizeof(Node));
    graph[2]->index = 2;
    graph[2]->next = NULL;

    graph[3] = (Node*)malloc(sizeof(Node));
    graph[3]->index = 3;
    graph[3]->next = NULL;

    // Connect the nodes
    graph[0]->next = graph[1];
    graph[1]->next = graph[2];
    graph[2]->next = graph[3];

    // Print the topological order
    int topoOrder[numVertices];
    topoOrder[0] = 0;
    topoOrder[1] = 1;
    topoOrder[2] = 2;
    topoOrder[3] = 3;

    for (int i = 0; i < numVertices; i++) {
        printf("%d ", topoOrder[i]);
    }

    printf("\n");

    // Free the memory
    for (int i = 0; i < numVertices; i++) {
        free(graph[i]);
    }
    free(graph);
}

int main() {
    topoMap(4);
    return 0;
}