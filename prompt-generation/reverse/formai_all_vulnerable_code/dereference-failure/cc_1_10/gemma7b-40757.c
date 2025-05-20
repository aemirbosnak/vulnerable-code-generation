//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k) {
    int *colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        colors[i] = -1;
    }

    int i = 0;
    for (int v = 0; v < n; v++) {
        for (int u = 0; u < n; u++) {
            if (graph[v][u] && colors[v] != colors[u]) {
                i++;
            }
        }
    }

    if (i == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(colors);
}

int main() {
    int n, k;
    scanf("Enter the number of nodes:", &n);
    scanf("Enter the number of colors:", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("Enter the edge value:", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    return 0;
}