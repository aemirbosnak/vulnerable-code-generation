//FormAI DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define VERTICES 6

struct Graph {
    int v;
    int **adjMat;
};

struct Graph *createGraph(int v) {
    struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->v = v;
    graph->adjMat = (int**) malloc(sizeof(int*) * v);
    for(int i=0; i<v; i++) {
        graph->adjMat[i] = (int*) malloc(sizeof(int) * v);
        for(int j=0; j<v; j++)
            graph->adjMat[i][j] = 0;
    }
    return graph;
}

void addEdge(struct Graph *graph, int v1, int v2) {
    graph->adjMat[v1][v2] = 1;
    graph->adjMat[v2][v1] = 1;
}

void displayGraph(struct Graph *graph) {
    printf("   ");
    for(int i=0; i<graph->v; i++) printf("%d ", i);
    printf("\n");
    for(int i=0; i<graph->v; i++) {
        printf("%d: ", i);
        for(int j=0; j<graph->v; j++)
            printf("%d ", graph->adjMat[i][j]);
        printf("\n");
    }
}

int main() {
    struct Graph *graph = createGraph(VERTICES);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);
    addEdge(graph, 2, 4);
    addEdge(graph, 4, 5);
    displayGraph(graph);
    return 0;
}