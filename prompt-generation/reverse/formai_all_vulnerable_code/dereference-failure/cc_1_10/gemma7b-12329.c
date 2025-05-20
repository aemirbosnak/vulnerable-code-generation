//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 10

typedef struct Graph {
    int **adjList;
    int numVertices;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (int**)malloc(MAX_VERTS * sizeof(int*));
    for (int i = 0; i < MAX_VERTS; i++) {
        graph->adjList[i] = NULL;
    }
    graph->numVertices = 0;
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjList[src] = (int*)realloc(graph->adjList[src], (graph->numVertices + 1) * sizeof(int));
    graph->adjList[src][graph->numVertices++] = dest;
}

int graphColoring(Graph* graph) {
    int* color = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = -1;
    }

    int chromaticNumber = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        int availableColors = 0;
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjList[i][j] && color[j] != -1) {
                availableColors++;
            }
        }

        color[i] = availableColors;
        chromaticNumber = fmax(chromaticNumber, color[i]);
    }

    free(color);
    return chromaticNumber;
}

int main() {
    Graph* graph = createGraph();
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    int chromaticNumber = graphColoring(graph);
    printf("Chromatic number: %d\n", chromaticNumber);

    return 0;
}