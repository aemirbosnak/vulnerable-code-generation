//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int k)
{
    int *color = (int *)malloc(n * sizeof(int));
    int i, j, c, flag = 0;

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (graph[i][j] && color[j] == color[i])
            {
                flag = 1;
            }
        }
    }

    if (flag)
    {
        printf("No solution\n");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            printf("Color of node %d is %d\n", i, color[i]);
        }
    }

    free(color);
}

int main()
{
    int **graph = (int **)malloc(MAX * sizeof(int *));
    int n, k, i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the adjacency matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    return 0;
}