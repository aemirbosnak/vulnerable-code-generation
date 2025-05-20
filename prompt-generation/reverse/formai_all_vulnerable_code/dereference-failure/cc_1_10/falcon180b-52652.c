//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int numVertices;
int **graph;
int *color;

void initGraph(void) {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    graph = (int **)malloc(numVertices * sizeof(int *));
    for (i = 0; i < numVertices; i++) {
        graph[i] = (int *)malloc(numVertices * sizeof(int));
        for (j = 0; j < numVertices; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = 1;
            }
        }
    }

    color = (int *)malloc(numVertices * sizeof(int));
    for (i = 0; i < numVertices; i++) {
        color[i] = -1;
    }
}

void printGraph(void) {
    int i, j;

    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void colorGraph(int v) {
    int i, j;

    if (color[v] == -1) {
        color[v] = 0;
    }

    for (i = 0; i < numVertices; i++) {
        if (graph[v][i] == 1 && color[i] == -1) {
            color[i] = (color[v] + 1) % MAX_COLORS;
            colorGraph(i);
        }
    }
}

int main(void) {
    int i, j;

    srand(time(NULL));

    initGraph();

    for (i = 0; i < numVertices; i++) {
        color[i] = -1;
    }

    colorGraph(0);

    printf("Vertex\tColor\n");
    for (i = 0; i < numVertices; i++) {
        printf("%d\t%d\n", i, color[i]);
    }

    return 0;
}