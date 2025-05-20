//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6

typedef struct {
    int adjMat[MAX_VERTICES][MAX_VERTICES];
    int color[MAX_VERTICES];
    int nVertices;
} Graph;

bool isGraphColorableUtil(Graph *graph, int m, int v, int c) {
    for (int i = 0; i < graph->nVertices; i++) {
        if (graph->adjMat[v][i] && graph->color[i] == c)
            return false;
    }
    graph->color[v] = c;
    if (m > 0 && v < graph->nVertices-1) {
        if (graph->nVertices - v >= m && isGraphColorableUtil(graph, m-1, v+1, c+1))
            return true;
    }
    return true;
}

bool isGraphColorable(Graph *graph, int m) {
    if (m > (graph->nVertices + graph->nVertices/2))
        return false;
    return isGraphColorableUtil(graph, m, 0, MIN_COLOR);
}

void createGraph(Graph *graph, int vertices) {
    graph->nVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMat[i][j] = 0;
        }
    }
}

void addEdge(Graph *graph, int v1, int v2) {
    graph->adjMat[v1][v2] = 1;
    graph->adjMat[v2][v1] = 1;
}

int main() {
    Graph graph;
    int vertices, edges, m;

    scanf("%d %d %d", &vertices, &edges, &m);
    createGraph(&graph, vertices);

    for (int i = 0; i < edges; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        addEdge(&graph, v1, v2);
    }

    if (isGraphColorable(&graph, m))
        printf("Graph is colorable with %d colors\n", m);
    else
        printf("Graph is not colorable with %d colors\n", m);

    return 0;
}