//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Node {
    int index;
    struct Node* next;
} Node;

void topoMap(int** graph, int nVertices, int nEdges) {
    Node** adjacencyList = (Node**)malloc(nVertices * sizeof(Node*));
    for (int i = 0; i < nVertices; i++) {
        adjacencyList[i] = NULL;
    }

    for (int i = 0; i < nEdges; i++) {
        int u = graph[i][0];
        int v = graph[i][1];

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->index = v;
        newNode->next = adjacencyList[u];
        adjacencyList[u] = newNode;
    }

    for (int i = 0; i < nVertices; i++) {
        printf("Vertex %d: ", adjacencyList[i]->index);
        Node* current = adjacencyList[i];
        while (current) {
            printf("%d ", current->index);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int** graph = (int**)malloc(MAX_EDGES * sizeof(int*));
    for (int i = 0; i < MAX_EDGES; i++) {
        graph[i] = (int*)malloc(2 * sizeof(int));
    }

    graph[0][0] = 1;
    graph[0][1] = 2;
    graph[1][0] = 2;
    graph[1][1] = 3;
    graph[2][0] = 3;
    graph[2][1] = 4;
    graph[3][0] = 4;
    graph[3][1] = 5;

    topoMap(graph, MAX_VERTICES, MAX_EDGES);

    return 0;
}