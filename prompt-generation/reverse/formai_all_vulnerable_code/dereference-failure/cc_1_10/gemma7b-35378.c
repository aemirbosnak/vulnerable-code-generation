//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void solveCase(int n, int **graph, int **color)
{
  for (int i = 0; i < n; i++)
  {
    int neighbors = graph[i][0];
    for (int j = 0; j < neighbors; j++)
    {
      if (color[graph[i][j]] == color[i])
      {
        printf("Case Closed: Conflict detected!\n");
        return;
      }
    }
  }

  printf("Case Closed: No conflicts found.\n");
}

int main()
{
  int n, m, i, j;
  scanf("Enter the number of cases: ", &n);

  for (i = 0; i < n; i++)
  {
    scanf("Enter the number of nodes: ", &m);
    int **graph = (int **)malloc(m * sizeof(int *));
    for (j = 0; j < m; j++)
    {
      graph[j] = (int *)malloc(2 * sizeof(int));
    }

    scanf("Enter the adjacency list: ");
    for (j = 0; j < m; j++)
    {
      scanf("%d ", &graph[j][0]);
      scanf("%d ", &graph[j][1]);
    }

    int **color = (int *)malloc(m * sizeof(int));
    for (j = 0; j < m; j++)
    {
      color[j] = -1;
    }

    solveCase(m, graph, color);

    free(graph);
    free(color);
  }

  return 0;
}