//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    int i = 0;
    for (int v = 0; v < n; v++)
    {
        for (int u = 0; u < n; u++)
        {
            if (graph[v][u] && colors[v] != colors[u])
            {
                colors[v] = colors[u] ^ 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }
}

int main()
{
    int n, k;
    scanf("Enter the number of vertices: ", &n);
    scanf("Enter the number of colors: ", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("Enter the edge between vertex %d and vertex %d: ", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    return 0;
}