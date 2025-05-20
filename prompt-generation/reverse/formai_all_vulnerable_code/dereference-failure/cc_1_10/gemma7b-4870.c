//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int k)
{
  int *colors = (int *)malloc(n * sizeof(int));
  int i, j, color, conflict = 0;

  for (i = 0; i < n; i++)
  {
    colors[i] = -1;
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < graph[i][0]; j++)
    {
      color = graph[i][j + 1];

      if (colors[color] == colors[i])
      {
        conflict = 1;
      }

      colors[i] = color;
    }
  }

  if (conflict)
  {
    printf("No solution found.\n");
  }
  else
  {
    printf("Solution:\n");
    for (i = 0; i < n; i++)
    {
      printf("Vertex %d colored with %d\n", i + 1, colors[i]);
    }
  }

  free(colors);
}

int main()
{
  int n, k;

  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  printf("Enter the number of colors: ");
  scanf("%d", &k);

  int **graph = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    graph[i] = (int *)malloc(k * sizeof(int));
  }

  printf("Enter the graph adjacency list: ");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < k; j++)
    {
      scanf("%d ", &graph[i][j]);
    }
  }

  graphColoring(graph, n, k);

  return 0;
}