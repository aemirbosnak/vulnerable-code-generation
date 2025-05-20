//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k)
{
    int *color = (int *)malloc(n * sizeof(int));
    int i, j, v, color_used = 0;

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i]; j++)
        {
            if (color[i] == color[j])
            {
                color_used = 1;
            }
        }
    }

    if (!color_used)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d ", color[i]);
        }
        printf("\n");
    }
    else
    {
        printf("No solution found.\n");
    }

    free(color);
}

int main()
{
    int n, k;
    int **graph;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the adjacency list: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    return 0;
}