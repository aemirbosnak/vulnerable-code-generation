//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 5

void graphColoring(int **graph, int **color, int v)
{
    int i, j, k;
    for (i = 0; i < v; i++)
    {
        color[i] = -1;
        for (j = 0; j < v; j++)
        {
            if (graph[i][j] && color[i] == color[j])
            {
                for (k = 0; k < v; k++)
                {
                    if (graph[i][k] && color[k] == color[j])
                        color[k] = -1;
                }
            }
        }
    }
}

int main()
{
    int v = MAX_V;
    int **graph = (int **)malloc(v * sizeof(int *));
    for (int i = 0; i < v; i++)
    {
        graph[i] = (int *)malloc(v * sizeof(int));
    }

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;

    int **color = (int *)malloc(v * sizeof(int));

    graphColoring(graph, color, v);

    for (int i = 0; i < v; i++)
    {
        printf("Node %d has color %d\n", i, color[i]);
    }

    return 0;
}