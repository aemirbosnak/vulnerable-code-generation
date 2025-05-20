//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void graph_coloring(int **graph, int n, int **colors)
{
  for (int i = 0; i < n; i++)
  {
    colors[i] = -1;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (graph[i][j] && colors[i] != colors[j])
      {
        colors[i] = colors[j];
      }
    }
  }

  return;
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  int **graph = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    graph[i] = (int *)malloc(m * sizeof(int));
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%d", &graph[i][j]);
    }
  }

  int **colors = (int *)malloc(n * sizeof(int));

  graph_coloring(graph, n, colors);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", colors[i]);
  }

  printf("\n");

  return 0;
}