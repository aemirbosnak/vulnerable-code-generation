//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graph_coloring(int **graph, int n, int **colors)
{
    int i, j, k, color, flag = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && colors[i] == colors[j])
            {
                flag = 1;
            }
        }
    }

    if (flag)
    {
        printf("No solution found.\n");
    }
    else
    {
        printf("Solution found.\n");
    }
}

int main()
{
    int n, m, i, j, **graph, **colors;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    colors = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        colors[i] = 0;
    }

    for (i = 0; i < m; i++)
    {
        scanf("Enter the edge (%d, %d): ", &i, &j);
        graph[i][j] = 1;
    }

    graph_coloring(graph, n, colors);

    return 0;
}