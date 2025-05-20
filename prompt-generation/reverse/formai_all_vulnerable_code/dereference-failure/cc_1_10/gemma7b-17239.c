//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int k)
{
  int **visited = (int *)malloc(n * sizeof(int));
  int *color = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    visited[i] = 0;
    color[i] = -1;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < k; j++)
    {
      if (visited[j] && color[j] == color[i])
      {
        return;
      }
    }

    int available = -1;
    for (int j = 0; j < k; j++)
    {
      if (visited[j] == 0)
      {
        available = j;
      }
    }

    color[i] = available;
    visited[available] = 1;
  }

  for (int i = 0; i < n; i++)
  {
    printf("Vertex %d colored with color %d\n", i, color[i]);
  }
}

int main()
{
  int n = 5;
  int k = 3;
  int **graph = (int **)malloc(n * sizeof(int *));

  for (int i = 0; i < n; i++)
  {
    graph[i] = (int *)malloc(k * sizeof(int));
  }

  graph[0][1] = 1;
  graph[0][2] = 1;
  graph[1][2] = 1;
  graph[2][3] = 1;
  graph[3][4] = 1;

  graph_coloring(graph, n, k);

  return 0;
}