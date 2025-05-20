//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void graph_coloring(int **graph, int n, int k)
{
  int *colors = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    colors[i] = -1;
  }

  for (int i = 0; i < k; i++)
  {
    int current_color = graph[i][0];
    for (int j = 1; j < n; j++)
    {
      if (colors[j] == current_color)
      {
        colors[j] = -1;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    printf("%d ", colors[i]);
  }
  printf("\n");
  free(colors);
}

int main()
{
  int n = 5;
  int k = 3;
  int **graph = (int **)malloc(k * sizeof(int *));
  for (int i = 0; i < k; i++)
  {
    graph[i] = (int *)malloc(n * sizeof(int));
  }

  graph[0][0] = 1;
  graph[0][1] = 2;
  graph[0][2] = 3;
  graph[1][0] = 2;
  graph[1][1] = 3;
  graph[2][0] = 3;
  graph[2][1] = 1;
  graph[2][2] = 2;
  graph[3][0] = 1;
  graph[3][1] = 2;
  graph[3][2] = 3;
  graph[4][0] = 2;
  graph[4][1] = 3;
  graph[4][2] = 1;

  graph_coloring(graph, n, k);

  free(graph);

  return 0;
}