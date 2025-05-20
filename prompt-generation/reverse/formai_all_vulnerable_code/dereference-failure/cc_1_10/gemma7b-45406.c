//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int k) {
  int *colors = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    colors[i] = -1;
  }

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] == 1) {
        colors[j] = i;
      }
    }
  }

  int conflict = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && graph[i][j] == 1 && colors[i] == colors[j]) {
        conflict = 1;
      }
    }
  }

  if (conflict == 0) {
    printf("No conflict.\n");
  } else {
    printf("Conflict.\n");
  }

  free(colors);
}

int main() {
  int n, k;
  scanf("Enter the number of nodes: ", &n);
  scanf("Enter the number of colors: ", &k);

  int **graph = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    graph[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      graph[i][j] = 0;
    }
  }

  scanf("Enter the adjacency matrix: ", graph);

  graph_coloring(graph, n, k);

  return 0;
}