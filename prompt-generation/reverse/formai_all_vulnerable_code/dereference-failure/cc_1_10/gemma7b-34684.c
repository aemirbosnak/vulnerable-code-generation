//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int k) {
  int *colors = (int *)malloc(n * sizeof(int));
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
  int n, k;
  scanf("Enter the number of nodes: ", &n);
  scanf("Enter the number of edges: ", &k);

  int **graph = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    graph[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < k; i++) {
    int u, v;
    scanf("Enter the two nodes connected by edge %d: ", &u, &v);
    graph[u][v] = 1;
  }

  graph_coloring(graph, n, k);

  return 0;
}