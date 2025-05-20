//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
  for (int i = 0; i < n; i++)
  {
    int available = 1;
    for (int j = 0; j < n; j++)
    {
      if (graph[i][j] && colors[j] == colors[i])
      {
        available = 0;
      }
    }
    if (available)
    {
      colors[i] = 1;
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
    graph[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("Enter the source node: ", &u);
    scanf("Enter the destination node: ", &v);
    graph[u][v] = 1;
  }

  int **colors = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    colors[i] = 0;
  }

  graph_coloring(graph, n, colors);

  for (int i = 0; i < n; i++)
  {
    printf("Node %d has color %d\n", i + 1, colors[i]);
  }

  return 0;
}