//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
    int vertex;
    int color;
} GraphVertex;

typedef struct {
    int numVertices;
    int numColors;
    GraphVertex *vertices;
} Graph;

void createGraph(Graph *graph) {
    int i;
    srand(time(NULL));

    graph->numVertices = rand() % MAX_VERTICES + 1;
    graph->numColors = rand() % MAX_COLORS + 1;

    graph->vertices = (GraphVertex *) malloc(graph->numVertices * sizeof(GraphVertex));

    for (i = 0; i < graph->numVertices; i++) {
        graph->vertices[i].vertex = i;
        graph->vertices[i].color = rand() % graph->numColors;
    }
}

int isValidColor(Graph *graph, int vertex, int color) {
    int i;

    for (i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i].vertex == vertex) {
            return graph->vertices[i].color!= color;
        }
    }

    return 0;
}

void colorGraph(Graph *graph) {
    int i, j;
    int colors[MAX_COLORS];

    for (i = 0; i < graph->numColors; i++) {
        colors[i] = 0;
    }

    for (i = 0; i < graph->numVertices; i++) {
        while (1) {
            int color = rand() % graph->numColors;

            if (isValidColor(graph, i, color)) {
                colors[color]++;
                break;
            }
        }
    }

    for (i = 0; i < graph->numColors; i++) {
        printf("Color %d used %d times\n", i, colors[i]);
    }
}

int main() {
    Graph graph;

    createGraph(&graph);
    colorGraph(&graph);

    return 0;
}