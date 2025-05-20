//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int graph[MAX][MAX] = {{0, 1, 1, 0, 0, 0, 0, 1, 0, 0},
                              {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                              {1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
                              {1, 0, 0, 0, 0, 0, 1, 0, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                              {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
                           };

    int chromaticNumber = graphColoring(graph);

    printf("The chromatic number of the graph is: %d\n", chromaticNumber);

    return 0;
}

int graphColoring(int **graph)
{
    int n = MAX;
    int chromaticNumber = 0;
    int **visited = (int *)malloc(n * sizeof(int *));
    int *color = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        color[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] && visited[j] == 0)
            {
                visited[j] = 1;
                color[i] = color[j] ^ 1;
            }
        }
    }

    chromaticNumber = color[n - 1] + 1;

    return chromaticNumber;
}