//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Node {
    int index;
    struct Node* next;
} Node;

void createGraph(Node**, int);
void topologicalSort(Node**, int);

int main() {
    Node** graph = NULL;
    int numVertices = 0;

    createGraph(&graph, numVertices);
    topologicalSort(graph, numVertices);

    return 0;
}

void createGraph(Node** graph, int numVertices) {
    graph = (Node**)malloc(numVertices * sizeof(Node));

    for (int i = 0; i < numVertices; i++) {
        graph[i] = NULL;
    }
}

void topologicalSort(Node** graph, int numVertices) {
    int inDegree[numVertices];
    int outDegree[numVertices];
    int visited[numVertices];
    int i, j, k;

    for (i = 0; i < numVertices; i++) {
        inDegree[i] = 0;
        outDegree[i] = 0;
        visited[i] = 0;
    }

    for (i = 0; i < numVertices; i++) {
        for (j = 0; graph[i] != NULL; j++) {
            outDegree[graph[i]->index]++;
            inDegree[graph[i]->index]++;
        }
    }

    for (i = 0; i < numVertices; i++) {
        if (inDegree[i] == 0) {
            visited[i] = 1;
            printf("%d ", i);
        }
    }

    printf("\n");
}