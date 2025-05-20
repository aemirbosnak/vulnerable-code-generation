//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void shock(int **graph, int n, int k)
{
    int i, j, color, min_color = MAX, current_color = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && i != j)
            {
                color = graph[i][j] - 1;
                if (color < min_color)
                {
                    min_color = color;
                    current_color = color;
                }
            }
        }
    }

    if (min_color == MAX)
    {
        printf("No solution\n");
    }
    else
    {
        printf("The minimum color is: %d\n", min_color);
        printf("The current color is: %d\n", current_color);
    }
}

int main()
{
    int n, k;
    int **graph;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    shock(graph, n, k);

    return 0;
}