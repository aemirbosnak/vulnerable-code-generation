//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors, int k)
{
  for (int i = 0; i < n; i++)
  {
    int available = 1;
    for (int j = 0; j < k; j++)
    {
      if (colors[graph[i][j]] == colors[i])
      {
        available = 0;
      }
    }

    if (available)
    {
      colors[i] = rand() % k + 1;
    }
  }
}

int main()
{
  int n, k;
  scanf("Enter the number of nodes:", &n);
  scanf("Enter the number of colors:", &k);

  int **graph = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    graph[i] = (int *)malloc(k * sizeof(int));
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < k; j++)
    {
      scanf("Enter the edge weight:", &graph[i][j]);
    }
  }

  int **colors = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    colors[i] = 0;
  }

  graph_coloring(graph, n, colors, k);

  for (int i = 0; i < n; i++)
  {
    printf("Node %d has color %d\n", i + 1, colors[i]);
  }

  free(graph);
  free(colors);

  return 0;
}