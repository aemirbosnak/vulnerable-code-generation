//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void graph_coloring(int **graph, int n, int **color)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (graph[i][j] && color[i] != color[j])
      {
        color[j] = color[i];
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
    graph[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("Enter the two nodes: ", &u, &v);
    graph[u][v] = 1;
  }

  int **color = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    color[i] = -1;
  }

  graph_coloring(graph, n, color);

  for (int i = 0; i < n; i++)
  {
    printf("The color of node %d is %d.\n", i + 1, color[i]);
  }

  return 0;
}