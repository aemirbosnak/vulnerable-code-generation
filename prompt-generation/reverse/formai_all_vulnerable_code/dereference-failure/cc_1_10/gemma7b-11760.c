//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    int i, j, color = 1, available = k;

    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            if (colors[graph[i][j]] == colors[i])
            {
                available = 0;
            }
        }
        if (available)
        {
            colors[i] = color++;
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }

    free(colors);
}

int main()
{
    int n, k, i, j;
    int **graph;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the adjacency list: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    return 0;
}