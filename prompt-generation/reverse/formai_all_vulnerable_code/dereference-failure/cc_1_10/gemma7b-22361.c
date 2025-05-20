//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int **color)
{
    for (int i = 0; i < n; i++)
    {
        int visited = 0;
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] && color[j] != -1)
            {
                visited = 1;
            }
        }

        if (!visited)
        {
            color[i] = 0;
        }
    }
}

int main()
{
    int n, m;
    scanf("Enter number of nodes: ", &n);
    scanf("Enter number of edges: ", &m);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter u: ", &u);
        scanf("Enter v: ", &v);
        graph[u][v] = 1;
    }

    int **color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    graph_coloring(graph, n, color);

    for (int i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i, color[i]);
    }

    return 0;
}