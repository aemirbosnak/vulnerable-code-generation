//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **color, int current_color)
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < current_color; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (graph[i][k] && color[k] == color[j])
                {
                    return;
                }
            }
        }

        color[i] = current_color;
    }

    current_color++;
    graph_coloring(graph, n, color, current_color);
}

int main()
{
    int n, m, i, j, k, current_color = 1;
    int **graph;
    int **color;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    color = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
        color[i] = 0;
    }

    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &j, &k);
        graph[j][k] = 1;
    }

    graph_coloring(graph, n, color, current_color);

    printf("The coloring is complete.\n");

    return 0;
}