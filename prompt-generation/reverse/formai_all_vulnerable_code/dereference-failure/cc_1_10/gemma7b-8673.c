//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (int i = 0; i < k; i++)
    {
        int color = graph[i][0];
        for (int j = 1; j < n; j++)
        {
            if (graph[i][j] && colors[j] == color)
            {
                colors[j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (colors[i] == -1)
        {
            printf("No solution\n");
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d colored with %d\n", i, colors[i]);
    }
}

int main()
{
    int n, k;
    scanf("Enter the number of vertices: ", &n);
    scanf("Enter the number of edges: ", &k);

    int **graph = (int **)malloc(k * sizeof(int *));
    for (int i = 0; i < k; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("Enter the edge weight: ", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    return 0;
}