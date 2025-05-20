//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 20

typedef struct Graph {
    int numVertices;
    int **adjList;
} Graph;

void graphColor(Graph *graph) {
    int i, j, k, color, graphColorCount = 0;
    int *colorArray = malloc(graph->numVertices * sizeof(int));
    for (i = 0; i < graph->numVertices; i++) {
        colorArray[i] = -1;
    }

    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->adjList[i]; j++) {
            for (k = 0; k < graph->adjList[j]; k++) {
                if (colorArray[i] == colorArray[j] && colorArray[j] == colorArray[k]) {
                    color = 0;
                    while (colorArray[k] == color) {
                        color++;
                    }
                    colorArray[i] = color;
                }
            }
        }
    }

    for (i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d has color %d\n", i, colorArray[i]);
    }

    free(colorArray);
    graphColorCount++;
    printf("Total number of colorings: %d\n", graphColorCount);
}

int main() {
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = 5;
    graph->adjList = malloc(graph->numVertices * sizeof(int));
    graph->adjList[0] = 2;
    graph->adjList[1] = 3;
    graph->adjList[2] = 4;
    graph->adjList[3] = 4;
    graph->adjList[4] = 3;

    graphColor(graph);

    return 0;
}