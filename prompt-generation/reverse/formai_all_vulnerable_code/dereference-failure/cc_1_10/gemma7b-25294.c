//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
  int i, j, k, color = 0;
  for (i = 0; i < n; i++)
  {
    colors[i] = -1;
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < MAX; j++)
    {
      int flag = 0;
      for (k = 0; k < n; k++)
      {
        if (graph[i][k] && colors[k] == j)
        {
          flag = 1;
        }
      }
      if (!flag)
      {
        colors[i] = j;
      }
    }
  }
}

int main()
{
  int n, m, i, j;
  scanf("Enter the number of nodes: ", &n);
  scanf("Enter the number of edges: ", &m);

  int **graph = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
  {
    graph[i] = (int *)malloc(m * sizeof(int));
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      scanf("Enter the edge weight: ", &graph[i][j]);
    }
  }

  int **colors = (int *)malloc(n * sizeof(int));

  graph_coloring(graph, n, colors);

  for (i = 0; i < n; i++)
  {
    printf("The color of node %d is %d\n", i, colors[i]);
  }

  return 0;
}