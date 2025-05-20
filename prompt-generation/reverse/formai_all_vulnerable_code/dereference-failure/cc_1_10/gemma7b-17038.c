//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int k) {
  int *colors = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    colors[i] = -1;
  }

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] != 0) {
        colors[j] = graph[i][j];
      }
    }
  }

  int conflicts = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && graph[i][j] != 0 && colors[i] == colors[j]) {
        conflicts++;
      }
    }
  }

  if (conflicts == 0) {
    printf("No conflicts.\n");
  } else {
    printf("Conflicts: %d.\n", conflicts);
  }

  free(colors);
}

int main() {
  int n = 5;
  int k = 3;
  int **graph = malloc(k * sizeof(int *));
  for (int i = 0; i < k; i++) {
    graph[i] = malloc(n * sizeof(int));
  }

  graph[0][1] = 1;
  graph[0][2] = 1;
  graph[1][2] = 1;
  graph[1][3] = 1;
  graph[2][3] = 1;
  graph[2][4] = 1;
  graph[3][4] = 1;

  graph_coloring(graph, n, k);

  free(graph);

  return 0;
}