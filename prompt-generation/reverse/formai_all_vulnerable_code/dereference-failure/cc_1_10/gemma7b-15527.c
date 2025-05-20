//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **color)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && color[i] != color[j])
            {
                for (k = 0; k < MAX; k++)
                {
                    if (color[i] != k && color[j] != k)
                    {
                        color[i] = k;
                        break;
                    }
                }
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
        scanf("Enter the source node: ", &u);
        scanf("Enter the destination node: ", &v);
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
        printf("Node %d has color %d\n", i + 1, color[i]);
    }

    return 0;
}