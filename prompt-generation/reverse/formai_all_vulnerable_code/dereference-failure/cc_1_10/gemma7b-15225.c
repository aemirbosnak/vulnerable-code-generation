//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graph_coloring(int **graph, int n, int **colors)
{
    for (int i = 0; i < n; i++)
    {
        int color = -1;
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] && colors[j] != -1)
            {
                if (color == -1 || colors[j] != colors[i])
                {
                    color = colors[j];
                }
            }
        }
        colors[i] = color;
    }
}

int main()
{
    int n = 5;
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;

    int **colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    graph_coloring(graph, n, colors);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", colors[i]);
    }

    return 0;
}