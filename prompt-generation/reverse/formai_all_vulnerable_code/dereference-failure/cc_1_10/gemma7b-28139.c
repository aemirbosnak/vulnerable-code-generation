//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int k)
{
  int *colors = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    colors[i] = -1;

  for (int i = 0; i < k; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (graph[j][i] != -1)
      {
        colors[j] = graph[j][i];
      }
    }
  }

  int conflicts = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i != j && colors[i] == colors[j] && graph[i][j] != -1)
      {
        conflicts++;
      }
    }
  }

  if (conflicts == 0)
  {
    printf("No conflicts.\n");
  }
  else
  {
    printf("Conflicts: %d.\n", conflicts);
  }

  free(colors);
}

int main()
{
  int n = 5;
  int k = 3;
  int **graph = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
    graph[i] = (int *)malloc(k * sizeof(int));

  graph[0][1] = 1;
  graph[0][2] = 2;
  graph[1][2] = 2;
  graph[1][3] = 3;
  graph[2][3] = 3;
  graph[2][4] = 4;
  graph[3][4] = 4;

  graph_coloring(graph, n, k);

  free(graph);

  return 0;
}