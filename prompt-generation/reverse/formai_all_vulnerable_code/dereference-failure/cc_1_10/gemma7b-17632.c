//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
  int graph[MAX][MAX] = {{0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                           {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                           {1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                           {0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
                           {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                           {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
  };

  int chromaticNumber = graphColoring(graph);

  printf("Chromatic number of the graph: %d\n", chromaticNumber);

  return 0;
}

int graphColoring(int **graph)
{
  int n = MAX;
  int chromaticNumber = 0;
  int color[n];

  for (int i = 0; i < n; i++)
  {
    color[i] = -1;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (graph[i][j] && color[i] != color[j])
      {
        color[j] = color[i] + 1;
      }
    }
  }

  chromaticNumber = color[n - 1] + 1;

  return chromaticNumber;
}