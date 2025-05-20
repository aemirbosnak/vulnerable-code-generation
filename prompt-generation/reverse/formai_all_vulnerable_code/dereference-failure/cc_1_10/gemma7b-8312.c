//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
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
        for (int j = 0; j < MAX; j++)
        {
            if (graph[i][j] && colors[j] == -1)
            {
                colors[i] = j;
                break;
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
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the two nodes connected by edge %d: ", &u, &v);
        graph[u][v] = 1;
    }

    int **colors = (int *)malloc(n * sizeof(int));

    graph_coloring(graph, n, colors);

    for (int i = 0; i < n; i++)
    {
        printf("The color of node %d is %d\n", i, colors[i]);
    }

    return 0;
}