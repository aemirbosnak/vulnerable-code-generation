//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int k) {
  int *colors = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    colors[i] = -1;
  }

  for (int i = 0; i < k; i++) {
    int color = graph[i][0];
    int neighbor = graph[i][1];

    if (colors[neighbor] != -1) {
      while (colors[neighbor] == color) {
        color++;
      }
    }

    colors[neighbor] = color;
  }

  for (int i = 0; i < n; i++) {
    printf("Vertex %d colored with %d\n", i, colors[i]);
  }
}

int main() {
  int n = 5;
  int k = 3;

  int **graph = malloc(k * sizeof(int *));
  for (int i = 0; i < k; i++) {
    graph[i] = malloc(2 * sizeof(int));
  }

  graph[0][0] = 1;
  graph[0][1] = 2;
  graph[1][0] = 2;
  graph[1][1] = 3;
  graph[2][0] = 3;
  graph[2][1] = 1;
  graph[3][0] = 1;
  graph[3][1] = 2;
  graph[4][0] = 2;
  graph[4][1] = 3;

  graph_coloring(graph, n, k);

  return 0;
}