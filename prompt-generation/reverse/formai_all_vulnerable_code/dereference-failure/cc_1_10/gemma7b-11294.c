//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **color, int current_color, int *used_colors) {
  int i, j, k;

  for (i = 0; i < n; i++) {
    for (j = 0; j < graph[i][0]; j++) {
      if (color[graph[i][j]] == current_color) {
        used_colors[current_color] = 1;
        return;
      }
    }
  }

  current_color++;
  used_colors[current_color] = 1;
  color[i] = current_color;

  graph_coloring(graph, n, color, current_color, used_colors);
}

int main() {
  int n, m, i, j, k;
  int **graph;
  int **color;
  int *used_colors;

  printf("Enter the number of nodes:");
  scanf("%d", &n);

  printf("Enter the number of edges:");
  scanf("%d", &m);

  graph = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    graph[i] = (int *)malloc(m * sizeof(int));
  }

  color = (int *)malloc(n * sizeof(int));
  used_colors = (int *)malloc(MAX * sizeof(int));

  for (i = 0; i < MAX; i++) {
    used_colors[i] = 0;
  }

  graph_coloring(graph, n, color, 1, used_colors);

  for (i = 0; i < n; i++) {
    printf("Node %d has color %d\n", i + 1, color[i]);
  }

  return 0;
}