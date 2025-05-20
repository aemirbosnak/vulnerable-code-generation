//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void topo_mapper(int **graph, int n)
{
  int i, j, k, degree[n], visited[n], order[n];
  for (i = 0; i < n; i++)
  {
    degree[i] = 0;
    visited[i] = 0;
  }
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (graph[i][j] != 0)
      {
        degree[i]++;
      }
    }
  }
  for (i = 0; i < n; i++)
  {
    visited[i] = 1;
    for (k = 0; k < degree[i]; k++)
    {
      if (visited[graph[i][k]] == 0)
      {
        visited[graph[i][k]] = 1;
        order[graph[i][k]] = order[i] + 1;
      }
    }
  }
  for (i = 0; i < n; i++)
  {
    printf("%d ", order[i]);
  }
  printf("\n");
}

int main()
{
  int n, i, j, graph[MAX][MAX];
  scanf("Enter the number of nodes: ", &n);
  scanf("Enter the adjacency matrix: ", graph);
  topo_mapper(graph, n);
  return 0;
}