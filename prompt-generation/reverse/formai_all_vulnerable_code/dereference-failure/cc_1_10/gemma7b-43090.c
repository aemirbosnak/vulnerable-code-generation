//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
    int i, j, k, color, available;

    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][MAX]; j++)
        {
            available = 1;

            for (k = 0; k < n; k++)
            {
                if (colors[k] == graph[i][j] && k != i)
                {
                    available = 0;
                }
            }

            if (available)
            {
                colors[i] = graph[i][j];
            }
        }
    }

    return;
}

int main()
{
    int n, m, i, j, graph[MAX][MAX], colors[MAX];

    scanf("Enter the number of nodes:", &n);
    scanf("Enter the number of edges:", &m);

    graph_coloring(graph, n, colors);

    for (i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i + 1, colors[i]);
    }

    return 0;
}