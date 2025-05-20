//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != -1)
            {
                colors[j] = graph[i][j];
            }
        }
    }

    int conflict = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && colors[i] == colors[j] && graph[i][j] != -1)
            {
                conflict = 1;
            }
        }
    }

    if (!conflict)
    {
        printf("No conflict.\n");
    }
    else
    {
        printf("Conflict.\n");
    }

    free(colors);
}

int main()
{
    int n, k;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of edges: ", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = -1;
        }
    }

    for (int i = 0; i < k; i++)
    {
        int u, v, color;
        scanf("Enter the source node: ", &u);
        scanf("Enter the destination node: ", &v);
        scanf("Enter the color: ", &color);
        graph[u][v] = color;
    }

    graph_coloring(graph, n, k);

    return 0;
}