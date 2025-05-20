//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graph_coloring(int **graph, int n, int **coloring, int current_color)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && coloring[i] != coloring[j])
            {
                if (current_color + 1 > MAX)
                {
                    return;
                }
                coloring[j] = current_color + 1;
                graph_coloring(graph, n, coloring, current_color + 1);
                coloring[j] = 0;
            }
        }
    }
    return;
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

    int **coloring = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        coloring[i] = 0;
    }

    graph_coloring(graph, n, coloring, 0);

    int max_color = 0;
    for (int i = 0; i < n; i++)
    {
        if (coloring[i] > max_color)
        {
            max_color = coloring[i];
        }
    }

    printf("The maximum number of colors used is: %d", max_color);

    return 0;
}