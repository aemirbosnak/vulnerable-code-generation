//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void graphColoring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[j][i] != 0)
            {
                colors[j] = graph[j][i];
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (colors[i] == -1)
        {
            count++;
        }
    }

    printf("The number of vertices colored with the same color is: %d\n", count);
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
    graph[0][2] = 3;
    graph[1][0] = 2;
    graph[1][1] = 1;
    graph[1][2] = 3;
    graph[2][0] = 3;
    graph[2][1] = 2;
    graph[2][2] = 1;
    graph[3][0] = 2;
    graph[3][1] = 1;
    graph[3][2] = 3;
    graph[4][0] = 3;
    graph[4][1] = 2;
    graph[4][2] = 1;

    graphColoring(graph, n, k);

    return 0;
}