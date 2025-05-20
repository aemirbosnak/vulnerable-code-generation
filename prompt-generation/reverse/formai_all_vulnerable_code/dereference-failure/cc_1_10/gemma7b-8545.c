//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Node {
    int index;
    struct Node* next;
} Node;

void traverse(Node* node) {
    printf("Vertex %d: ", node->index);
    Node* current = node->next;
    while (current) {
        printf("-> ");
        printf("Vertex %d", current->index);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node** graph = (Node**)malloc(MAX_VERTICES * sizeof(Node*));
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph[i] = NULL;
    }

    // Build the graph
    graph[0] = (Node*)malloc(sizeof(Node));
    graph[0]->index = 0;
    graph[0]->next = graph[1];

    graph[1] = (Node*)malloc(sizeof(Node));
    graph[1]->index = 1;
    graph[1]->next = graph[2];

    graph[2] = (Node*)malloc(sizeof(Node));
    graph[2]->index = 2;
    graph[2]->next = graph[3];

    graph[3] = (Node*)malloc(sizeof(Node));
    graph[3]->index = 3;
    graph[3]->next = NULL;

    traverse(graph[0]);
    traverse(graph[1]);
    traverse(graph[2]);
    traverse(graph[3]);

    free(graph);

    return 0;
}