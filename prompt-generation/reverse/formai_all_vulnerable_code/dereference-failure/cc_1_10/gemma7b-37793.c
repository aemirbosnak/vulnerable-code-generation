//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int graph_coloring(int **graph, int n, int m)
{
    int *colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                int color = colors[graph[i][j]] == -1 ? 0 : colors[graph[i][j]] + 1;
                colors[graph[i][j]] = color;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i, colors[i]);
    }

    free(colors);

    return 0;
}

int main()
{
    int n, m;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of edges: ", &m);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the two nodes connected by edge %d: ", &u, &v);
        graph[u][v] = 1;
    }

    graph_coloring(graph, n, m);

    return 0;
}