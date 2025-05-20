//FormAI DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

struct Graph {
    int V;
    int **adjMatrix;
};

void addEdge(struct Graph *graph, int start, int end, int weight) {
    graph->adjMatrix[start][end] = weight;
    graph->adjMatrix[end][start] = weight;
}

struct Graph *createGraph(int numVertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = numVertices;

    graph->adjMatrix = (int **)malloc(numVertices * sizeof(int *));
    for(int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(numVertices * sizeof(int));
        for(int j = 0; j < numVertices; j++)
            graph->adjMatrix[i][j] = 0;
    }

    return graph;
}

void printGraph(struct Graph *graph) {
    printf("\nAdjacency Matrix representation of the Graph:\n");
    for(int i = 0; i < graph->V; i++) {
        for(int j = 0; j < graph->V; j++)
            printf("%d ", graph->adjMatrix[i][j]);
        printf("\n");
    }
}

int main() {
    struct Graph *graph = createGraph(5);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 20);
    addEdge(graph, 1, 2, 30);
    addEdge(graph, 1, 3, 40);
    addEdge(graph, 1, 4, 50);
    addEdge(graph, 2, 3, 60);
    addEdge(graph, 3, 4, 70);

    printGraph(graph);

    return 0;
}