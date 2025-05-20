//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    int i, j, color, max_color = -1;

    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            if (colors[graph[i][j]] != -1)
            {
                colors[i] = -1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        color = 0;
        while (colors[graph[i][color]] != -1)
        {
            color++;
        }
        colors[i] = color;
    }

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }

    free(colors);
}

int main()
{
    int n, k;
    int **graph;

    printf("Enter the number of vertices:");
    scanf("%d", &n);

    printf("Enter the number of colors:");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the adjacency list:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d ", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    return 0;
}