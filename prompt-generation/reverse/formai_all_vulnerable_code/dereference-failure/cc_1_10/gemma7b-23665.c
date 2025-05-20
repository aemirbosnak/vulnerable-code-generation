//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] && colors[i] != colors[j])
            {
                colors[j] = colors[i] + 1;
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
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the two nodes: ", &u, &v);
        graph[u][v] = 1;
    }

    int **colors = (int *)malloc(n * sizeof(int));

    graph_coloring(graph, n, colors);

    for (int i = 0; i < n; i++)
    {
        printf("The color of node %d is %d.\n", i + 1, colors[i] + 1);
    }

    return 0;
}