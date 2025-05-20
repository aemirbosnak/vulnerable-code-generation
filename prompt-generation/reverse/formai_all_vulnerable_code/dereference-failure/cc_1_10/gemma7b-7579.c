//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
  int n, i, j, k, l, m, **graph, **visited, **distance;

  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  graph = (int **)malloc(n * sizeof(int *));
  visited = (int *)malloc(n * sizeof(int));
  distance = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
  {
    graph[i] = (int *)malloc(n * sizeof(int));
    visited[i] = 0;
    distance[i] = -1;
  }

  printf("Enter the adjacency list: ");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d ", &graph[i][j]);
    }
  }

  distance[0] = 0;

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (distance[i] + graph[i][j] < distance[j])
      {
        distance[j] = distance[i] + graph[i][j];
      }
    }
  }

  printf("The shortest path distances are: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", distance[i]);
  }

  free(graph);
  free(visited);
  free(distance);

  return 0;
}