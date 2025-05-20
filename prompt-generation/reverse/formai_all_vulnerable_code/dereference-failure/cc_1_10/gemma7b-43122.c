//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
    int i, j, k, color = 1;

    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && colors[i] != colors[j])
            {
                colors[i] = color++;
            }
        }
    }

    return;
}

int main()
{
    int n, m, i, j, k, **graph, **colors;

    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of edges: ", &m);

    graph = (int **)malloc(n * sizeof(int *));
    colors = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < m; i++)
    {
        scanf("Enter the source node: ", &k);
        scanf("Enter the destination node: ", &j);

        graph[k][j] = 1;
    }

    graph_coloring(graph, n, colors);

    for (i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i + 1, colors[i]);
    }

    return 0;
}