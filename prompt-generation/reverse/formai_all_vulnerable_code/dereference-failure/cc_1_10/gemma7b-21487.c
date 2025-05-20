//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
  for (int i = 0; i < n; i++)
  {
    colors[i] = -1;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      if (graph[i][j] && colors[j] == -1)
      {
        colors[i] = j;
        break;
      }
    }
  }
}

int main()
{
  int n, m;
  scanf("Enter the number of nodes: ", &n);
  scanf("Enter the number of edges: ", &m);

  int **graph = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    graph[i] = (int *)malloc(m * sizeof(int));
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("Enter the edge between nodes %d and %d: ", &graph[i][j]);
    }
  }

  int **colors = (int *)malloc(n * sizeof(int));

  graph_coloring(graph, n, colors);

  for (int i = 0; i < n; i++)
  {
    printf("Node %d has color %d\n", i, colors[i]);
  }

  return 0;
}