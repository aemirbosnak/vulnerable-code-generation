//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int **colors)
{
    for (int i = 0; i < n; i++)
    {
        int color = colors[i];
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] && color == colors[j])
            {
                colors[i] = -1;
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of edges: ", &m);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    int **colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the two nodes connected: ", &u, &v);
        graph[u][v] = 1;
    }

    graphColoring(graph, n, colors);

    for (int i = 0; i < n; i++)
    {
        if (colors[i] != -1)
        {
            printf("Node %d has color %d\n", i + 1, colors[i]);
        }
    }

    return 0;
}