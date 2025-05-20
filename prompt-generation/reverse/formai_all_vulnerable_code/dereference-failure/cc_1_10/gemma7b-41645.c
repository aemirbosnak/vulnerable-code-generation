//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && colors[j] != -1)
            {
                for (k = 0; k < MAX; k++)
                {
                    if (colors[j] == k && colors[i] == k)
                    {
                        colors[i] = -1;
                        break;
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }
}

int main()
{
    int **graph = NULL;
    int n, m;
    int **colors = NULL;

    printf("Enter the number of vertices:");
    scanf("%d", &n);

    printf("Enter the number of edges:");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    colors = (int *)malloc(n * sizeof(int));

    graph_coloring(graph, n, colors);

    return 0;
}