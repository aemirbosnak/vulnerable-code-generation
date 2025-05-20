//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    int i, j, color = 1, conflict = 0;

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
                conflict = 1;
            }
        }
    }

    if (!conflict)
    {
        for (i = 0; i < n; i++)
        {
            colors[i] = color++;
        }
    }

    free(colors);
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

    printf("Enter the adjacency list: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            scanf("%d ", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    printf("The coloring is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", graph[i][0]);
    }

    free(graph);

    return 0;
}