//FormAI DATASET v1.0 Category: Graph representation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

struct Graph {
    int numVertices;
    int** adjMatrix;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjMatrix = malloc(vertices * sizeof(int*));

    for(int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = calloc(vertices, sizeof(int));
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void printGraph(struct Graph* graph) {
    for(int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);

        for(int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }

        printf("\n");
    }
}

int main() {
    struct Graph* graph = createGraph(MAX_VERTICES);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 6);
    addEdge(graph, 7, 8);
    addEdge(graph, 8, 9);

    printGraph(graph);

    return 0;
}