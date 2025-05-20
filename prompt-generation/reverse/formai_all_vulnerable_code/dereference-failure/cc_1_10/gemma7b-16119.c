//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Node {
    char **graph;
    int numVertices;
    struct Node* next;
} Node;

Node* newNode(int numVertices) {
    Node* node = malloc(sizeof(Node));
    node->graph = malloc(numVertices * sizeof(char*));
    node->numVertices = numVertices;
    node->next = NULL;

    for (int i = 0; i < numVertices; i++) {
        node->graph[i] = malloc(MAX_VERTICES * sizeof(char));
    }

    return node;
}

void addEdge(Node* node, int src, int dest) {
    node->graph[src][dest] = 1;
}

void printGraph(Node* node) {
    for (int i = 0; i < node->numVertices; i++) {
        for (int j = 0; j < node->numVertices; j++) {
            if (node->graph[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    Node* graph = newNode(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    printGraph(graph);

    return 0;
}