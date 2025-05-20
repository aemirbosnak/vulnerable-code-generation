//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algorithm(int **graph, int n, int m)
{
  int i, j, k, max_matching = 0, current_matching = 0, match_graph[n][m];

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      match_graph[i][j] = 0;
    }
  }

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (graph[j][i] > 0)
      {
        match_graph[j][i] = 1;
        current_matching++;
      }
    }
  }

  max_matching = current_matching;

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (match_graph[i][j] == 0)
      {
        for (k = 0; k < m; k++)
        {
          if (graph[i][k] > 0 && match_graph[k][j] == 0)
          {
            match_graph[k][j] = 1;
            current_matching++;
            break;
          }
        }
      }
    }
  }

  printf("The maximum matching is: %d\n", max_matching);
  printf("The current matching is: %d\n", current_matching);
}

int main()
{
  int n, m, i, j, graph[MAX][MAX], **graph_ptr = NULL;

  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter the number of edges: ");
  scanf("%d", &m);

  graph_ptr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
  {
    graph_ptr[i] = (int *)malloc(m * sizeof(int));
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      graph_ptr[i][j] = 0;
    }
  }

  printf("Enter the adjacency matrix: ");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      scanf("%d", &graph_ptr[i][j]);
    }
  }

  greedy_algorithm(graph_ptr, n, m);

  return 0;
}