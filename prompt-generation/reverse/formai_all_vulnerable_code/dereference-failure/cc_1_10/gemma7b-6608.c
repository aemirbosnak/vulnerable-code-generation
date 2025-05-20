//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void graphColoring(int **graph, int n, int k)
{
    int *color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < n; l++)
            {
                if (graph[j][l] && color[j] != color[l])
                {
                    color[l] = color[j] ^ 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i, color[i]);
    }
}

int main()
{
    int n = 5;
    int k = 3;
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
    graph[2][4] = 1;
    graph[3][4] = 1;

    graphColoring(graph, n, k);

    return 0;
}