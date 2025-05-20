//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void graphColoring(int **graph, int n, int **colors, int *usedColors) {
  for (int i = 0; i < n; i++) {
    int currentColor = graph[i][0];
    int neighbors = graph[i][1];
    usedColors[currentColor] = 1;
    for (int j = 0; j < neighbors; j++) {
      int neighborColor = graph[i][j + 2];
      if (usedColors[neighborColor] == 1) {
        while (1) {
          currentColor++;
          if (!usedColors[currentColor]) {
            break;
          }
        }
      }
    }
    colors[i] = currentColor;
  }
}

int main() {
  int n, m, i, j;

  scanf("Enter the number of nodes: ", &n);
  scanf("Enter the number of edges: ", &m);

  int **graph = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    graph[i] = (int *)malloc(m * sizeof(int));
  }

  for (i = 0; i < m; i++) {
    scanf("Enter the source node: ", &graph[i][0]);
    scanf("Enter the destination node: ", &graph[i][1]);
  }

  int **colors = (int *)malloc(n * sizeof(int));
  int *usedColors = (int *)malloc(MAX * sizeof(int));

  graphColoring(graph, n, colors, usedColors);

  for (i = 0; i < n; i++) {
    printf("The color of node %d is %d\n", i + 1, colors[i]);
  }

  return 0;
}