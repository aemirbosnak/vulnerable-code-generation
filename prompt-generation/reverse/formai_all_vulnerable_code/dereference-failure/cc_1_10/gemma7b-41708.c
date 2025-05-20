//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int k)
{
    int i, j, color, available, conflict;

    for (i = 0; i < n; i++)
    {
        available = 1;
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && graph[i][j] != -1)
            {
                color = graph[i][j];
                conflict = 0;
                for (int l = 0; l < n; l++)
                {
                    if (graph[l][j] && graph[l][j] == color)
                    {
                        conflict = 1;
                    }
                }
                if (!conflict)
                {
                    graph[i][j] = color;
                }
                else
                {
                    available = 0;
                }
            }
        }
        if (available)
        {
            graph[i][n] = color;
        }
        else
        {
            graph[i][n] = -1;
        }
    }

    return;
}

int main()
{
    int n, k;
    scanf("Enter the number of nodes:", &n);
    scanf("Enter the number of colors:", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = -1;
        }
    }

    graph_coloring(graph, n, k);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}