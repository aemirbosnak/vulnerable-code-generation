//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void graphColor(int **graph, int n, int k)
{
    int *color = (int *)malloc(n * sizeof(int));
    int i, j, currentColor = 0;

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            if (color[graph[i][j]] != -1)
            {
                currentColor = color[graph[i][j]];
            }
        }

        int availableColor = 0;

        for (j = 0; j < k; j++)
        {
            if (currentColor != j)
            {
                availableColor = 1;
            }
        }

        if (availableColor)
        {
            color[i] = currentColor;
        }
        else
        {
            printf("No solution\n");
            exit(0);
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d colored with %d\n", i + 1, color[i] + 1);
    }

    free(color);
}

int main()
{
    int n, k;
    scanf("Enter the number of vertices:", &n);
    scanf("Enter the number of colors:", &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the adjacency list (source, destination):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &graph[i][0], &graph[i][1]);
    }

    graphColor(graph, n, k);

    return 0;
}