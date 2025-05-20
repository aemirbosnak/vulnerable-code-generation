//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    int current_color = 0;
    for (int i = 0; i < n; i++)
    {
        int neighbors = graph[i][0];
        for (int j = 0; j < neighbors; j++)
        {
            if (colors[graph[i][j]] == current_color)
            {
                current_color++;
            }
        }

        colors[i] = current_color;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d colored with color %d\n", i + 1, colors[i]);
    }
}

int main()
{
    int n = 5;
    int k = 3;
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    graph[0][0] = 1;
    graph[0][1] = 2;
    graph[1][0] = 2;
    graph[1][1] = 3;
    graph[2][0] = 3;
    graph[2][1] = 1;
    graph[3][0] = 1;
    graph[3][1] = 2;
    graph[4][0] = 2;
    graph[4][1] = 3;

    graph_coloring(graph, n, k);

    return 0;
}