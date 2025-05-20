//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int **colors)
{
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] && colors[i] != colors[j])
            {
                colors[i] = colors[j];
            }
        }
    }

    return;
}

int main()
{
    int n = 5;
    int **graph = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = malloc(n * sizeof(int));
    }

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;

    int **colors = malloc(n * sizeof(int));
    graph_coloring(graph, n, colors);

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }

    return 0;
}