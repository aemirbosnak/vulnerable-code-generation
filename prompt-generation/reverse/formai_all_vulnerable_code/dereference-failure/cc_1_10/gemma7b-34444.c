//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int **color, int currentColor)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && color[i] != color[j])
            {
                if (currentColor == 0)
                {
                    color[i] = 1;
                    graphColoring(graph, n, color, 1);
                    color[i] = 0;
                }
                else
                {
                    color[i] = currentColor;
                    graphColoring(graph, n, color, currentColor + 1);
                    color[i] = 0;
                }
            }
        }
    }
}

int main()
{
    int n, m;
    int **graph;
    int **color;
    int currentColor = 0;

    printf("Enter the number of nodes:");
    scanf("%d", &n);

    printf("Enter the number of edges:");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    color = (int *)malloc(n * sizeof(int));

    graphColoring(graph, n, color, currentColor);

    printf("The optimal coloring is:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", color[i]);
    }

    return 0;
}