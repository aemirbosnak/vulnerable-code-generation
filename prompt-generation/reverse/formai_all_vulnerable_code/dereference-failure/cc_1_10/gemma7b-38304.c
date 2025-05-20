//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graphColoring(int **graph, int n, int k)
{
    int **color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (graph[i][j] == 1)
            {
                int available = 0;
                for (int l = 0; l < n; l++)
                {
                    if (color[l] == j)
                    {
                        available = 1;
                    }
                }

                if (!available)
                {
                    color[i] = j;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", color[i]);
    }

    free(color);
}

int main()
{
    int n, k;
    scanf("Enter the number of nodes:", &n);
    scanf("Enter the number of colors:", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("Enter the edge value:", &graph[i][j]);
        }
    }

    graphColoring(graph, n, k);

    free(graph);

    return 0;
}