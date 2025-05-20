//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    int i, j, color = 0, conflict = 0;

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
    int n, k;

    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of colors: ", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    graph_coloring(graph, n, k);

    printf("The coloring is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i + 1, graph[i][0]);
    }

    free(graph);

    return 0;
}