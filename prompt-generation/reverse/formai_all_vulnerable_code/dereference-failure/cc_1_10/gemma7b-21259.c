//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void graph_coloring(int **graph, int n, int k)
{
    int **colors = (int *)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        colors[i] = (int *)malloc(k * sizeof(int));
        for (int j = 0; j < k; j++)
        {
            colors[i][j] = 0;
        }
    }

    int used_colors = 0;
    for (int i = 0; i < n; i++)
    {
        int color = graph[i][0];
        colors[i][color] = 1;
        used_colors++;
    }

    if (used_colors < k)
    {
        printf("Graph coloring successful!\n");
    }
    else
    {
        printf("Graph coloring unsuccessful!\n");
    }

    free(colors);
}

int main()
{
    int n, k;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of colors: ", &k);

    int **graph = (int *)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
        for (int j = 0; j < k; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter the adjacency list: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d ", &graph[i][j]);
        }
    }

    graph_coloring(graph, n, k);

    free(graph);

    return 0;
}