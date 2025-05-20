//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void GraphColoring(int **graph, int n, int k)
{
    int *color = (int *)malloc(n * sizeof(int));
    int i, j, c = 0, flag = 0;

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (graph[i][j] && color[j] == color[i])
            {
                flag = 1;
            }
        }
    }

    if (flag)
    {
        printf("No coloring\n");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            printf("Vertex %d colored with %d\n", i, color[i]);
        }
    }

    free(color);
}

int main()
{
    int n, k;
    int **graph;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    GraphColoring(graph, n, k);

    return 0;
}