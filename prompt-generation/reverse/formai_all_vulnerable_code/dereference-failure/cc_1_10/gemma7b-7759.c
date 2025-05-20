//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graph_coloring(int **graph, int n, int **colors)
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
    scanf("Enter the number of nodes and edges:", &n, &m);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the nodes connected:", &u, &v);
        graph[u][v] = 1;
    }

    int **colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    graph_coloring(graph, n, colors);

    for (int i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i + 1, colors[i]);
    }

    return 0;
}