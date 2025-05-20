//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void map_topology(int **graph, int n)
{
  int i, j, k, l, count = 0, min_distance = MAX, current_distance = MAX;
  char **visited = malloc(n * sizeof(char *));
  for (i = 0; i < n; i++)
  {
    visited = malloc(n * sizeof(char *));
    for (j = 0; j < n; j++)
    {
      visited[j] = 0;
    }
    for (k = 0; k < n; k++)
    {
      for (l = 0; l < n; l++)
      {
        if (graph[k][l] && visited[k] && visited[l] && k != l)
        {
          current_distance = graph[k][l];
          if (current_distance < min_distance)
          {
            min_distance = current_distance;
          }
        }
      }
      visited[k] = 1;
    }
  }
  free(visited);
  printf("The minimum distance is: %d", min_distance);
}

int main()
{
  int n, i, j, **graph;
  scanf("Enter the number of nodes: ", &n);
  graph = malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
  {
    graph[i] = malloc(n * sizeof(int));
  }
  printf("Enter the adjacency matrix: ");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d ", &graph[i][j]);
    }
  }
  map_topology(graph, n);
  free(graph);
  return 0;
}