//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int num_vertices) {
    int *colors = malloc(num_vertices * sizeof(int));
    int i, j, k, color = 0;

    for (i = 0; i < num_vertices; i++) {
        colors[i] = -1;
    }

    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < graph[i][0]; j++) {
            k = graph[i][j];
            if (colors[i] == colors[k]) {
                colors[i] = -1;
            }
        }
    }

    for (i = 0; i < num_vertices; i++) {
        if (colors[i] == -1) {
            printf("No coloring solution found.\n");
            return;
        }
    }

    printf(" Coloring solution:\n");
    for (i = 0; i < num_vertices; i++) {
        printf("Vertex %d colored with %d.\n", i, colors[i]);
    }
}

int main() {
    int num_vertices = 5;
    int **graph = malloc(num_vertices * sizeof(int *));
    graph[0] = malloc(2 * sizeof(int));
    graph[0][0] = 1;
    graph[0][1] = 2;
    graph[1] = malloc(2 * sizeof(int));
    graph[1][0] = 3;
    graph[1][1] = 4;
    graph[2] = malloc(2 * sizeof(int));
    graph[2][0] = 4;
    graph[2][1] = 5;
    graph[3] = malloc(2 * sizeof(int));
    graph[3][0] = 5;
    graph[3][1] = 2;
    graph[4] = malloc(2 * sizeof(int));
    graph[4][0] = 2;
    graph[4][1] = 3;

    graph_coloring(graph, num_vertices);

    return 0;
}