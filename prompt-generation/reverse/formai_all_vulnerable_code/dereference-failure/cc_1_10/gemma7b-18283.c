//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
    int i, j, k, color;

    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            k = graph[i][j];
            if (colors[i] == colors[k])
            {
                return;
            }
        }
    }

    return;
}

int main()
{
    int n, m, i, j, **graph, **colors;

    scanf("Enter the number of nodes:", &n);
    scanf("Enter the number of edges:", &m);

    graph = (int **)malloc(n * sizeof(int *));
    colors = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    for (i = 0; i < m; i++)
    {
        scanf("Enter the source node:", &graph[i][0]);
        scanf("Enter the destination node:", &graph[i][1]);
    }

    graph_coloring(graph, n, colors);

    for (i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i + 1, colors[i]);
    }

    return 0;
}