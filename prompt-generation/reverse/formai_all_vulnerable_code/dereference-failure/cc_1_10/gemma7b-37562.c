//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int k) {
    int **colors = (int *)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        colors[i] = (int *)malloc(k * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            colors[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i]; j++) {
            colors[i][colors[j][0]] = 1;
        }
    }

    int chromatic_number = 0;
    for (int i = 0; i < n; i++) {
        int available = 1;
        for (int j = 0; j < k; j++) {
            if (colors[i][j] == 0) {
                available = 0;
            }
        }
        if (available) {
            chromatic_number++;
        }
    }

    printf("Chromatic number: %d\n", chromatic_number);
    free(colors);
}

int main() {
    int n, k;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of colors: ", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the adjacency list: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d ", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    free(graph);

    return 0;
}