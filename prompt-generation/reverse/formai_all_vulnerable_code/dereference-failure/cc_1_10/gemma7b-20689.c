//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int **colors)
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
    int n, m;
    scanf("Enter the number of nodes:", &n);
    scanf("Enter the number of edges:", &m);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the source node:", &u);
        scanf("Enter the destination node:", &v);
        graph[u][v] = 1;
    }

    int **colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    graphColoring(graph, n, colors);

    for (int i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i + 1, colors[i]);
    }

    return 0;
}