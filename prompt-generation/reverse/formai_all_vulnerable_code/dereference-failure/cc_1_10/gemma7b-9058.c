//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void graphColoring(int **graph, int n, int k)
{
    int **color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < graph[i][0]; j++)
        {
            if (color[graph[i][j]] != -1)
            {
                color[i] = -1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (color[i] != -1)
        {
            count++;
        }
    }

    printf("The number of colors used is: %d", count);
}

int main()
{
    int n, k;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of colors: ", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the adjacency list: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", graph[i][0]);
        for (int j = 0; j < graph[i][0]; j++)
        {
            scanf("%d ", graph[i][j + 1]);
        }
    }

    graphColoring(graph, n, k);

    return 0;
}