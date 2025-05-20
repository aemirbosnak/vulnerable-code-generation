//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    int i, j, color;

    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (graph[i][j] && colors[j] == -1)
            {
                color = 0;
                while (colors[color] == 0)
                {
                    color++;
                }
                colors[j] = color;
            }
        }
    }

    free(colors);
}

int main()
{
    int **graph = (int **)malloc(MAX * sizeof(int *));
    int n, k;

    n = 5;
    k = 3;

    graph[0] = (int *)malloc(k * sizeof(int));
    graph[1] = (int *)malloc(k * sizeof(int));
    graph[2] = (int *)malloc(k * sizeof(int));
    graph[3] = (int *)malloc(k * sizeof(int));
    graph[4] = (int *)malloc(k * sizeof(int));

    graph[0][0] = 1;
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][0] = 1;
    graph[2][1] = 1;
    graph[3][0] = 1;
    graph[3][2] = 1;
    graph[4][0] = 1;

    graph_coloring(graph, n, k);

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d has color %d\n", i, graph[i][0]);
    }

    free(graph);

    return 0;
}