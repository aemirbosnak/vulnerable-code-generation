//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int **color)
{
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

    int **color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    graphColoring(graph, n, color);

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d has color %d\n", i, color[i]);
    }

    free(graph);
    free(color);

    return 0;
}