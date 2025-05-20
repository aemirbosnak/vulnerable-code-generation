//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int **colors)
{
    for (int i = 0; i < n; i++)
    {
        int currentColor = colors[i];
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] && currentColor == colors[j])
            {
                printf("Error: Invalid coloring!\n");
                exit(1);
            }
        }
    }

    printf("Valid coloring!\n");
}

int main()
{
    int n, m;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of edges: ", &m);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the two nodes: ", &u, &v);
        graph[u][v] = 1;
    }

    int **colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = 0;
    }

    graphColoring(graph, n, colors);

    return 0;
}